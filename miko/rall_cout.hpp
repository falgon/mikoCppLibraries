#ifndef INCLUDED_RANGE_ALL_OPERATOR
#define INCLUDED_RANGE_ALL_OPERATOR
#include<iterator>
#include<iostream>
#ifndef __GXX_EXPERIMENTAL_CXX0X__
#include<boost/range.hpp>
#endif
namespace miko{
class range_all_op{
	const char* token;
	const char* last_token;
public:
        range_all_op(const char* token=" ",const char* last_token="\n")
		:token(token),last_token(last_token){}
#ifdef __GXX_EXPERIMENTAL_CXX0X__
        ~range_all_op()=default;
#else
        ~range_all_op(){}
#endif
        void set_tokenize(const char* token,const char* last_token)
        {
                this->token=token;
                this->last_token=last_token;
        }  

        template<class _Tp>
        friend void operator<<(range_all_op& cout,const _Tp& container)
        {
#ifdef __GXX_EXPERIMENTAL_CXX0X__
                using std::begin;
                using std::end;
#else
                using boost::begin;
                using boost::end;
#endif
                std::copy(begin(container),end(container),
                                std::ostream_iterator<
                                        typename std::iterator_traits<
				                typename _Tp::iterator
                                        >::value_type
                                >(std::cout,cout.token));
                std::cout<<cout.last_token;
        }
}rall_cout;

} // namespace miko
#endif
