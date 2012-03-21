#ifndef INCLUDeD_EQUAL_RANGE_ERASE
#define INCLUDeD_EQUAL_RANGE_ERASE
#include<map>
#include<boost/concept_check.hpp>
namespace miko{

template<class Range,class InputIterator>
inline void eq_erase(Range& c,const std::pair<InputIterator,InputIterator>& p)
{
	boost::function_requires<boost::InputIteratorConcept<InputIterator> >();
	c.erase(p.first,p.second);
}

template<class Range,class InputIterator>
inline void eq_erase(Range& c,const InputIterator first,const InputIterator last)
{
        boost::function_requires<boost::InputIteratorConcept<InputIterator> >();
        c.erase(first,last);
}

template<class Range>
inline void eq_erase(Range& c)
{
        c.clear();
}

} // namespace
#endif
