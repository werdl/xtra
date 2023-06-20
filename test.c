#include "xtra.h"

int main() {
    XtraMatrix * MyVec=NewXtraMatrix(3,3);
    (void)XtraMatrixSet(&MyVec,2,2,(void *)3);
    printf("%p",XtraMatrixGrab(&MyVec,2,2));
    (void)XtraMatrixSet(&MyVec,2,2,(void *)4);
    printf("%p",XtraMatrixGrab(&MyVec,2,2));
}