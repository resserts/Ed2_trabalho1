#include "query.h"
#include "retangulo.h"
#include "circulo.h"
#include "linha.h"
#include "svg.h"
#include "smutreap.h"
#include "texto.h"
#include "lista.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct{
     int n;
     Lista l;
}Selecao;

typedef struct{
     double x, y;
}Ancora;
bool igual(double x, double y, Ancora* anc, double epsilon){
     if(fabs(x-anc->x)<epsilon && fabs(y-anc->y)<epsilon){
          return true;
     }else{
          return false;
     }
}
bool igualNo(SmuTreap t, Node n, Info i, double x, double y, void *aux){
     if(igual(x, y, aux, epsilon)){

     }
}



void comandosQuery(SmuTreap t, char* fn){
     printf("arquivo query: %s\n", fn);
     FILE* f=fopen(fn, "r");
     if(f==NULL){
          printf("não foi possível acessar arquivo query\n");
          return;
     }
     Lista listas=criaLista();
     char comando[10];
     while(fscanf(f, "%s", comando)!=EOF){
          printf("entro while\n");
          printf("comando: %s\n", comando);
          if(strcmp(comando, "ts")==0){
               char family[30];
               char weight[3];
               char size[6];
               fscanf(f, "%s", family);
               fscanf(f, "%s", weight);
               fscanf(f, "%s", size);
               printf("final ts %s | %s | %s\n", family, weight, size);
          }else if(strcmp(comando, "selr")==0){
               int n;
               double x, y;
               double w, h;
               fscanf(f, "%i" , &n);
               fscanf(f, "%lf" , &x);
               fscanf(f, "%lf" , &y);
               fscanf(f, "%lf" , &w);
               fscanf(f, "%lf" , &h);
               for(int i=0; getValor(listas, i); i++){
                    Selecao* sel=getValor(listas, i);
                    if(sel->n==n){
                         getNodesDentroRegiaoSmuT(t, x, y, w, h, sel->l);
                         continue;
                    }
               }
               Selecao* sel=(Selecao*)malloc(sizeof(Selecao));
               sel->n=n;
               getNodesDentroRegiaoSmuT(t, x, y, w, h, sel->l);

               insertList(listas, sel, 0);
          }else if(strcmp(comando, "seli")==0){
               int n;
               double x, y;
               fscanf(f, "%i" , &n);
               fscanf(f, "%lf" , &x);
               fscanf(f, "%lf" , &y);

          }else if(strcmp(comando, "disp")==0){
               int i;
               int n;
               fscanf(f, "%i" , &i);
               fscanf(f, "%i" , &n);
          }else if(strcmp(comando, "transp")==0){
               int i;
               double x, y;
               fscanf(f, "%i" , &i);
               fscanf(f, "%lf" , &x);
               fscanf(f, "%lf" , &y);
          }else if(strcmp(comando, "cln")==0){
               int i;
               double dx, dy;
               fscanf(f, "%i" , &i);
               fscanf(f, "%lf" , &dx);
               fscanf(f, "%lf" , &dy);
          }else if(strcmp(comando, "spy")==0){
               int i;
               fscanf(f, "%i" , &i);
          }else if(strcmp(comando, "cmflg")==0){
               int i;
               char corb[30];
               char corp[30];
               char w[30];
               fscanf(f, "%i" , &i);
               fscanf(f, "%s" , corb);
               fscanf(f, "%s" , corp);
               fscanf(f, "%s" , w);
          }else if(strcmp(comando, "blow")==0){
               int i;
               fscanf(f, "%i" , &i);

          }
     }

     fclose(f);
}
