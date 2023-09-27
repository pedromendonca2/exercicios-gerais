#include <stdio.h>

typedef struct Data {
    int dia;
    int mes; 
    int ano; 
} tData;

int main(){

    tData data1 = {1, 2, 3};
    tData data2 = {3, 2, 1};

    // tData *p1 = &data1, *p2 = &data2; 
    // if(p1->dia == p2->dia && p1->mes == p2->mes && p1->ano == p2->ano){
    //     printf("IGUAL\n");
    // } else{
    //     printf("DESIGUAL\n");
    // }
    
    
    if(&data1->dia == *data2->dia && *data1->mes == *data2->mes && *data1->ano == *data2->ano){
        printf("IGUAL\n");
    } else{
        printf("DESIGUAL\n");
    }

    return 0;
}