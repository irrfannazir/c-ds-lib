#ifndef DYN_H
#define DYN_H

#define MAIN(PGM) int main(){PGM; return 0;}

typedef enum {
    INTEGER,
    DECIMAL,
    CHAR
} typec;

typedef struct{
    typec type;
    union{
        int intv;
        float fltv;
        char chrv; 
    } val;
} dynamic;


#define eval(x) _Generic((x), \
    int: (( dynamic ){INTEGER, {.intv = (x)}}), \
    float: (( dynamic ){DECIMAL, {.fltv = (x)}}), \
    double: (( dynamic ){DECIMAL, {.fltv = (x)}}), \
    char: (( dynamic ){CHAR, {.chrv = (x)}}) \
)

#define dint(x) (x.val.intv)
#define dfloat(x) (x.val.fltv)
#define dchar(x) (x.val.chrv)



#endif