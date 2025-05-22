#ifndef _TEXTO_H
#define _TEXTO_H

#include "smutreap.h"

Info criaTexto(int i, char* corb, char* corp, char a, char* texto);
void mudaEstilo(char* fFamily, char* fWeight, char* fSize);

int getTxtId(Info i);
char* getTxtCorb(Info i);
char* getTxtCorp(Info i);
char getTxtPos(Info i);
char* getTxt(Info i);
char* getTxtFamily(Info i);
char* getTxtWeight(Info i);
char* getTxtSize(Info i);

#endif
