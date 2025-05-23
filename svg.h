#ifndef _SVG_H
#define _SVG_H

#include "smutreap.h"
#include "retangulo.h"
#include "circulo.h"
#include "linha.h"
#include "texto.h"

enum tipo{RETANGULO, CIRCULO, LINHA, TEXTO};

void gerarSvg(SmuTreap t, char* fn);

#endif
