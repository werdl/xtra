#include "xtra.h"

int main() {
    XtraVector * MyVec=NewXtraVector(16);
    (void)XtraVectorPush(&MyVec,(void *)3); // cast ret value to void, we don't need it
    (void)XtraVectorPush(&MyVec,(void *)4);
    (void)XtraVectorPush(&MyVec,(void *)5);
    (void)XtraVectorPush(&MyVec,(void *)6);
    (void)printf("%p",XtraVectorIndex(&MyVec,2));
    MyVec=XtraVectorDelEl(&MyVec,2);
    (void)printf("%p",XtraVectorIndex(&MyVec,2));
}