#ifndef INLCUDED_USR_INFO
#define INLCUDED_USR_INFO
#include<sys/types.h>
#include<pwd.h>
#include<iostream>
#include<boost/any.hpp>
#include<boost/assign.hpp>
#ifndef __GXX_EXPERIMENTAL_CXX0X__
#include<boost/array.hpp>
#else
#include<array>
#endif

namespace miko{
class usr_info{
public:
	usr_info()
		:data(getpwuid(getuid()))
	{}
	usr_info(uid_t uid)
		:data(getpwuid(uid))
	{}
	usr_info(const char *usr_name)
		:data(getpwnam(usr_name))
	{}
	usr_info(passwd* pw)
		:data(pw)
	{}

	size_t getuid()const{return getuid();}
	const char* getlogin()const{return getlogin();}
	
	const char* get_usrname()const{return data->pw_name;}
	__uid_t get_usruid()const{return data->pw_uid;}
	__gid_t get_usrgid()const{return data->pw_gid;}
       	const char* get_usrrealname()const{return data->pw_gecos;}
	const char* get_usrhomedirectory()const{return data->pw_dir;}
	const char* get_usrshell()const{return data->pw_shell;}
#ifndef __GXX_EXPERIMENTAL_CXX0X__
        using boost::array;
#else
        using std::array;
#endif        
	array<boost::any,6> make_array()
	{
		array<boost::any,6> usr_d={
			data->pw_name,
			data->pw_uid,
			data->pw_gid,
			data->pw_gecos,
			data->pw_dir,
			data->pw_shell,
		};
		return usr_d;
	}
	std::map<const char*,boost::any> make_map()
	{	
		return boost::assign::
			map_list_of<const char*,boost::any>
					("name",data->pw_name)
					("uid",data->pw_uid)
					("gid",data->pw_gid)
					("gecos",data->pw_gecos)
					("dir",data->pw_dir)
					("shell",data->pw_shell);
	}
	
	template<class OutputStream>
	friend OutputStream& operator<<(OutputStream& os,const usr_info& usr)
	{
		return os<<":"<<usr.data->pw_name<<"\n:"
			<<usr.data->pw_uid<<"\n:"<<
			usr.data->pw_gid<<"\n:"<<usr.data->pw_gecos<<"\n:"<<
			usr.data->pw_dir<<"\n:"<<usr.data->pw_shell;
	}
private:
	passwd* data;
};
}// namespace
#endif
