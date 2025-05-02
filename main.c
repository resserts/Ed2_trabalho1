#include "smutreap.h"

#include <stdlib.h>

int main(){
     SmuTreap s=newSmuTreap(3, 1.1, 0.0001);
     insertSmuT(s, 1, 2, NULL, 1);
     insertSmuT(s, 5, 2, NULL, 1);
     insertSmuT(s, 2, 2, NULL, 1);
     insertSmuT(s, 7, 2, NULL, 1);
     insertSmuT(s, 7, 1, NULL, 1);

     return 0;
}
