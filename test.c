#include "xtra.h"



int main() {
    XtraVector2D * test=NewXtraVector2D(3,3);
    XtraVector2DNewRow(&test);
    XtraVector2DNewRow(&test);
    XtraVector2DPush(&test,(void *)2,1);
    void * res=XtraVector2DGrab(&test,1,0);
    printf("%p",res);
}
// XtraVectorIndex((XtraVector **)&(test->data[1]),0))