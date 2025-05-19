#include "texto.h"

#include <stdlib.h>

typedef struct{
     int id;
     double x, y;
     char* corb;
     char* corp;
     char a;
     char* texto;
}StTexto;

char* family = "sans-serif";
char weight = 'n';
int size=5;

Info criaTexto(int i, double x, double y, char* corb, char* corp, char a, char* texto){
     StTexto* txt= (StTexto*)malloc(sizeof(StTexto));
     txt->id=i;
     txt->x=x;
     txt->y=y;
     txt->corb=corb;
     txt->corp=corp;
     txt->a=a;
     txt->texto=texto;
     return txt;
}

void mudaEstilo(char* fFamily, char fWeight, int fSize){
     family=fFamily;
     weight=fWeight;
     size=fSize;
}
