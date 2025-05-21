#include "retangulo.h"

#include <stdlib.h>

typedef struct{
     int id;
     double w, h;
     char* corb;
     char* corp;
}StRetangulo;

Info criaRetangulo(int i, double w, double h, char* corb, char* corp){
     StRetangulo* ret= (StRetangulo*)malloc(sizeof(StRetangulo));
     ret->id=i;
     ret->w=w;
     ret->h=h;
     ret->corb=corb;
     ret->corp=corp;
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

