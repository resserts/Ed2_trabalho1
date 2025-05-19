#include "retangulo.h"

#include <stdlib.h>

typedef struct{
     int id;
     double x, y, w, h;
     char* corb;
     char* corp;
}StRetangulo;

Info criaRetangulo(int i, double x, double y, double w, double h, char* corb, char* corp){
     StRetangulo* ret= (StRetangulo*)malloc(sizeof(StRetangulo));
     ret->id=i;
     ret->x=x;
     ret->y=y;
     ret->w=w;
     ret->h=h;
     ret->corb=corb;
     ret->corp=corp;
     return ret;
}


