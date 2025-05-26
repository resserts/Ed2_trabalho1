#include "retangulo.h"
#include "circulo.h"
#include "linha.h"
#include "svg.h"
#include "texto.h"
#include "smutreap.h"
#include "geo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATH_LEN 255

void calcbb(DescritorTipoInfo tp, Info i, double *x, double *y, double *w, double *h){
     return;
}


int main(int argc, char* argv[]){
     printf("argc: %i\n", argc);
     char BED[MAX_PATH_LEN]="./";
     char BSD[MAX_PATH_LEN];
     char geo[MAX_PATH_LEN];
     char query[MAX_PATH_LEN];
     char arq[MAX_PATH_LEN];
     int prioMax=10000;
     int hitCount=3;
     double promotionRate=1.1;

     for(int i=1; i<argc; i++){
          printf("i: %i\n", i);
          printf("argv[i]: %s\n", argv[i]);
          if(strcmp(argv[i], "-f")==0){
               printf("entro comandos\n");
               i++;
               strcpy(geo, argv[i]);
               strcpy(arq, geo);
               arq[strlen(arq)-5]='\0';
          }else if(strcmp(argv[i], "-e")==0){
               i++;
               strcpy(BED, argv[i]);
          }else if(strcmp(argv[i], "-o")==0){
               i++;
               strcpy(BSD, argv[i]);
          }else if(strcmp(argv[i], "-q")==0){
               i++;
               strcpy(query, argv[i]);
          }else if(strcmp(argv[i], "-p")==0){
               i++;
               prioMax=atoi(argv[i]);
          }else if(strcmp(argv[i], "-hc")==0){
               i++;
               hitCount=atoi(argv[i]);
          }else if(strcmp(argv[i], "-pr")==0){
               i++;
               promotionRate=atof(argv[i]);
          }
     }

     SmuTreap s=newSmuTreap(hitCount, promotionRate, 0.001, prioMax);
     char geoArq[MAX_PATH_LEN];
     strcpy(geoArq, BED);
     strcat(geoArq, geo);
     comandosGeo(s, geoArq);

     char dotArq[MAX_PATH_LEN];
     strcpy(dotArq, BSD);
     strcat(dotArq, arq);
     strcat(dotArq, ".dot");
     printDotSmuTreap(s, dotArq);

     char svgArq[MAX_PATH_LEN];
     strcpy(svgArq, BSD);
     strcat(svgArq, arq);
     strcat(svgArq, ".svg");
     gerarSvg(s, svgArq);

     return 0;
}
