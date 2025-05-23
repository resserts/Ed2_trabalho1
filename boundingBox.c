#include "boundingBox.h"
#include "svg.h"
#include "retangulo.h"
#include "circulo.h"
#include "linha.h"
#include "texto.h"
#include <stdlib.h>
#include <string.h>

typedef struct{
     double x, y;
     double w, h;
}StBoundingBox;

void calculabb(DescritorTipoInfo tp, Info i, double *x, double *y, double *w, double *h){
     switch (tp) {
          case RETANGULO:
               *x=getRetX(i);
               *y=getRetY(i);
               *w=getRetWidth(i);
               *h=getRetHeight(i);
               break;
          case CIRCULO:
               double r=getCircRaio(i);
               *x=getCircx(i)-r;
               *y=getCircy(i)-r;
               *w=getCircx(i)+r;
               *h=getCircy(i)+r;
               break;
          case LINHA:
               double x1=getLinhax1(i);
               double x2=getLinhax2(i);
               double y1=getLinhay1(i);
               double y2=getLinhay2(i);
               *x=(x1<x2) ? x1 : x2;
               *y=(y1<y2) ? y1 : y2;
               *w=(x1>=x2) ? x1 : x2;
               *h=(y1>=y2) ? y1 : y2;
               break;
          default:
               break;
               
     }
}
/*
 * Calcula o bounding box da informacao i.
 * Atribui a x,y,w,h, respectivamente, a ancora do retangulo (x,y), a largura e altura
 * do retangulo.
 */

Info criabb(double x, double y, double w, double h){
     StBoundingBox* bb=(StBoundingBox*)malloc(sizeof(StBoundingBox));
     bb->x=x;
     bb->y=y;
     bb->w=w;
     bb->h=h;
     return bb;
}
