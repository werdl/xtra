#include "xtra.h"

int main() {
    XtraVector * MyVec=NewXtraVector(16);
    XtraVectorPush(&MyVec,3);
    XtraVectorPush(&MyVec,4);
    XtraVectorPush(&MyVec,5);
    XtraVectorPush(&MyVec,6);
    printf("%p",XtraVectorIndex(&MyVec,2));
    MyVec=XtraVectorDelEl(&MyVec,2);
    printf("%p",XtraVectorIndex(&MyVec,2));
}