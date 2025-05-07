#include "smutreap.h"

#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>
#include <math.h>


typedef struct{
     double x, y, h, w;
}StBb;

typedef struct aux{
     int prioridade;
     double x,y;
     Info info;
     DescritorTipoInfo descritor;
     Info bbinfo;
     Info bbsa;
     struct aux* dir;
     struct aux* esq;
}StNode;
typedef struct {
     int hitCount;
     double promotionRate;
     double epsilon;
     StNode* raiz;
}StSmutreap;

SmuTreap newSmuTreap(int hitCount, double promotionRate, double epsilon){
     srand(time(NULL));
     StSmutreap* t=(StSmutreap*)malloc(sizeof(StSmutreap));
     if(hitCount>=1){
          t->hitCount=hitCount;
     }
     if(promotionRate>0){
          t->promotionRate=promotionRate;
     }
     t->epsilon=epsilon;
     t->raiz=NULL;
     printf("Smutreap criada\n");
     return t;
}

Node criaNo(double x, double y, Info i, DescritorTipoInfo d){
     StNode* n=(StNode*)malloc(sizeof(StNode));
     n->prioridade=rand()%100;
     n->x=x;
     n->y=y;
     n->info=i;
     n->descritor=d;
     n->bbinfo=NULL;
     n->bbsa=NULL;
     n->dir=NULL;
     n->esq=NULL;
     return n;
}

int getPrioridade(StNode* r){
     if(r!=NULL){
          return r->prioridade;
     }
     return 0;
}

bool igual(double x, double y, StNode* r, double epsilon){
     if(fabs(x-r->x)<epsilon && fabs(y-r->y)<epsilon){
          return true;
     }else{
          return false;
     }
}
bool menor(double x, double y, StNode* r, double epsilon){
     if(x<r->x){
          return true;
     }else if(fabs(x-r->x)<epsilon && y<r->y){
          return true;
     }else{
          return false;
     }
}

StNode* rotaDireita(StNode* r){
     StNode* q=r->esq;
     StNode* aux=q->dir;
     q->dir=r;
     r->esq=aux;
     return q;
}
StNode* rotaEsquerda(StNode* r){
     StNode* q=r->dir;
     StNode* aux=q->esq;
     q->esq=r;
     r->dir=aux;
     return q;
}

StNode* rebalanceie(StNode* r){
     int prioE = getPrioridade(r->esq);
     int prioD = getPrioridade(r->dir);
     int prioR = getPrioridade(r);
     int maxPrioFilhos=(prioD>prioE) ? prioD : prioE;
     if(prioR>=maxPrioFilhos){
          return r;
     }

     StNode* nr;
     if(prioE>prioD){
          nr=rotaDireita(r);
     }else{
          nr=rotaEsquerda(r);
     }
     printf("retorno %d\n", nr->prioridade);
     return nr;
}

void simetrica(StNode* raiz){
    if(raiz->esq!=NULL){
        simetrica(raiz->esq);
    }
    printf("%f, %f| |", raiz->x, raiz->y);
    if(raiz->dir!=NULL){
        simetrica(raiz->dir);
    }
}
Node insertAux(StSmutreap* t, double x, double y, StNode* r, Info i, DescritorTipoInfo d){
     if(r==NULL){
          StNode* n=criaNo(x, y, i, d);
          printf("%d\n", n->prioridade);
          return n;
     }
     
     StNode* nr=r;
     if(igual(x, y, r, t->epsilon)){
          printf("entro igual\n");
          return r;
     }else if(menor(x, y, r, t->epsilon)){
          nr = insertAux(t, x, y, r->esq, i, d);
          r->esq=nr;
          printf("menor: %d(%f, %f) < %d(%f, %f)\n", nr->prioridade, nr->x, nr->y, r->prioridade, r->x, r->y);
     }else{
          nr = insertAux(t, x, y, r->dir, i, d);
          r->dir=nr;
          printf("maior: %d(%f, %f)\n", nr->prioridade, nr->x, nr->y);
     }
     

     nr=rebalanceie(r);
     return nr;
}

Node insertSmuT(SmuTreap t, double x, double y, Info i, DescritorTipoInfo d, FCalculaBoundingBox fCalcBb){
     StSmutreap* treap=t;
     StNode* r=treap->raiz;
     treap->raiz=insertAux(treap, x, y, r, i, d);
     simetrica(treap->raiz);
     printf("\nraiz: %d\n", treap->raiz->prioridade);
}

int printSmuAux(StNode* n, FILE* f, int* index){
     if(n==NULL){
          return 0;
     }
     *index=(*index)+1;
     int nIndex=*index;
     fprintf(f, "\tn%d[label=\"%d\nx=%f, y=%f\"];\n", nIndex, n->prioridade, n->x, n->y);
     int i;
     if(i=printSmuAux(n->esq, f, index)){
          fprintf(f, "\tn%d->n%d;\n", nIndex, i);
     }
     if(i=printSmuAux(n->dir, f, index)){
          fprintf(f, "\tn%d->n%d;\n", nIndex, i);
     }

     return nIndex;
}
bool printDotSmuTreap(SmuTreap t, char *fn){
     FILE* f = fopen(fn, "w");
     if(f==NULL){
          return false;
     }

     StSmutreap* treap=(StSmutreap*)t;
     fprintf(f, "digraph \"\"\n{\n");
     int i=0;
     printSmuAux(treap->raiz, f, &i);
     fprintf(f, "}");

     fclose(f);
     return true;
}


