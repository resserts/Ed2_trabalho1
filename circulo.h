#ifndef _CIRCULO_H
#define _CIRCULO_H

#include "smutreap.h"

Info criaCirculo(int i, double r, char* corb, char* corp);

int getCircId(Info i);
double getCircRaio(Info i);
char* getCircCorb(Info i);
char* getCircCorp(Info i);

#endif
