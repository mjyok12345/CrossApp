#ifndef __CCSTRING_H__
#define __CCSTRING_H__

#include "CAObject.h"

NS_CC_BEGIN

class CC_DLL CCString : public CAObject {
public:
    CCString(const char* str);

    int intValue();

    CC_SYNTHESIZE_PASS_BY_REF(std::string,_str,String)
};

NS_CC_END

#endif // __CCSTRING_H__