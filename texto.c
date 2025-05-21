#include "texto.h"

#include <stdlib.h>

typedef struct{
     int id;
     char* corb;
     char* corp;
     char a;
     char* texto;
     char* family;
     char* weight;
     int size;
}StTexto;

char* family = "sans-serif";
char* weight = "n";
int size=5;

Info criaTexto(int i, char* corb, char* corp, char a, char* texto){
     StTexto* txt= (StTexto*)malloc(sizeof(StTexto));
     txt->id=i;
     txt->corb=corb;
     txt->corp=corp;
     txt->a=a;
     txt->texto=texto;
     txt->family=family;
     txt->weight=weight;
     txt->size=size;
     return txt;
}

void mudaEstilo(char* fFamily, char* fWeight, int fSize){
     family=fFamily;
     weight=fWeight;
     size=fSize;
}

int getTxtId(Info i){
     StTexto* ret=(StTexto*)i;
     return ret->id;
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
int getTxtSize(Info i){
     StTexto* ret=(StTexto*)i;
     return ret->size;
}
