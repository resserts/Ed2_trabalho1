#include "retangulo.h"

#include <stdlib.h>
#include <string.h>

typedef struct{
     int id;
     double w, h;
     char corb[30];
     char corp[30];
}StRetangulo;

Info criaRetangulo(int i, double w, double h, char* corb, char* corp){
     StRetangulo* ret= (StRetangulo*)malloc(sizeof(StRetangulo));
     ret->id=i;
     ret->w=w;
     ret->h=h;
     strcpy(ret->corb, corb);
     strcpy(ret->corp, corp);
     return ret;
}


int getRetId(Info i){
     StRetangulo* ret=(StRetangulo*)i;
     return ret->id;
}
double getRetWidth(Info i){
     StRetangulo* ret=(StRetangulo*)i;
     return ret->w;
}
double getRetHeight(Info i){
     StRetangulo* ret=(StRetangulo*)i;
     return ret->h;
}
char* getRetCorb(Info i){
     StRetangulo* ret=(StRetangulo*)i;
     return ret->corb;
}
char* getRetCorp(Info i){
     StRetangulo* ret=(StRetangulo*)i;
     return ret->corp;
}

