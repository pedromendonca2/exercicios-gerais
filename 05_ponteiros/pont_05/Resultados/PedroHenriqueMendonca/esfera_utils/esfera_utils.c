#include <stdio.h> 
#include "esfera_utils.h" 

void CalculaVolume(float R, float *volume){
    *volume = (float) 4*PI*R*R*R/3;
}

void CalculaArea(float R, float *area){
    *area = (float) 4*PI*R*R;
}