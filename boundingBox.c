#include "boundingBox.h"
#include "svg.h"
#include "retangulo.h"
#include "circulo.h"
#include "linha.h"
#include "texto.h"
#include <stdio.h>
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
               *w=r*2;
               *h=r*2;
               printf("circ bb: %f, %f, %f, %f\n", *x, *y, *w, *h);
               break;
          case LINHA:
               double x1=getLinhax1(i);
               double x2=getLinhax2(i);
               double y1=getLinhay1(i);
               double y2=getLinhay2(i);
               *x=(x1<x2) ? x1 : x2;
               *y=(y1<y2) ? y1 : y2;
               *w=((x1>=x2) ? x1 : x2)-*x;
               *h=((y1>=y2) ? y1 : y2)-*y;
               break;
          case TEXTO:
               *x=getTxtx(i);
               *y=getTxty(i);
               *w=0;
               *h=0;
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

bool bbDentro(SmuTreap t, Node n, Info i, double x1, double y1, double x2, double y2){
     StBoundingBox* bb=i;
     if(bb->x>=x1 && bb->x+bb->w<=x2 && bb->y>=y1 && bb->y+bb->h<=y2){
          return true;
     }
     return false;
}

void uniaobb(Info bb1, Info bb2, Info bb3){
     if(bb1==NULL){
          return;
     }
     StBoundingBox* boundB1=bb1;
     StBoundingBox* boundB2=bb2;
     StBoundingBox* boundB3=bb3;
     double xmin=boundB1->x;
     double xmax=boundB1->x+boundB1->w;
     double ymin=boundB1->y;
     double ymax=boundB1->y+boundB1->h;
     if(boundB2!=NULL){
          xmin=(xmin<boundB2->x) ? xmin : boundB2->x;
          xmax=(xmax>boundB2->x+boundB2->w) ? xmax : boundB2->x+boundB2->w;
          ymin=(ymin<boundB2->y) ? ymin : boundB2->y;
          ymax=(ymax>boundB2->y+boundB2->h) ? ymax : boundB2->y+boundB2->h;
     }
     if(boundB3!=NULL){
          xmin=(xmin<boundB3->x) ? xmin : boundB3->x;
          xmax=(xmax>boundB3->x+boundB3->w) ? xmax : boundB3->x+boundB3->w;
          ymin=(ymin<boundB3->y) ? ymin : boundB3->y;
          ymax=(ymax>boundB3->y+boundB3->h) ? ymax : boundB3->y+boundB3->h;
     }
     boundB1->x=xmin;
     boundB1->y=ymin;
     boundB1->w=xmax-xmin;
     boundB1->h=ymax-ymin;
}

double getbbx(Info i){
     StBoundingBox* bb=i;
     return bb->x;
}
double getbby(Info i){
     StBoundingBox* bb=i;
     return bb->y;
}

double getbbWidth(Info i){
     StBoundingBox* bb=i;
     return bb->w;
}

double getbbHeight(Info i){
     StBoundingBox* bb=i;
     return bb->h;
}

