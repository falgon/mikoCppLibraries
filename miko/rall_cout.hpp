#ifndef INCLUDED_RANGE_ALL_COUT
#define INCLUDED_RANGE_ALL_COUT
#include<iterator>
#include<iostream>
#include<map>
#include<stack>
#include<queue>
#include<boost/concept_check.hpp>
#include<boost/tuple/tuple.hpp>
#include<boost/foreach.hpp>
#ifndef __GXX_EXPERIMENTAL_CXX0X__
#include<boost/range.hpp>
#include<boost/move/move.hpp>
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
        void operator<<(const _Tp &container)
        {
                std::copy(container.begin(),container.end(),
                                std::ostream_iterator<
                                        typename _Tp::value_type
                                >(std::cout,token));
                std::cout<<last_token<<std::flush;
        }
        template<class _Tp,size_t size>
        void operator<<(_Tp (&ar)[size])
        {                
#ifdef __GXX_EXPERIMENTAL_CXX0X__
                using std::begin;
                using std::end;
                using std::make_move_iterator;
#else
                using boost::begin;
                using boost::end;
                using boost::make_move_iterator;
#endif
                std::copy(make_move_iterator(begin(ar)),make_move_iterator(end(ar)),
                                std::ostream_iterator<_Tp>(std::cout,token));
                std::cout<<last_token<<std::flush;
        }

        template<class InputIterator>
        void operator<<(const std::pair<InputIterator,InputIterator>& t)
        {
#ifdef __GXX_EXPERIMENTAL_CXX0X__
                using std::make_move_iterator;
#else
                using boost::make_move_iterator;
#endif
                boost::function_requires<boost::InputIteratorConcept<InputIterator> >();
                std::copy(make_move_iterator(t.first),make_move_iterator(t.second),
                                std::ostream_iterator<
                                        typename std::iterator_traits<
                                                InputIterator
                                        >::value_type
                                 >(std::cout,token));
                std::cout<<last_token<<std::flush;
        }

        //For Container Adapter. These are High cost.....
        template<class _Tp,class Range>
        void operator<<(std::stack<_Tp,Range> lhs)
        {
                for(;!lhs.empty();){
                        std::cout<<lhs.top()<<token;
                        lhs.pop();
                }
                std::cout<<last_token<<std::flush;
        }
        template<class _Tp,class Range>
        void operator<<(std::queue<_Tp,Range> lhs)
        {
                for(;!lhs.empty();){
                        std::cout<<lhs.front()<<token;
                        lhs.pop();
                }
                std::cout<<last_token<<std::flush;
        }
        template<class _Tp,class Range,class Compare>
        void operator<<(std::priority_queue<_Tp,Range,Compare> lhs)
        {
                for(;!lhs.empty();){
                        std::cout<<lhs.top()<<token;
                        lhs.pop();
                }
                std::cout<<last_token<<std::flush;
        }

        template<class _lTp,class _rTp,class Compare>
        void operator<<(const std::map<_lTp,_rTp,Compare>& m)
        {
                _lTp key; _rTp value;
                BOOST_FOREACH(boost::tie(key,value),m)
                        std::cout<<key<<token<<value<<last_token<<std::flush;
        }
        template<class _lTp,class _rTp,class Compare>
        void operator<<(const std::multimap<_lTp,_rTp,Compare>& m)
        {
                _lTp key; _rTp value;
                BOOST_FOREACH(boost::tie(key,value),m)
                        std::cout<<key<<token<<value<<last_token<<std::flush;
        }
        template<class _lTp,class _rTp>
        void operator<<(const std::pair<_lTp,_rTp>& p)
        {
                std::cout<<p.first<<token<<p.second<<last_token<<std::flush;
        }

        template<class InputIterator>
        void out_map_range(const InputIterator first,const InputIterator last) //HACK
        {
                boost::function_requires<boost::InputIteratorConcept<InputIterator> >();
                for(InputIterator it=first; it!=last; ++it)
                        std::cout<<(*it).first<<token<<(*it).second<<last_token<<std::flush;
        }        
}rall_cout;

} // namespace miko
#endif
