#ifndef _LINHA_H
#define _LINHA_H

#include "smutreap.h"

Info criaLinha(int i, double x2, double y2, char* corb);

int getLinhaId(Info i);
double getLinhax2(Info i);
double getLinhay2(Info i);
char* getLinhaCor(Info i);

#endif
