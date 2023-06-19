#include "xtra.h"

int main() {
    XtraVector * MyVec=NewXtraVector(16);
    XtraVectorPush(&MyVec,(void *)3);
    XtraVectorPush(&MyVec,(void *)4);
    XtraVectorPush(&MyVec,(void *)5);
    XtraVectorPush(&MyVec,(void *)6);
    printf("%p",XtraVectorIndex(&MyVec,2));
    MyVec=XtraVectorDelEl(&MyVec,2);
    printf("%p",XtraVectorIndex(&MyVec,2));
}