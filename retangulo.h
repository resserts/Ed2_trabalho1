#ifndef _RETANGULO_H
#define _RETANGULO_H

#include "smutreap.h"

Info criaRetangulo(int id, double x, double y, double w, double h, char* corb, char* corp);
/* Retorna o retangulo com id=id, ancora=(x,y), largura=w, 
 * altura=h, cor da borda=corb e cor de preenchimento=corp.
*/

void moveRet(Info i, double x, double y);
// Move o retangulo i para (x,y).

int getRetId(Info i);
double getRetX(Info i);
double getRetY(Info i);
double getRetWidth(Info i);
double getRetHeight(Info i);
char* getRetCorb(Info i);
char* getRetCorp(Info i);

#endif
