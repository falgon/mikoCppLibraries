#ifndef INCLUDED_STRING_REPLACE
#define INLCUDED_STRING_REPLACE
#include<string>
#include<cstring>

namespace miko{
std::string& str_replace(std::string& str,const char* src,const char* rhs)
{
	if(str.empty()||!src||!*src||!rhs||!strcmp(src,rhs))
		return str;
	const size_t src_len=strlen(src);
	const size_t rhs_len=strlen(rhs);
	for(std::string::size_type i=0;
			(i=str.find(src,i,src_len))!=std::string::npos;
			i+=rhs_len)
		str.replace(i,src_len,rhs,rhs_len);
	return str;
}
}
#endif
