#ifndef _TEXTO_H
#define _TEXTO_H

#include "smutreap.h"

Info criaTexto(int i, double x, double y, char* corb, char* corp, char a, char* texto);
void mudaEstilo(char* fFamily, char* fWeight, char* fSize);

void moveTxt(Info i, double x, double y);
int getTxtId(Info i);
double getTxtx(Info i);
double getTxty(Info i);
char* getTxtCorb(Info i);
char* getTxtCorp(Info i);
char getTxtPos(Info i);
char* getTxt(Info i);
char* getTxtFamily(Info i);
char* getTxtWeight(Info i);
char* getTxtSize(Info i);

#endif
