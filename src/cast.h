


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
#define tfloat(x) _Generic((x),\
    char *:(float)atof,\
    default:doubfloat\
)

#define doubint(x) (int)x
#define tint(x) _Generic((x),\
    char *:atoi,\
    default:doubint\
)

#define doubdoub(x) (double)x
#define tdouble(x) _Generic((x),\
    char *:atof,\
    default:doubdoub\
)
char * itof(double input) {
    char *c; //size of the number
    sprintf(c, "%g", input);
    return c;
}

#define tstr(x) _Generic(\
    int:itoa(x),\
    float:itof((double)x),\
    double:itof(x),\
    char *:x,\
    char:&x,\
    default:"err"\
)

#define tbool(x) _Generic(\
    int:(bool)x,\
    float:(bool)(int)x,\
    double:(bool)(int)x,\
    char *:x-'0',\
    bool:x,\
    default:(bool)(int)x\
)
