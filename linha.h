#ifndef _LINHA_H
#define _LINHA_H

#include "smutreap.h"

Info criaLinha(int i, double x, double y, double x2, double y2, char* corb);
// Retorna o ponteiro para a linha com id=i, que vai da ancora=(x,y) até (x2,y2) e tem cor=corb.

void moveLinha(Info i, double x, double y);
// Move a linha i de forma que a ancora fique em (x,y);

// Retornam os atributos da linha i.
int getLinhaId(Info i);
double getLinhax1(Info i);
double getLinhay1(Info i);
double getLinhax2(Info i);
double getLinhay2(Info i);
char* getLinhaCor(Info i);

#endif
