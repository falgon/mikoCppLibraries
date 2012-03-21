#ifndef INCLUDED_ARGUMENT_OF
#define INCLUDED_ARGUMENT_OF

namespace miko{

template<class Signature>
struct argument_of;

template<class Function,class Arg>
struct argument_of<Function(Arg)>{
	typedef Arg type;
};

}// namespace 
#endif
