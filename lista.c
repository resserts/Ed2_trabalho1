#include "lista.h"
#include <stdlib.h>

typedef struct{
     void* inicio;
}StLista;

typedef struct aux{
     void* no;
     struct aux* prox;
}StElemento;

Lista criaLista(){
     StLista* l=(StLista*)malloc(sizeof(StLista));
     l->inicio=NULL;
     return l;
}
void killLista(Lista l){
     StLista* stl=(StLista*)l;
     StElemento* e=stl->inicio;
     while (e) {
          StElemento* aux=e->prox;
          free(e);
          e=aux;
     }
     free(stl);
}
void insertList(Lista l, void* node, int index){
     StElemento* e=(StElemento*)malloc(sizeof(StElemento));
     e->no=node;
     StLista* stl=(StLista*)l;
     StElemento* n=stl->inicio;
     if(index<=0 || n==NULL){
          e->prox=stl->inicio;
          stl->inicio=e;
          return;
     }
     for (int i=1; n->prox && i<index; i++) {
          n=n->prox;
     }

     e->prox=n->prox;
     n->prox=e;
}

void removeList(Lista l, int index){
     StLista* stl=(StLista*)l;
     StElemento* n=stl->inicio;
     if(n==NULL){
          return;
     }
     if(index<=0 || n->prox==NULL){
          stl->inicio=n->prox;
          free(n);
          return;
     }
     for (int i=1; n->prox && i<index; i++) {
          n=n->prox;
     }

     StElemento* e=n->prox->prox;
     free(n->prox);
     n->prox=e;
}

void* getValor(Lista l, int index){
     StLista* stl=(StLista*)l;
     StElemento* n=stl->inicio;
     if(n==NULL){
          return NULL;
     }
     if(index<=0){
          return n->no;
     }
     for (int i=1; n && i<index; i++) {
          n=n->prox;
     }
     if(n==NULL){
          return NULL;
     }

     return n->no;
}
