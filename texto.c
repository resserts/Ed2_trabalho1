#include "texto.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
     int id;
     double x, y;
     char corb[30];
     char corp[30];
     char a;
     char texto[256];
     char family[30];
     char weight[30];
     char size[30];
}StTexto;

char family[30] = "sans-serif";
char weight[30] = "n";
char size[30]="12px";

Info criaTexto(int i, double x, double y, char* corb, char* corp, char a, char* texto){
     StTexto* txt= (StTexto*)malloc(sizeof(StTexto));
     txt->id=i;
     strcpy(txt->corb, corb);
     strcpy(txt->corp, corp);
     txt->a=a;
     txt->x=x;
     txt->y=y;
     strcpy(txt->texto, texto);
     strcpy(txt->family, family);
     strcpy(txt->weight, weight);
     strcpy(txt->size, size);
     printf("family: %s\n", txt->family);
     printf("weight: %s\n", txt->weight);
     printf("size: %s\n", txt->size);
     return txt;
}

void mudaEstilo(char* fFamily, char* fWeight, char* fSize){
     strcpy(family, fFamily);
     strcpy(weight, fWeight);
     strcpy(size, fSize);
}

void moveTxt(Info i, double x, double y){
     StTexto* ret=(StTexto*)i;
     ret->x=x;
     ret->y=y;
}
int getTxtId(Info i){
     StTexto* ret=(StTexto*)i;
     return ret->id;
}
double getTxtx(Info i){
     StTexto* ret=(StTexto*)i;
     return ret->x;
}
double getTxty(Info i){
     StTexto* ret=(StTexto*)i;
     return ret->y;
}
char* getTxtCorb(Info i){
     StTexto* ret=(StTexto*)i;
     return ret->corb;
}
char* getTxtCorp(Info i){
     StTexto* ret=(StTexto*)i;
     return ret->corp;
}
char getTxtPos(Info i){
     StTexto* ret=(StTexto*)i;
     return ret->a;
}
char* getTxt(Info i){
     StTexto* ret=(StTexto*)i;
     return ret->texto;
}
char* getTxtFamily(Info i){
     StTexto* ret=(StTexto*)i;
     return ret->family;
}
char* getTxtWeight(Info i){
     StTexto* ret=(StTexto*)i;
     return ret->weight;
}
char* getTxtSize(Info i){
     StTexto* ret=(StTexto*)i;
     return ret->size;
}
