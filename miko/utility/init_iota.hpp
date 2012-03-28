#ifndef INCLUDED_INIT_IOTA
#define INCLUDED_INIT_IOTA
#include<boost/preprocessor.hpp>
#define INIT_IOTA_T(z,x,text) x,
#define INIT_IOTA(x,y) BOOST_PP_REPEAT_FROM_TO(x,y,INIT_IOTA_T,_)
#endif
