#ifndef INCLUDED_VECTOR_EXTENTION
#define INCLUDED_VECTOR_EXTENTION
#include<vector>
#include<miko/member_ext/ranges/range_ext.hpp>
namespace miko{
const struct shink_to_fit_t{
	typedef void result_type;

	template<class _Tp,class Allocator=std::allocator<_Tp> >
	void operator()(std::vector<_Tp,Allocator>& v)const
	{
		std::vector<_Tp,Allocator>(v).swap(v);
	}
}shrink_to_fit={};
}
#endif
