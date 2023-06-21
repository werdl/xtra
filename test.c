#include "xtra.h"

int main() {
    XtraVector2D * test=NewXtraVector2D(3,3);
    printf("%p\n",test->data);
    XtraVector2DNewRow(&test);
    XtraVector2DNewRow(&test);
    XtraVector2DPush(&test,2,1);
    printf("%p",(void*)XtraVectorIndex((test->data[1]),0));
}