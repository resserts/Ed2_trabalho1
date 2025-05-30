#ifndef _SVG_H
#define _SVG_H

#include "smutreap.h"
#include "retangulo.h"
#include "circulo.h"
#include "linha.h"
#include "texto.h"

enum tipo{RETANGULO, CIRCULO, LINHA, TEXTO};
typedef void* Letra;

Letra criaLetra(double x, double y, char l);
// Retorna um ponteiro para uma Letra l com posição=(x,y).

void gerarSvg(SmuTreap t, char* fn, Lista letras);
// Gera o svg fn usando as formas na SmuTreap t e a lista letras, caso não seja nula.

#endif
