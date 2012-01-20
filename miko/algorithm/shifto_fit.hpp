#include<vector>
#include<boost/tr1/functional.hpp>

const struct shink_to_fit_t{
	typedef void result_type;

	template<class T,class Allocator=std::allocator<T> >
	void operator()(std::vector<T,Allocator>& v)const
	{
		std::vector<T,Allocator>(v).swap(v);
	}
}shrink_to_fit={};

template<class T,class Allocator=std::allocator<T>,class F>
typename std::tr1::result_of<F(std::vector<T,Allocator>&)>::type
operator |(std::vector<T,Allocator>& source,F f)
{
	return f(source);
}
