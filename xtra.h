
#ifndef _STDLIB_H
#include <stdlib.h>
#endif

#ifndef _STDIO_H
#include <stdio.h>
#endif

#ifndef _STRING_H
#include <string.h>
#endif

#define doubfloat(x) (float)x
#define float(x) _Generic((x),\
    char *:(float)atof,\
    default:doubfloat\
)

#define doubint(x) (int)x
#define int(x) _Generic((x),\
    char *:atoi,\
    default:doubint\
)

#define doubdoub(x) (double)x
#define double(x) _Generic((x),\
    char *:atof,\
    default:doubdoub\
)
char * itof(double input) {
    char *c; //size of the number
    sprintf(c, "%g", input);
    return c;
}

#define str(x) _Generic(\
    int:itoa(x),\
    float:itof((double)x),\
    double:itof(x),\
    char *:x,\
    char:&x,\
    default:"err"\
)

#define bool(x) _Generic(\
    int:(bool)x,\
    float:(bool)(int)x,\
    double:(bool)(int)x,\
    char *:x-'0',\
    bool:x,\
    default:(bool)(int)x\
)#define and &&
#define or ||
#define not !
#define nor !(a or b)
#define xor ^
#define bnot ~
#define band &
#define bor |
#define lshi <<
#define rshi >>

#define is ==
#define isnt !=

#define elif else if

#if defined(__thenfi__)
#define then {
#define fi } // for the Bash programmer
#endif

#define mainf int main(char ** argv,char * argc)
#define ret0 return 0
#define ret1 return 1

#define reterr return -1
#define ifthis(func,...) if(func(...))
#define ifnthis if(!func(...))

#ifndef _STDDEF_H
#include "stddef.h"
#endif
#ifndef _STDINT_H
#include "stdint.h"
#endif
typedef char * string;

#define big long long
#define ubig unsigned long long

typedef uint8_t uint8;
typedef uint16_t uint16;
typedef uint32_t uint32;
typedef uint64_t uint64;

typedef int8_t int8;
typedef int16_t int16;
typedef int32_t int32;
typedef int64_t int64;
#define GetType(type) _Generic((type), \
    char: "char", \
    signed char: "signed char", \
    unsigned char: "unsigned char", \
    short: "short", \
    unsigned short: "unsigned short", \
    int: "int", \
    unsigned int: "unsigned int", \
    long: "long", \
    unsigned long: "unsigned long", \
    long long: "long long", \
    unsigned long long: "unsigned long long", \
    float: "float", \
    double: "double", \
    long double: "long double", \
    void: "void", \
    char *: "char *", \
    signed char *: "signed char *", \
    unsigned char *: "unsigned char *", \
    short *: "short *", \
    unsigned short *: "unsigned short *", \
    int *: "int *", \
    unsigned int *: "unsigned int *", \
    long *: "long *", \
    unsigned long *: "unsigned long *", \
    long long *: "long long *", \
    unsigned long long *: "unsigned long long *", \
    float *: "float *", \
    double *: "double *", \
    long double *: "long double *", \
    void *: "void *", \
    default: "unknown" \
)
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
        XtraVector * newvec=realloc((*vec),sizeof(XtraVector)+sizeof(void *)*(*vec)->max*2);
        if (!vec) return VEC_FAILURE;
        (*vec)=newvec;
        (*vec)->max*=2;
    }
    (*vec)->data[(*vec)->length]=data;
    ++(*vec)->length;
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
#endif