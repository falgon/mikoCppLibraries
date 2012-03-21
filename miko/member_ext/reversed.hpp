#ifndef INCLUDED_REVERSE
#define INCLUDED_REVERSE
#include<iterator>
#include<miko/member_ext/range_ext.hpp>

namespace miko{ namespace detail{

template<class Iterator>
struct reversed_iterator{
        typedef std::bidirectional_iterator_tag iterator_category;
        typedef typename std::iterator_traits<Iterator>::value_type value_type;
        typedef value_type& reference;
        typedef value_type* pointer;
        typedef value_type difference_type;

        explicit reversed_iterator(Iterator it):it(it){}

        reversed_iterator& operator++()
        {
                --it;
                return *this;
        }
        reversed_iterator operator++(int)
        {
                reversed_iterator tmp=*this;
                --it;
                return tmp;
        }
        reversed_iterator& operator--()
        {
                ++it;
                return *this;
        }
        reversed_iterator operator--(int)
        {
                reversed_iterator tmp=*this;
                ++it;
                return tmp;
        }

        reference operator*()
        {
                return *prior(it);
        }

        bool operator==(reversed_iterator rhs)const
        {
                return it==rhs.it;
        }

        bool operator!=(reversed_iterator rhs)const
        {
               return it!=rhs.it;
        }
private:
        Iterator prior(Iterator x)const{return --x;}
        Iterator it;
};

template<class Iterator>
reversed_iterator<Iterator> make_reversed_iterator(Iterator it)
{
        return reversed_iterator<Iterator>(it);
}

template<class Range>
struct reversed_range{
        typedef 
           miko::detail::iterator_range<reversed_iterator<typename Range::iterator> >
                type;
};

const struct reversed_t{
        template<class Signature>
        struct result:reversed_range<typename miko::detail::copy_argument<Signature>::type>{};

        template<class Range>
        typename reversed_range<Range>::type operator()(Range& r)const
        {
                return miko::detail::make_iterator_range(
                                make_reversed_iterator(r.end()),
                                make_reversed_iterator(r.begin()));
        }
}reversed={};

} // namespace detail

using detail::reversed;

} // namespace miko

#endif
