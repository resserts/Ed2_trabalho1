#ifndef _TEXTO_H
#define _TEXTO_H

#include "smutreap.h"

Info criaTexto(int i, double x, double y, char* corb, char* corp, char a, char* texto);
/* Retorna um ponteiro de um texto com id=i, ancora=(x,y), cor da borda=corb, cor de preenchimento=corp,
 * posição da ancora do texto=a(i: inicio, m: meio, f:fim) e counteúdo=texto;
*/

void mudaEstilo(char* fFamily, char* fWeight, char* fSize);
/* Muda os atributos que serão usados na criação dos próximos textos de forma que fonte=fFamily, 
 * font_weight=fWeight e font_size=fSize.
*/

void moveTxt(Info i, double x, double y);
// Move a ancora do texto i para (x,y).

// Retornam os atributos do texto i.
int getTxtId(Info i);
double getTxtx(Info i);
double getTxty(Info i);
char* getTxtCorb(Info i);
float getTxtStrokew(Info i);
char* getTxtCorp(Info i);
char getTxtPos(Info i);
char* getTxt(Info i);
char* getTxtFamily(Info i);
char* getTxtWeight(Info i);
char* getTxtSize(Info i);

void setTxtColors(Info i, char* corb, char* corp, float strokeWidth);
#endif
