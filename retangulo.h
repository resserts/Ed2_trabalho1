#ifndef _RETANGULO_H
#define _RETANGULO_H

#include "smutreap.h"

Info criaRetangulo(int id, double w, double h, char* corb, char* corp);

int getRetId(Info i);
double getRetWidth(Info i);
double getRetHeight(Info i);
char* getRetCorb(Info i);
char* getRetCorp(Info i);

#endif
