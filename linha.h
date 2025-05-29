#ifndef _LINHA_H
#define _LINHA_H

#include "smutreap.h"

Info criaLinha(int i, double x, double y, double x2, double y2, char* corb);

void moveLinha(Info i, double x, double y);
int getLinhaId(Info i);
double getLinhax1(Info i);
double getLinhay1(Info i);
double getLinhax2(Info i);
double getLinhay2(Info i);
char* getLinhaCor(Info i);

#endif
