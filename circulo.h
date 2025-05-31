#ifndef _CIRCULO_H
#define _CIRCULO_H

#include "smutreap.h"

Info criaCirculo(int i, double x, double y, double r, char* corb, char* corp);
// retorna o ponteiro para um circulo com id=i, x=x, y=y, raio=r, cor da borda=corb e cor de preenchimento=corp.

void moveCirc(Info i, double x, double y);
// Muda x e y do circulo i passado para x e y.

// Retornam os atributos do circulo i.
int getCircId(Info i);
double getCircx(Info i);
double getCircy(Info i);
double getCircRaio(Info i);
char* getCircCorb(Info i);
float getCircStrokew(Info i);
char* getCircCorp(Info i);

void setCircColors(Info i, char* corb, char* corp, float strokeWidth);

#endif
