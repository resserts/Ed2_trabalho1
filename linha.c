#include "linha.h"

#include <stdlib.h>

typedef struct{
     int id;
     double x2, y2;
     char* cor;
}StLinha;

Info criaLinha(int i, double x2, double y2, char* cor){
     StLinha* linha= (StLinha*)malloc(sizeof(StLinha));
     linha->id=i;
     linha->x2=x2;
     linha->y2=y2;
     linha->cor=cor;
     return linha;
}


int getLinhaId(Info i){
     StLinha* ret=(StLinha*)i;
     return ret->id;
}
double getLinhax2(Info i){
     StLinha* ret=(StLinha*)i;
     return ret->x2;
}
double getLinhay2(Info i){
     StLinha* ret=(StLinha*)i;
     return ret->y2;
}
char* getLinhaCor(Info i){
     StLinha* ret=(StLinha*)i;
     return ret->cor;
}

