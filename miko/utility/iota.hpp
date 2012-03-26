#ifndef INCLUDED_IOTA
#define INCLUDED_IOTA
#ifndef __GXX0X_EXPERIMENTAL_CXX0X__
#include<algorithm>
#endif
#include<set>
#include<stack>
#include<queue>
#include<map>

#include<boost/concept_check.hpp>
#include<boost/static_assert.hpp>

namespace miko{
template<class _ForwardIterator,class _Tp>
void iota(_ForwardIterator first,_ForwardIterator last,_Tp value)
{
#ifndef __GXX0X_EXPERIMENTAL_CXX0X__
	boost::function_requires<boost::ForwardIteratorConcept<
						_ForwardIterator> >();
	boost::function_requires<boost::ConvertibleConcept<_Tp,
						typename std::iterator_traits<
                                                        _ForwardIterator
                                                 >::value_type> >();
        for(; first!=last; ++first)
                *first=value++;
#else
        std::iota(first,last,value);
#endif
}

template<class Key,class Compare,class Allocator>
void iota(std::set<Key,Compare,Allocator>& s,Key first_value,Key last_value)
{      
        for(; (first_value>last_value?first_value:last_value)>(first_value>last_value?last_value:first_value);
                        ++(first_value>last_value?last_value:first_value))
                s.insert(s.end(),first_value>last_value?last_value:first_value);
}
template<class Key,class Compare,class Allocator>
void iota(std::multiset<Key,Compare,Allocator>& s,Key first_value,Key last_value)
{      
        for(; (first_value>last_value?first_value:last_value)>(first_value>last_value?last_value:first_value);
                        ++(first_value>last_value?last_value:first_value))
                s.insert(s.end(),first_value>last_value?last_value:first_value);
}
template<class _Tp,class Range>
void iota(std::stack<_Tp,Range>& s,_Tp first_value,_Tp last_value)
{
        for(; (first_value>last_value?first_value:last_value)>(first_value>last_value?last_value:first_value);
                        ++(first_value>last_value?last_value:first_value))
                s.push(first_value>last_value?last_value:first_value);
}
template<class _Tp,class Range>
void iota(std::queue<_Tp,Range>& q,_Tp first_value,_Tp last_value)
{
        for(; (first_value>last_value?first_value:last_value)>(first_value>last_value?last_value:first_value);
                        ++(first_value>last_value?last_value:first_value))
                q.push(first_value>last_value?last_value:first_value);
}
template<class _Tp,class Range,class Compare>
void iota(std::priority_queue<_Tp,Range,Compare>& pq,_Tp first_value,_Tp last_value)
{
        for(; (first_value>last_value?first_value:last_value)>(first_value>last_value?last_value:first_value);
                        ++(first_value>last_value?last_value:first_value))
                pq.push(first_value>last_value?last_value:first_value);
}
}// namespace
#endif
