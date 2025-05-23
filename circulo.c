#include "circulo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
     int id;
     double r;
     char corb[30];
     char corp[30];
}StCirculo;

Info criaCirculo(int i, double r, char* corb, char* corp){
     StCirculo* circ= (StCirculo*)malloc(sizeof(StCirculo));
     circ->id=i;
     circ->r=r;
     strcpy(circ->corb, corb);
     strcpy(circ->corp, corp);
     printf("Circulo criado corb: %s\n", circ->corb);
     printf("Circulo criado corp: %s\n", circ->corp);
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
