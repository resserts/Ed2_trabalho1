#include "smutreap.h"

#include <stdlib.h>



SmuTreap newSmuTreap(int hitCount, double promotionRate, double epsilon){
     SmuTreap t;
     if(hitCount>=1){
          t.hitCount=hitCount;
     }
     if(promotionRate>0){
          t.promotionRate=promotionRate;
     }
     t.epsilon=epsilon;
     t.raiz=NULL;
     return t;
}

Node* criaNo(double x, double y, Info i, DescritorTipoInfo d){
     Node* n=(Node*)malloc(sizeof(Node));
     n->x=x;
     n->y=y;
     n->info=i;
     n->descritor=d;
     n->bb=NULL;
     n->dir=NULL;
     n->esq=NULL;
     return n;
}

bool igual(double x, double y, Node* r, double epsilon){
     if(fabs(x-y)<epsilon){
          return true;
     }else{
          return false;
     }
}

Node* insertAux(Smutreap* t, double x, double y, Node* r, Info i, DescritorTipoInfo d, Info bb){
     if(r==NULL){
          Node* n=criaNo(x, y, i, d);
          n->bb=bb;
          return n;
     }

     if(igual())
}

Node insertSmuT(SmuTreap *t, double x, double y, Info i, DescritorTipoInfo d){
     Node* r=t->raiz;
     Info bb=calculaBoundingBox(Info f, DescritorTipoInfo d);
     t->raiz=insertAux(t, x, y, r, i, d, bb);
}
