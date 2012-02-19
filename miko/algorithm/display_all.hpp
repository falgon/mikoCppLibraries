#ifndef INCLUDED_DISPLAY_ALL_HPP
#define INCLUDED_DISPLAY_ALLHPP
#include<iterator>
#include<iostream>
#include<boost/range.hpp>
namespace miko{
template<class Container>
void display_all(const Container& container,
		 const char* token="\n",
		 const char* last_token="")
{
	std::copy(boost::begin(container),boost::end(container),
			std::ostream_iterator<
				typename std::iterator_traits<
					typename Container::iterator
				>::value_type
			>(std::cout,token));
	std::cout<<last_token;
}

template<class Array,std::size_t Array_Size>
void display_all(const Array (&ar)[Array_Size],
                 const char* token="\n",
                 const char* last_token="")
{
        std::copy(ar,ar+Array_Size,
                        std::ostream_iterator<Array>(std::cout,token));
        std::cout<<last_token;
}
} // namespace miko
#endif
