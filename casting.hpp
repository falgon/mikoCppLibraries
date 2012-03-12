#ifndef CASTING_HPP_INCLUDED
#define CASTING_HPP_INCLUDED
namespace miko{
template<class from>
class Static_Cast{
	from var;
public:
	Static_Cast(from f):var(f){}
	template<class T>
	operator T()const
	{
		return static_cast<T>(var);
	}
};
template<class from>
Static_Cast<from> st_cast(from v)
{
	return Static_Cast<from>(v);
}

template<class from>
class Dynamic_Cast{
	from var;
public:
	Dynamic_Cast(from f):var(f){}
	template<class T>
	operator T()const
	{
		return dynamic_cast<T>(var);
	}
};
template<class from>
Dynamic_Cast<from> dy_cast(from v)
{
	return Dynamic_Cast<from>(v);
}

template<class from>
class Const_Cast{
	from var;
public:
	Const_Cast(from f):var(f){}
	template<class T>
	operator T()const
	{
		return const_cast<T>(var);
	}
};
template<class from>
Const_Cast<from> co_cast(from v)
{
	return Const_Cast<from>(v);
}

template<class from>
class Reinterpret_Cast{
	from var;
public:
	Reinterpret_Cast(from f):var(f){}
	template<class T>
	operator T()const
	{
		return reinterpret_cast<T>(var);
	}
};
template<class from>
Reinterpret_Cast<from> re_cast(from v)
{
	return Reinterpret_Cast<from>(v);
}

#include<sstream>

template<class from>
class Lexical_Cast{
	from var;
public:
	Lexical_Cast(from f):var(f){}
	template<class T>
	operator T()const
	{
		T result;
		std::stringstream ss;
		ss<<var;
		ss>>result;
		return result;
	}
};
template<class from>
Lexical_Cast<from> le_cast(from v)
{
	return Lexical_Cast<from>(v);
}
}

#endif
