#ifndef INCLUDED_EMPLACE_INSERT_ITERATOR
#define INCLUDED_EMPLACE_INSERT_ITERATOR
#include<iterator>
#ifdef  __GXX_EXPERIMENTAL_CXX0X__
namespace miko{
template<class Container>
class emplace_insert_iterator:
        public std::iterator<std::output_iterator_tag,void,void,void,void>{
protected:
        Container* container;
        typename Container::iterator iter;
public:
        typedef Container container_type;

        emplace_insert_iterator(Container& x,typename Container::iterator i)
                :container(&x),iter(i)
        {}

        emplace_insert_iterator&
        operator=(typename Container::value_type& value)
        {
                iter=container->emplace(iter,value);
                ++iter;
                return *this;
        }
        emplace_insert_iterator&
        operator=(typename Container::value_type&& value)
        {
                iter=container->emplace(iter,std::move(value));
                ++iter;
                return *this;
        }

        emplace_insert_iterator&
        operator*()
        {
                return *this;
        }
        emplace_insert_iterator&
        operator++()
        {
                return *this;
        }
        emplace_insert_iterator&
        operator++(int)
        {
                return *this;
        }
};

template<class Container,class Iterator>
inline emplace_insert_iterator<Container>
emplace_inserter(Container& x,Iterator i)
{
        return emplace_insert_iterator<Container>(x,typename Container::iterator(i));
}
}

#endif
#endif
