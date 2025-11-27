#include "include/dyn.h"
#include <stdio.h>

/*
    Here, we introduce a datatype dynamic.
    dynamic can store any three of these: int, float, char.
    eval() is the initialization
    dint(), dfloat(), dchar() is needed to scrap the value from variable.  
*/

int main(){
    dynamic a = eval(4);
    dynamic b = eval(5.3);
    dynamic res = eval(dint(a) + dfloat(b));
    printf("%.2f\n", dfloat(res));
    return 0;
}