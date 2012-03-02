#ifndef MIKO_ANY_INCLUDED
#define MIKO_ANY_INCLUDED

#define nullptr 0  //‚µ‚å‚¤‚ª–³‚­...

#include<typeinfo>
#include<cstdlib>
#include<iostream>
#include<algorithm>

namespace miko{

namespace place{
struct placeholder{
        virtual ~placeholder(){}
        virtual placeholder* clone()const=0;
        virtual const std::type_info& type()const=0;
};
template<class ValueType>
struct holder:public placeholder{
        ValueType value;
        holder(const ValueType& value):value(value){}
private:
        placeholder* clone()const
        {
                return new holder(value);
        }
        const std::type_info& type()const
        {
                return typeid(ValueType);
        }
};
}

class any{
        place::placeholder* content;
        size_t array;
public:
        any()
                :content(nullptr),
                array(1)
        {}
	template<class T>
	any(const T& value)
                :content(new place::holder<T>(value)),
                array(1)
        {}
        template<class T,size_t N>
        any(T (&value)[N])
                :content(new place::holder<T*>(value)),
                array(N)
        {}

	template<class T>
	any& operator=(const T& value)
	{
		if(!content)delete content;
		content=new place::holder<T>(value);
		return *this;
	}
        template<class T,size_t N>
        any& operator=(T(&value)[N])
        {
		if(!content)delete content;
                content=new place::holder<T*>(value);
                array=N;
                return *this;
        }                
        any& operator=(const any& obj)
        {
		if(!content)delete content;
                content=obj.content?obj.content->clone():nullptr;
                return *this;
        }
        ~any(){delete content;}

/*      To user member function      */
        const std::type_info& type()const
        {
                return content?content->type():typeid(void);
        }
        template<class T>
        const T& get()const
        {
                try{
                       return dynamic_cast<place::holder<T>& >(*content).value;
                }catch(std::bad_cast mes){
                        std::cerr<<
                                "miko::bad_get: failed conversion using miko::get =>"
                                <<mes.what()
                                <<std::endl;
                        if(!content==nullptr)delete content;
                        std::exit(-1);
                }
        }
        bool empty()const
        {
                return !content;
        }
        any& swap(any& rhs)
        {
                std::swap(content,rhs.content);
                return *this;
        }
        size_t size()
        {
                return array;
        }
};
} // namespace miko
#endif
