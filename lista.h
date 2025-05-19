#ifndef LISTA_H
#define LISTA_H

typedef struct{
     void* prox;
}Lista;

void insertList(Lista l, void* node);

#endif
