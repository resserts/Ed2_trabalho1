#include "linha.h"

#include <stdlib.h>
#include <string.h>

typedef struct{
     int id;
     double x1, y1;
     double x2, y2;
     char cor[30];
}StLinha;

Info criaLinha(int i, double x1, double y1, double x2, double y2, char* cor){
     StLinha* linha= (StLinha*)malloc(sizeof(StLinha));
     linha->id=i;
     linha->x1=x1;
     linha->y1=y1;
     linha->x2=x2;
     linha->y2=y2;
     strcpy(linha->cor, cor);
     return linha;
}


void moveLinha(Info i, double x, double y){
     StLinha* ret=(StLinha*)i;
     ret->x2-=ret->x1;
     ret->y2-=ret->y1;
     ret->x1=x;
     ret->y1=y;
     ret->x2+=ret->x1;
     ret->y2+=ret->y1;
}
int getLinhaId(Info i){
     StLinha* ret=(StLinha*)i;
     return ret->id;
}
double getLinhax1(Info i){
     StLinha* ret=(StLinha*)i;
     return ret->x1;
}
double getLinhay1(Info i){
     StLinha* ret=(StLinha*)i;
     return ret->y1;
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

