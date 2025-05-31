#include "query.h"
#include "retangulo.h"
#include "circulo.h"
#include "linha.h"
#include "svg.h"
#include "smutreap.h"
#include "texto.h"
#include "lista.h"
#include "boundingBox.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

typedef struct{
     int n;
     Lista l;
}Selecao;
Selecao* criaSelecao(int n){
     Selecao* sel=(Selecao*)malloc(sizeof(Selecao));
     sel->l=criaLista();
     sel->n=n;
     return sel;
}

bool noComId(SmuTreap t, Node n, Info i, double x, double y, void *aux){
     DescritorTipoInfo dt=getTypeInfoSrbT(t, n);
     int id=0;
     switch (dt) {
          case RETANGULO:
               id=getRetId(i);
               break;
          case CIRCULO:
               id=getCircId(i);
               break;
          case LINHA:
               id=getLinhaId(i);
               break;
          case TEXTO:
               id=getTxtId(i);
               break;
          default:
               break;
     }
     int* procurado=(int*)aux;
     if(id==*procurado){
          return true;
     }
     return false;
}

double getX(SmuTreap t, Node n){
     DescritorTipoInfo dt=getTypeInfoSrbT(t, n);
     Info i=getInfoSmuT(t, n);
     switch (dt) {
          case RETANGULO:
               return getRetX(i);
          case CIRCULO:
               return getCircx(i);
          case LINHA:
               return getLinhax1(i);
          case TEXTO:
               return getTxtx(i);
          default:
               return 0;
     }
}
double getY(SmuTreap t, Node n){
     DescritorTipoInfo dt=getTypeInfoSrbT(t, n);
     Info i=getInfoSmuT(t, n);
     switch (dt) {
          case RETANGULO:
               return getRetY(i);
          case CIRCULO:
               return getCircy(i);
          case LINHA:
               return getLinhay1(i);
          case TEXTO:
               return getTxty(i);
          default:
               return 0;
     }
}

double calcArea(SmuTreap t, Node n){
     DescritorTipoInfo dt=getTypeInfoSrbT(t, n);
     Info i=getInfoSmuT(t, n);
     switch (dt) {
          case RETANGULO:
               return getRetWidth(i)*getRetHeight(i);
          case CIRCULO:
               return getCircRaio(i)*getCircRaio(i)*3.14;
          case LINHA:
               double x=getLinhax2(i)-getLinhax1(i);
               double y=getLinhay2(i)-getLinhay1(i);
               return 10*sqrt((x*x)+(y*y));
          case TEXTO:
               return 12*strlen(getTxt(i));
          default:
               return 0;
     }
}

bool pontoIgual(double x, double y, double x2, double y2, double epsilon){
     if(fabs(x-x2)<epsilon && fabs(y-y2)<epsilon){
          return true;
     }else{
          return false;
     }
}
bool pontoInternoAInfo(SmuTreap t, Node n, Info i, double x, double y){
     DescritorTipoInfo dt=getTypeInfoSrbT(t, n);
     switch (dt) {
          case RETANGULO:
               if(getRetX(i)<=x && getRetX(i)+getRetWidth(i)>=x && getRetY(i)<=y && getRetY(i)+getRetHeight(i)>=y){
                    return true;
               }
               return false;
          case CIRCULO:
               int dist=pow(getCircx(i)-x, 2) + pow(getCircy(i)-y, 2);
               return dist<=pow(getCircRaio(i), 2);
          case LINHA:
               return pontoIgual(x, y, getLinhax1(i), getLinhay1(i), getEpsilon(t));
          case TEXTO:
               return pontoIgual(x, y, getTxtx(i), getTxty(i), getEpsilon(t));
          default:
               return 0;
     }
}

void disp(SmuTreap t, Lista listas, int id, int n, char* saida){
     for(int i=0; getValor(listas, i); i++){
          Selecao* sel=getValor(listas, i);
          if(sel->n==n){
               Lista letras=criaLista();
               Node dir=procuraNoSmuT(t, &noComId, &id);
               Lista destruir=criaLista();
               for(int j=0; getValor(sel->l, j); j++){
                    Node n=getValor(sel->l, j);
                    double dirComp=calcArea(t, dir)/10.;
                    Info dirLinha=getInfoSmuT(t, dir);
                    double dirx=(getLinhax2(dirLinha)-getLinhax1(dirLinha))/dirComp;
                    double diry=(getLinhay2(dirLinha)-getLinhay1(dirLinha))/dirComp;
                    getInfosAtingidoPontoSmuT(t, getX(t, n)+dirx*calcArea(t, n), getY(t, n)+diry*calcArea(t, n),
                              &pontoInternoAInfo, destruir);
                    printf("disp dist: %f\n", calcArea(t, n));

                    Letra hash=criaLetra(getX(t, n)+dirx*calcArea(t, n), getY(t, n)+diry*calcArea(t, n), '#');
                    insertList(letras, hash, 0);
               }
               for(int k=0; getValor(destruir, k); k++){
                    Node destruido=getValor(destruir, k);
                    Letra chis=criaLetra(getX(t, destruido), getY(t, destruido), 'X');
                    insertList(letras, chis, 0);
               }
               char disp[256];
               strcpy(disp, saida);
               strcat(disp, "-disp.svg");
               gerarSvg(t, disp, letras);
               for(int k=0; getValor(destruir, k); k++){
                    Node destruido=getValor(destruir, k);
                    removeNoSmuT(t, destruido);
               }
               for(int k=0; getValor(letras, k); k++){
                    Letra excluir=getValor(letras, k);
                    free(excluir);
               }
               killLista(destruir);
               killLista(letras);
               break;
          }
     }
}

void spy(SmuTreap t, int id, char* saida){
     Node n=procuraNoSmuT(t, &noComId, &id);
     if(n==NULL){
          return;
     }
     Lista dentro=criaLista();

     if(getTypeInfoSrbT(t, n)==TEXTO){
          insertList(dentro, n, 0);
     }else{
          double x, y, w, h;
          getBoundingBoxSmuT(t, n, &x, &y, &w, &h);

          printf("%f, %f, %f, %f\n", x, y, w, h);
          if(getInfosDentroRegiaoSmuT(t, x, y, x+w, y+h, &bbDentro, dentro)){
               printf("acho pelo menos um\n");
          }
     }
     FILE* f=fopen(saida, "a");
     if(f==NULL){
          return;
     }
     for(int i=0; getValor(dentro, i); i++){
          Node n=getValor(dentro, i);
          DescritorTipoInfo dt=getTypeInfoSrbT(t, n);
          Info info=getInfoSmuT(t, n);
          switch (dt) {
               case RETANGULO:
                    fprintf(f, "%i: Retangulo\n\tx:%f\n\ty:%f\n\twidth:%f\n\theight:%f\n\n", 
                              getRetId(info), getRetX(info), getRetY(info), getRetWidth(info), getRetHeight(info));
                    break;
               case CIRCULO:
                    fprintf(f, "%i: Circulo\n\tx:%f\n\ty:%f\n\traio:%f\n\n", 
                              getCircId(info), getCircx(info), getCircy(info), getCircRaio(info));
                    break;
               case LINHA:
                    fprintf(f, "%i: Linha\n\tx1:%f\n\ty1:%f\n\tx2:%f\n\ty2:%f\n\n", 
                              getLinhaId(info), getLinhax1(info), getLinhay1(info), getLinhax2(info), getLinhay2(info));
                    break;
               case TEXTO:
                    fprintf(f, "%i: Texto\n\tx:%f\n\ty:%f\n\tconteudo:%s\n\n", 
                              getTxtId(info), getTxtx(info), getTxty(info), getTxt(info));
                    break;
               default:
                    break;
          }
     }
     fclose(f);
}

void blow(SmuTreap t, int id, char* saida){
     Node destruir=procuraNoSmuT(t, &noComId, &id);
     Lista letras=criaLista();
     Letra chis=criaLetra(getX(t, destruir), getY(t, destruir), 'X');
     insertList(letras, chis, 0);
     char disp[256];
     strcpy(disp, saida);
     strcat(disp, "-blow.svg");
     gerarSvg(t, disp, letras);
     removeNoSmuT(t, destruir);
     for(int k=0; getValor(letras, k); k++){
          Letra excluir=getValor(letras, k);
//          free(excluir);
     }
     killLista(letras);
}

void comandosQuery(SmuTreap t, char* fn, char* saida){
     printf("arquivo query: %s\n", fn);
     FILE* f=fopen(fn, "r");
     if(f==NULL){
          printf("não foi possível acessar arquivo query\n");
          return;
     }
     Lista listas=criaLista();
     char comando[10];
     char spyfn[256];
     strcpy(spyfn, saida);
     strcat(spyfn, "-spy.txt");
     remove(spyfn);
     char cmflgfn[256];
     strcpy(cmflgfn, saida);
     strcat(cmflgfn, "-cmflg.txt");
     remove(cmflgfn);
     char transpfn[256];
     strcpy(transpfn, saida);
     strcat(transpfn, "-transp.txt");
     remove(transpfn);
     char slrfn[256];
     strcpy(slrfn, saida);
     strcat(slrfn, "-selr.txt");
     remove(slrfn);
     while(fscanf(f, "%s", comando)!=EOF){
          printf("comando: %s\n", comando);
          if(strcmp(comando, "selr")==0){
               int n;
               double x, y;
               double w, h;
               fscanf(f, "%i" , &n);
               fscanf(f, "%lf" , &x);
               fscanf(f, "%lf" , &y);
               fscanf(f, "%lf" , &w);
               fscanf(f, "%lf" , &h);
               Selecao* sel;
               for(int i=0; getValor(listas, i); i++){
                    sel=getValor(listas, i);
                    if(sel->n==n){
                         killLista(sel->l);
                         sel->l=criaLista();
                         goto seleciona;
                    }
               }
               sel=criaSelecao(n);
seleciona:
               //printf("x: %f, y: %f, w:");
               if(getInfosDentroRegiaoSmuT(t, x, y, x+w, y+h, &bbDentro, sel->l)){
                    printf("acho info");
               }
               Lista letras=criaLista();
               FILE* slrf=fopen(slrfn, "a");
               for(int i=0; getValor(sel->l, i); i++){
                    Node n=getValor(sel->l, i);
                    DescritorTipoInfo dt=getTypeInfoSrbT(t, n);
                    Info inf=getInfoSmuT(t, n);
                    Letra bola;
                    switch (dt) {
                         case RETANGULO:
                              fprintf(slrf, "Retangulo: %i\t\n", getRetId(inf));
                              bola=criaLetra(getRetX(inf), getRetY(inf)+2, 'o');
                              insertList(letras, bola, 0);
                              break;
                         case CIRCULO:
                              fprintf(slrf, "Circulo: %i\t\n", getCircId(inf));
                              bola=criaLetra(getCircx(inf), getCircy(inf)+2, 'o');
                              insertList(letras, bola, 0);
                              break;
                         case LINHA:
                              fprintf(slrf, "Linha: %i\t\n", getLinhaId(inf));
                              bola=criaLetra(getLinhax1(inf), getLinhay1(inf)+2, 'o');
                              insertList(letras, bola, 0);
                              break;
                         case TEXTO:
                              fprintf(slrf, "Texto: %i\t\n", getTxtId(inf));
                              bola=criaLetra(getTxtx(inf)+2, getTxty(inf)+2, 'o');
                              insertList(letras, bola, 0);
                              break;
                         default:
                              break;
                    }
               }
               fclose(slrf);

               insertList(listas, sel, 0);

               Node ret=insertSmuT(t, x, y, criaRetangulo(-1, x, y, w, h, "#FF0000", "#FF0000"), RETANGULO, &calculabb);
               slrfn[strlen(slrfn)-4]='\0';

               strcat(slrfn, ".svg");
               gerarSvg(t, slrfn, letras);
               removeNoSmuT(t, ret);
               //slrfn[strlen(slrfn)-4]='\0';
               //strcat(slrfn, ".txt");
               for(int i=0; getValor(letras, i); i++){
                    free(getValor(letras, i));
               }
               killLista(letras);
          }else if(strcmp(comando, "seli")==0){
               int n;
               double x, y;
               fscanf(f, "%i" , &n);
               fscanf(f, "%lf" , &x);
               fscanf(f, "%lf" , &y);
               Node selecionado;
               for(int i=0; getValor(listas, i); i++){
                    Selecao* sel=getValor(listas, i);
                    if(sel->n==n){
                         selecionado=getNodeSmuT(t, x, y);
                         insertList(sel->l, selecionado, 0);
                         continue;
                    }
               }
               Selecao* sel=criaSelecao(n);
               selecionado=getNodeSmuT(t, x, y);
               insertList(sel->l, selecionado, 0);

               insertList(listas, sel, 0);
          }else if(strcmp(comando, "disp")==0){
               int id;
               int n;
               fscanf(f, "%i" , &id);
               fscanf(f, "%i" , &n);
               disp(t, listas, id, n, saida);

          }else if(strcmp(comando, "transp")==0){
               int id;
               double x, y;
               fscanf(f, "%i" , &id);
               fscanf(f, "%lf" , &x);
               fscanf(f, "%lf" , &y);

               printf("veio ate antes\n");
               Node n=procuraNoSmuT(t, &noComId, &id);
               if(n==NULL){
                    continue;
               }
               printf("acho o no\n");
               DescritorTipoInfo dt=getTypeInfoSrbT(t, n);
               Info inf=getInfoSmuT(t, n);
               FILE* transf=fopen(transpfn, "a");
               switch (dt) {
                    case RETANGULO:
                         fprintf(transf, "%i: Retangulo\n\tx:%f\n\ty:%f\n\n", 
                                   getRetId(inf), getRetX(inf), getRetY(inf));
                         printf("will move ret\n");
                         removeNoSmuT(t, n);
                         moveRet(inf, x, y);
                         insertSmuT(t, x, y, inf, RETANGULO, &calculabb);
                         break;
                    case CIRCULO:
                         fprintf(transf, "%i: Circulo\n\tx:%f\n\ty:%f\n\n", 
                                   getCircId(inf), getCircx(inf), getCircy(inf));
                         removeNoSmuT(t, n);
                         moveCirc(inf, x, y);
                         insertSmuT(t, x, y, inf, CIRCULO, &calculabb);
                         break;
                    case LINHA:
                         fprintf(transf, "%i: Linha\n\tx:%f\n\ty:%f\n\n", 
                                   getLinhaId(inf), getLinhax1(inf), getLinhay1(inf));
                         removeNoSmuT(t, n);
                         moveLinha(inf, x, y);
                         insertSmuT(t, x, y, inf, LINHA, &calculabb);
                         break;
                    case TEXTO:
                         fprintf(transf, "%i: Texto\n\tx:%f\n\ty:%f\n\n", 
                                   getTxtId(inf), getTxtx(inf), getTxty(inf));
                         removeNoSmuT(t, n);
                         moveTxt(inf, x, y);
                         insertSmuT(t, x, y, inf, TEXTO, &calculabb);
                         break;
                    default:
                         break;
               }
               fclose(transf);
          }else if(strcmp(comando, "cln")==0){
               int n;
               double dx, dy;
               fscanf(f, "%i" , &n);
               fscanf(f, "%lf" , &dx);
               fscanf(f, "%lf" , &dy);
               for(int i=0; getValor(listas, i); i++){
                    Selecao* sel=getValor(listas, i);
                    if(sel->n==n){
                         for(int i=0; getValor(sel->l, i); i++){
                              Node n=getValor(sel->l, i);
                              DescritorTipoInfo dt=getTypeInfoSrbT(t, n);
                              printf("clonando %i %i\n", dt, TEXTO);
                              Info i=getInfoSmuT(t, n);
                              double x, y;
                              switch (dt) {
                                   case RETANGULO:
                                        x=getRetX(i);
                                        y=getRetY(i);
                                        i=criaRetangulo(getRetId(i), x+dx, y+dy, 
                                                  getRetWidth(i), getRetHeight(i), getRetCorp(i), getRetCorb(i));

                                        break;
                                   case CIRCULO:
                                        x=getCircx(i);
                                        y=getCircy(i);
                                        i=criaCirculo(getCircId(i), x+dx, y+dy, getCircRaio(i), getCircCorp(i), getCircCorb(i));
                                        break;
                                   case LINHA:
                                        x=getLinhax1(i);
                                        y=getLinhay1(i);
                                        i=criaLinha(getLinhaId(i), x+dx, y+dy, getLinhax2(i)+dx, getLinhay2(i)+dy, getLinhaCor(i));
                                        break;
                                   case TEXTO:
                                        x=getTxtx(i);
                                        y=getTxty(i);
                                        i=criaTexto(getTxtId(i), x+dx, y+dy, getTxtCorp(i), getTxtCorb(i), getTxtPos(i), getTxt(i));
                                        break;
                                   default:
                                        break;
                              }
                              insertSmuT(t, x+dx, y+dy, i, dt, &calculabb);
                         }
                         continue;
                    }
               }
               
          }else if(strcmp(comando, "spy")==0){
               int id;
               fscanf(f, "%i" , &id);
               spy(t, id, spyfn);
          }else if(strcmp(comando, "cmflg")==0){
               int id;
               char corb[30];
               char corp[30];
               float w;
               fscanf(f, "%i" , &id);
               fscanf(f, "%s" , corb);
               fscanf(f, "%s" , corp);
               fscanf(f, "%f" , &w);
               spy(t, id, cmflgfn);
               Node n=procuraNoSmuT(t, &noComId, &id);
               if(n==NULL){
                    continue;
               }
               printf("acho o no\n");
               DescritorTipoInfo dt=getTypeInfoSrbT(t, n);
               Info inf=getInfoSmuT(t, n);
               switch (dt) {
                    case RETANGULO:
                         setRetColors(inf, corb, corp, w);
                         break;
                    case CIRCULO:
                         setCircColors(inf, corb, corp, w);
                         break;
                    case LINHA:
                         break;
                    case TEXTO:
                         setTxtColors(inf, corb, corp, w);
                         break;
                    default:
                         break;
               }
          }else if(strcmp(comando, "blow")==0){
               int id;
               fscanf(f, "%i" , &id);
               blow(t, id, saida);

          }

     }
     for (int i=0; getValor(listas, i); i++) {
          Selecao* sel=getValor(listas, i);
          killLista(sel->l);
          free(sel);
     }
     killLista(listas);

     fclose(f);
}
