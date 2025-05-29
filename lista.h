#ifndef LISTA_H
#define LISTA_H

typedef void* Lista;
typedef void* Elemento;

Lista criaLista();
// cria uma lista vazia.

void killLista(Lista l);
// Libera o espaço ocupado pela lista e seus elementos da lista mas não dos nós aos quais eles apontavam.

void insertList(Lista l, void* node, int index);
/* Insere um elemento que aponta para node na lista l, na posicao index caso ela exista,em caso contrário
 * no fim se for um valor positivo e no início se for um valor negativo.
*/

void removeList(Lista l, int index);
/* Remove o elemento na lista l, na posicao index caso ela exista,em caso contrário
 * no fim se for um valor positivo e no início se for um valor negativo.
*/

void* getValor(Lista l, int index);
/* Retorna o no apontado pelo elemento na posição index, caso exista, ou no início se for um valor negativo.
*/

#endif
