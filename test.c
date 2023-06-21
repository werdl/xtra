#include "xtra.h"

int main() {
    XtraVector2D * test=NewXtraVector2D(3,3);
    printf("%p\n",test->data);
    XtraVector2DNewRow(&test);
    XtraVector2DPush(&test,4,0);
    printf("%p",test->data);
}