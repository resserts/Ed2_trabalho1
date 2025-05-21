#include "retangulo.h"
#include "circulo.h"
#include "linha.h"
#include "svg.h"
#include "texto.h"
#include "smutreap.h"

#include <stdio.h>
#include <stdlib.h>

void calcbb(DescritorTipoInfo tp, Info i, double *x, double *y, double *w, double *h){
     return;
}


int main(int argc, char* argv[]){
     SmuTreap s=newSmuTreap(3, 1.1, 0.001);
     insertSmuT(s, 1, 2, criaRetangulo(1, 10, 10, "blue", "black"), RETANGULO, &calcbb);
     insertSmuT(s, 5, 2, NULL, 10, &calcbb);
     insertSmuT(s, 2, 2, NULL, 10, &calcbb);
     insertSmuT(s, 7, 2, NULL, 10, &calcbb);
     insertSmuT(s, 7, 1, NULL, 10, &calcbb);
     insertSmuT(s, 1, 3, NULL, 10, &calcbb);
     insertSmuT(s, 5, 1, NULL, 10, &calcbb);
     insertSmuT(s, 2, 5, NULL, 10, &calcbb);
     insertSmuT(s, 7, 3, NULL, 10, &calcbb);
     insertSmuT(s, 7, 9, criaTexto(2, "black", "black", 'm', "teste"), TEXTO, &calcbb);
     printDotSmuTreap(s, "antes.dot");
     removeNoSmuT(s, getNodeSmuT(s, 2, 2));
     printDotSmuTreap(s, "depois.dot");

     gerarSvg(s, "teste.svg");

     return 0;
}
