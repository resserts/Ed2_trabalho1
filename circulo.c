#include "circulo.h"

#include <stdlib.h>

typedef struct{
     int id;
     double r;
     char* corb;
     char* corp;
}StCirculo;

Info criaCirculo(int i, double r, char* corb, char* corp){
     StCirculo* circ= (StCirculo*)malloc(sizeof(StCirculo));
     circ->id=i;
     circ->r=r;
     circ->corb=corb;
     circ->corp=corp;
     return circ;
}


int getCircId(Info i){
     StCirculo* ret=(StCirculo*)i;
     return ret->id;
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
