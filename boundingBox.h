#include "smutreap.h"

void calculabb(DescritorTipoInfo tp, Info i, double *x, double *y, double *w, double *h);
/*
 * Calcula o bounding box da informacao i.
 * Atribui a x,y,w,h, respectivamente, a ancora do retangulo (x,y), a largura e altura
 * do retangulo.
 */

Info criabb(double x, double y, double w, double h);

double getbbx(Info i);
double getbby(Info i);
double getbbWidth(Info i);
double getbbHeight(Info i);
