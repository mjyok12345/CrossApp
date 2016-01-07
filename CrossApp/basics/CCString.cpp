#include "CCString.h"
#include <cstdlib>
NS_CC_BEGIN


int CCString::intValue()
{
    return std::atoi(_str.c_str());
}

CCString::CCString( const char* str )
{
    _str = str;
}

NS_CC_END