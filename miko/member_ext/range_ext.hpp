#ifndef INCLUDED_RANGE_EXTENTION
#define INCLUDED_RANGE_EXTENTION
#include<boost/utility/result_of.hpp>
#include<boost/type_traits.hpp>
#include<miko/type_traits/argument_of.hpp>
#include<iterator>
#define ITRAITS(_Tp) std::iterator_traits<_Tp>
namespace miko{ namespace detail{

template<class Signature>
struct copy_argument{
        typedef
                typename boost::remove_reference<
                                typename boost::remove_cv<
                                        typename miko::argument_of<Signature>::type
                                 >::type
                         >::type
                 type;
};

template<class Range,class Function>
typename boost::result_of<Function(Range&)>::type
operator |(Range& src,Function f)
{
	return f(src);
}
template<class Range,class Function>
typename boost::result_of<Function(Range&)>::type
operator |(const Range& src,Function f)
{
	return f(src);
}

template<class Iterator>
struct iterator_range{
        typedef Iterator iterator;
        typedef iterator const_iterator;
        typedef typename ITRAITS(iterator)::iterator_category iterator_category;
        typedef typename ITRAITS(iterator)::value_type value_type;
        typedef typename ITRAITS(iterator)::difference_type difference_type;
        typedef typename ITRAITS(iterator)::pointer pointer;
        typedef typename ITRAITS(iterator)::reference reference;

        iterator_range(iterator first,iterator last):first(first),last(last){}
        iterator begin()const{return first;}
        iterator end()const{return last;}
private:
        iterator first,last;
};

template<class Iterator>
iterator_range<Iterator> make_iterator_range(Iterator first,Iterator last)
{
        return iterator_range<Iterator>(first,last);
}

}} // namespaces

#endif
