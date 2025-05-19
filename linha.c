#include "linha.h"

#include <stdlib.h>

typedef struct{
     int id;
     double x1, y1, x2, y2;
     char* cor;
}StLinha;

Info criaLinha(int i, double x1, double y1, double x2, double y2, char* cor){
     StLinha* linha= (StLinha*)malloc(sizeof(StLinha));
     linha->id=i;
     linha->x1=x1;
     linha->y1=y1;
     linha->x2=x2;
     linha->y2=y2;
     linha->cor=cor;
     return linha;
}


