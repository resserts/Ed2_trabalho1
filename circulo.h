#ifndef _CIRCULO_H
#define _CIRCULO_H

#include "smutreap.h"

Info criaCirculo(int i, double x, double y, double r, char* corb, char* corp);

void moveCirc(Info i, double x, double y);
int getCircId(Info i);
double getCircx(Info i);
double getCircy(Info i);
double getCircRaio(Info i);
char* getCircCorb(Info i);
char* getCircCorp(Info i);

#endif
