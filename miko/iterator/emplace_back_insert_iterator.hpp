#ifndef INCLUDED_EMPLACE_BACK_INSERT_ITERATOR
#define INCLUDED_EMPLACE_BACK_INSERT_ITERATOR
#ifdef  __GXX_EXPERIMENTAL_CXX0X__
#include<iterator>
namespace miko{
template<class Container>
class emplace_back_insert_iterator:
	public std::iterator<std::output_iterator_tag,void,void,void,void>{
protected:
	Container* container;
public:
	typedef Container container_type;

	explicit emplace_back_insert_iterator(Container& x)
		:container(&x)
	{}
	emplace_back_insert_iterator&
        operator=(typename Container::value_type& value)
	{
		container->emplace_back(value);
		return *this;
	}
        emplace_back_insert_iterator&
        operator=(typename Container::value_type&& value)
        {
                container->emplace_back(std::move(value));
                return *this;
        }

	emplace_back_insert_iterator&
	operator*()
	{
		return *this;
	}
	emplace_back_insert_iterator&
	operator++()
	{
		return *this;
	}
	emplace_back_insert_iterator&
	operator++(int)
	{
		return *this;
	}
};

template<class Container>
inline miko::emplace_back_insert_iterator<Container> 
emplace_back_inserter(Container& container)
{
	return miko::emplace_back_insert_iterator<Container>(container);
}
}
#endif
#endif
