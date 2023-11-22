#include <stdio.h>
#include <stdlib.h>
#include "tadgen.h"

int main(){

    int type;
    int numElem;

    printf("tad_gen_01\nDigite o tipo e numero de elementos: ");
    scanf("%d %d", &type, &numElem);

    tGeneric* generico = CriaGenerico(type, numElem);

    LeGenerico(generico);
    ImprimeGenerico(generico);

    DestroiGenerico(generico);

    return 0;
}