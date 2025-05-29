#include "circulo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
     int id;
     double x, y;
     double r;
     char corb[30];
     char corp[30];
}StCirculo;

Info criaCirculo(int i, double x, double y, double r, char* corb, char* corp){
     StCirculo* circ= (StCirculo*)malloc(sizeof(StCirculo));
     circ->id=i;
     circ->x=x;
     circ->y=y;
     circ->r=r;
     strcpy(circ->corb, corb);
     strcpy(circ->corp, corp);
     return circ;
}

void moveCirc(Info i, double x, double y){
     StCirculo* ret=(StCirculo*)i;
     ret->x=x;
     ret->y=y;
}

int getCircId(Info i){
     StCirculo* ret=(StCirculo*)i;
     return ret->id;
}
double getCircx(Info i){
     StCirculo* ret=(StCirculo*)i;
     return ret->x;
}
double getCircy(Info i){
     StCirculo* ret=(StCirculo*)i;
     return ret->y;
}
double getCircRaio(Info i){
     StCirculo* ret=(StCirculo*)i;
     return ret->r;
}
char* getCircCorb(Info i){
     StCirculo* ret=(StCirculo*)i;
     return ret->corb;
}
char* getCircCorp(Info i){
     StCirculo* ret=(StCirculo*)i;
     return ret->corp;
}
