#ifndef _XTRA_VEC
#include "../xtra.h"
#endif
void fail(char * msg, char * test);
void succ(char * test);

int TestLogic() {
    bool failed=false;
    
    if ((1 and 1)!=(1 && 1)) fail("and!=&&","TestTypes"),failed=true;
    if ((1 or 1)!=(1 || 1)) fail("or!=||","TestTypes"),failed=true;
    if ((nor(1,1))!=(!(1 or 1))) fail("nor(a,b)!=!(a,b)","TestTypes"),failed=true;


    if (!failed) succ("TestTypes");
}