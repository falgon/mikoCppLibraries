#ifndef INCLUDED_EMPLACE_FRONT_INSERT_ITERATOR
#define INCLUDED_EMPLACE_FRONT_INSERT_ITERATOR
#ifdef  __GXX_EXPERIMENTAL_CXX0X__
#include<iterator>
namespace miko{
template<class Container>
class emplace_front_insert_iterator:
        public std::iterator<std::output_iterator_tag,void,void,void,void>{
protected:
        Container* container;
public:
        typedef Container container_type;

        explicit emplace_front_insert_iterator(Container& x)
                :container(&x)
        {}
        
        emplace_front_insert_iterator&
        operator=(typename Container::value_type& value)
        {
                container->emplace_front(value);
                return *this;
        }

        emplace_front_insert_iterator&
        operator=(typename Container::value_type&& value)
        {
                container->emplace_front(std::move(value));
                return *this;
        }

        emplace_front_insert_iterator&
        operator*()
        {
                return *this;
        }
        emplace_front_insert_iterator&
        operator++()
        {
                return *this;
        }
        emplace_front_insert_iterator&
        operator++(int)
        {
                return *this;
        }
};

template<class Container>
inline emplace_front_insert_iterator<Container>
emplace_front_inserter(Container& x)
{
        return emplace_front_insert_iterator<Container>(x);
}
}
#endif
#endif
