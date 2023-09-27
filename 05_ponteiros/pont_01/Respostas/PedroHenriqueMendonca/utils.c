// #include <stdio.h> 
// #include <stdlib.h> 
#include "utils.h" 

int TrocaInterios(int * n1, int * n2){
    int savevalue;

    if(*n1 <= *n2){
        return 0;
    } else{
        savevalue = *n1;
        *n1 = *n2;
        *n2 = savevalue;
    }
}