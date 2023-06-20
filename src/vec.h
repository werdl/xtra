


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

#endif