#include "retangulo.h"
#include "circulo.h"
#include "linha.h"
#include "svg.h"
#include "texto.h"
#include "smutreap.h"
#include "geo.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void calcbb(DescritorTipoInfo tp, Info i, double *x, double *y, double *w, double *h){
     return;
}


int main(int argc, char* argv[]){
     SmuTreap s=newSmuTreap(3, 1.1, 0.001);
     printf("argc: %i\n", argc);
     for(int i=1; i<argc; i++){
          printf("i: %i\n", i);
          printf("argv[i]: %s\n", argv[i]);
          if(strcmp(argv[i], "-f")==0){
               printf("entro comandos\n");
               i++;
               comandosGeo(s, argv[i]);
          }
     }
     printDotSmuTreap(s, "antes.dot");
     printDotSmuTreap(s, "depois.dot");

     gerarSvg(s, "teste.svg");

     return 0;
}
