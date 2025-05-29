#include "smutreap.h"

void calculabb(DescritorTipoInfo tp, Info i, double *x, double *y, double *w, double *h);
/*
 * Calcula o bounding box da informacao i.
 * Atribui a x,y,w,h, respectivamente, a ancora do retangulo (x,y), a largura e altura
 * do retangulo.
 */

Info criabb(double x, double y, double w, double h);
// retorna uma bounding box com ancora (x, y) e largura e altura w e h, respectivamente.

bool bbDentro(SmuTreap t, Node n, Info i, double x1, double y1, double x2, double y2);
// retorna true se a bounding box i estiver dentro da região delimitada 
// por (x1, y1) e (x2, y2) e falso em caso contrário.
void uniaobb(Info bb1, Info bb2, Info bb3);
// coloca a uniao das 3 bounding box em bb1. Se bb1 for nulo, nao faz nada.

double getbbx(Info i);
double getbby(Info i);
double getbbWidth(Info i);
double getbbHeight(Info i);
