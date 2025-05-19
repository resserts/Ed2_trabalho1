#include "circulo.h"

#include <stdlib.h>

typedef struct{
     int id;
     double x, y, r;
     char* corb;
     char* corp;
}StCirculo;

Info criaCirculo(int i, double x, double y, double r, char* corb, char* corp){
     StCirculo* circ= (StCirculo*)malloc(sizeof(StCirculo));
     circ->id=i;
     circ->x=x;
     circ->y=y;
     circ->r=r;
     circ->corb=corb;
     circ->corp=corp;
     return circ;
}


