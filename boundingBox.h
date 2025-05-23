#include "smutreap.h"

void calculabb(DescritorTipoInfo tp, Info i, double *x, double *y, double *w, double *h);
/*
 * Calcula o bounding box da informacao i.
 * Atribui a x,y,w,h, respectivamente, a ancora do retangulo (x,y), a largura e altura
 * do retangulo.
 */

Info criabb(double x, double y, double w, double h);
