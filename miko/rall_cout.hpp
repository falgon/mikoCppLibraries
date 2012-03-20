// Boost Software License - Version 1.0 - http://www.boost.org/LICENSE_1_0.txt 
#ifndef INCLUDED_RANGE_ALL_COUT
#define INCLUDED_RANGE_ALL_COUT
#include<iterator>
#include<iostream>
#include<map>
#include<boost/concept_check.hpp>
#include<boost/tuple/tuple.hpp>
#include<boost/foreach.hpp>
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
        void operator<<(const _Tp& container)
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
                                >(std::cout,token));
                std::cout<<last_token<<std::flush;
        }

        template<class InputIterator>
        void operator<<(const std::pair<InputIterator,InputIterator>& t)
        {
                boost::function_requires<boost::InputIteratorConcept<InputIterator> >();
                std::copy(t.first,t.second,
                                std::ostream_iterator<
                                        typename std::iterator_traits<
                                                InputIterator
                                        >::value_type
                                 >(std::cout,token));
                std::cout<<last_token<<std::flush;
        }

        template<class _lTp,class _rTp>
        void operator<<(const std::map<_lTp,_rTp>& m)
        {
                _lTp key; _rTp value;
                BOOST_FOREACH(boost::tie(key,value),m)
                        std::cout<<key<<token<<value<<last_token<<std::flush;
        }                               
}rall_cout;

} // namespace miko
#endif
