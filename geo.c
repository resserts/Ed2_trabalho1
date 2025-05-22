#include "geo.h"
#include "retangulo.h"
#include "circulo.h"
#include "linha.h"
#include "svg.h"
#include "smutreap.h"
#include "texto.h"
#include <stdio.h>
#include <string.h>

void comandosGeo(SmuTreap t, char* fn){
     printf("arquivo geo: %s\n", fn);
     FILE* f=fopen(fn, "r");
     if(f==NULL){
          printf("não foi possível acessar arquivo geo\n");
          return;
     }
     char comando[5];
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
               mudaEstilo(family, weight, size);
               printf("final ts %s | %s | %s\n", family, weight, size);
          }else if(strcmp(comando, "r")==0){
               int i;
               double x, y;
               double w, h;
               char corb[30];
               char corp[30];
               fscanf(f, "%i" , &i);
               fscanf(f, "%lf" , &x);
               fscanf(f, "%lf" , &y);
               fscanf(f, "%lf" , &w);
               fscanf(f, "%lf" , &h);
               fscanf(f, "%s" , corb);
               fscanf(f, "%s" , corp);
               insertSmuT(t, x, y, criaRetangulo(i, w, h, corb, corp), RETANGULO, NULL);
          }else if(strcmp(comando, "c")==0){
               int i;
               double x, y;
               double r;
               char corb[30];
               char corp[30];
               fscanf(f, "%i" , &i);
               fscanf(f, "%lf" , &x);
               fscanf(f, "%lf" , &y);
               fscanf(f, "%lf" , &r);
               fscanf(f, "%s" , corb);
               fscanf(f, "%s" , corp);
               insertSmuT(t, x, y, criaCirculo(i, r, corb, corp), CIRCULO, NULL);
          }else if(strcmp(comando, "l")==0){
               int i;
               double x, y;
               double x2, y2;
               char cor[30];
               fscanf(f, "%i" , &i);
               fscanf(f, "%lf" , &x);
               fscanf(f, "%lf" , &y);
               fscanf(f, "%lf" , &x2);
               fscanf(f, "%lf" , &y2);
               fscanf(f, "%s" , cor);
               insertSmuT(t, x, y, criaLinha(i, x2, y2, cor), LINHA, NULL);
          }else if(strcmp(comando, "t")==0){
               int i;
               double x, y;
               char corb[30];
               char corp[30];
               char a;
               char texto[256];
               fscanf(f, "%i" , &i);
               fscanf(f, "%lf" , &x);
               fscanf(f, "%lf" , &y);
               fscanf(f, "%s" , corb);
               fscanf(f, "%s" , corp);
               fscanf(f, " %c" , &a);
               fscanf(f, "%s" , texto);
               int len=strlen(texto);
               for(int i=0; i<len-1; i++){
                    texto[i]=texto[i+1];
               }
               texto[len-2]='\0';
               insertSmuT(t, x, y, criaTexto(i, corb, corp, a, texto), TEXTO, NULL);
          }
     }

     fclose(f);
}
