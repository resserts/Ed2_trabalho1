#include "smutreap.h"

#include <stdio.h>
#include <stdlib.h>

void calcbb(DescritorTipoInfo tp, Info i, double *x, double *y, double *w, double *h){
     return;
}

int main(){
     SmuTreap s=newSmuTreap(3, 1.1, 0.001);
     insertSmuT(s, 1, 2, NULL, 1, &calcbb);
     insertSmuT(s, 5, 2, NULL, 1, &calcbb);
     insertSmuT(s, 2, 2, NULL, 1, &calcbb);
     insertSmuT(s, 7, 2, NULL, 1, &calcbb);
     insertSmuT(s, 7, 1, NULL, 1, &calcbb);
     printDotSmuTreap(s, "arq.dot");

     return 0;
}
