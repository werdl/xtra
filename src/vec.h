


#ifndef _VEC_H
#define _VEC_H
#define VEC_H
#define _XTRA_VEC
#define datalength 127
#define defaultmax 16

#ifndef _STDLIB_H
#include <stdlib.h>
#endif


typedef enum VectorReturn {
    VEC_SUCCESS,
    VEC_FAILURE
} XtraVectorReturn;

typedef struct {
    int length;
    int max;
    void * data[datalength];
} XtraVector;

XtraVector * NewXtraVector(int maxsize) {
    if (!maxsize) maxsize=defaultmax;
    XtraVector * TempVec=malloc(sizeof(XtraVector)+sizeof(void *)*maxsize);
    if (TempVec) {
        TempVec->max=maxsize;
        TempVec->length=0;
    }
    return TempVec;
}
XtraVectorReturn XtraVectorPush(XtraVector ** vec, void * data) {
    if ((*vec)->length+1 > (*vec)->max) {
        XtraVector * TempVec=realloc((*vec),sizeof(XtraVector)+sizeof(void *)*(*vec)->max*2);
        if (!vec) return VEC_FAILURE;
        (*vec)=TempVec;
        (*vec)->max*=2;
    }
    (*vec)->data[(*vec)->length]=data;
    ++(*vec)->length;
    return VEC_SUCCESS;
}
void * XtraVectorPop(XtraVector ** vec) {
    if ((*vec)->length==0) return NULL;
    --(*vec)->length;
    return (*vec)->data[(*vec)->length];
}
void * XtraVectorIndex(XtraVector ** vec,int index) {
    if ((*vec)->length==0 || index>=(*vec)->length) return NULL;
    return (*vec)->data[index];
} 
void XtraVectorDelete(XtraVector ** vec) {
    for (int i=(*vec)->length;i;i--) {
        (void)XtraVectorPop(vec);
    }
    free(vec);
}
XtraVector * XtraVectorDelEl(XtraVector ** vec, int el) {
    XtraVector * TempVec=NewXtraVector((*vec)->max);
    for (int i=0;i<(*vec)->length;i++) {
        if (i==el) continue;
        (void)XtraVectorPush(&TempVec,XtraVectorIndex(vec,i));
    }
    return TempVec;
}

XtraVector * XtraVectorChangeEl(XtraVector ** vec, int el, void * data) {
    XtraVector * TempVec=NewXtraVector((*vec)->max);
    for (int i=0;i<(*vec)->length;i++) {
        if (i==el) (void)XtraVectorPush(&TempVec,data);
        (void)XtraVectorPush(&TempVec,XtraVectorIndex(vec,i));
    }
    return TempVec;
}

#endif
#ifndef _MATRIX
#define _MATRIX
typedef struct {
    int rows;
    int columns;

    void * data[32][32];
} XtraMatrix;
XtraMatrix * NewXtraMatrix(int width, int length) {
    if (!width) width=defaultmax;
    if (!length) length=defaultmax;
    XtraMatrix * TempVec=malloc(sizeof(XtraMatrix)+sizeof(void *)*32*32);
    if (TempVec) {
        TempVec->rows=width;
        TempVec->columns=length;
    }
    return TempVec;
}
XtraVectorReturn XtraMatrixSet(XtraMatrix ** matrix,int row, int column, void * data) {
    if (row>=(*matrix)->rows || column>=(*matrix)->columns) return VEC_FAILURE;
    (*matrix)->data[row][column]=data;
    return VEC_SUCCESS;
}
void * XtraMatrixGrab(XtraMatrix ** matrix,int row, int column) {
    if (row>=(*matrix)->rows || column>=(*matrix)->columns) return NULL;
    return (*matrix)->data[row][column];
}
XtraVectorReturn XtraMatrixRemove(XtraMatrix ** matrix,int row, int column) {
    if (row>=(*matrix)->rows || column>=(*matrix)->columns) return VEC_FAILURE;
    (*matrix)->data[row][column]=NULL;
    return VEC_SUCCESS;
}
#endif