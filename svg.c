#include "svg.h"
#include "retangulo.h"
#include "circulo.h"
#include "linha.h"
#include "texto.h"
#include "smutreap.h"
#include <string.h>
#include <stdio.h>



void svgNo(SmuTreap t, Node n, Info i, double x, double y, void *aux){
     DescritorTipoInfo tipo=getTypeInfoSrbT(t, n);
     switch (tipo) {
          case RETANGULO:
               fprintf(aux, "<rect x=\"%f\" y=\"%f\" width=\"%f\" height=\"%f\" stroke=\"%s\" fill=\"%s\" />\n",
                         x, y, getRetWidth(i), getRetHeight(i), getRetCorb(i), getRetCorp(i));
               break;
          case CIRCULO:
               fprintf(aux, "<circle x=\"%f\" y=\"%f\" r=\"%f\" stroke=\"%s\" fill=\"%s\" />\n",
                         x, y, getCircRaio(i), getRetCorb(i), getRetCorp(i));
               break;
          case LINHA:
               fprintf(aux, "<line x1=\"%f\" y1=\"%f\" x2=\"%f\" y2=\"%f\" stroke=\"%s\" />\n",
                         x, y, getLinhax2(i), getLinhay2(i), getLinhaCor(i));
               break;
          case TEXTO:
               char* fontWeight=getTxtWeight(i);
               if(strcmp(fontWeight, "n")){
                    fontWeight="normal";
               }else if(strcmp(fontWeight, "b")){
                    fontWeight="bold";
               }else if(strcmp(fontWeight, "b+")){
                    fontWeight="bolder";
               }else if(strcmp(fontWeight, "l")){
                    fontWeight="lighter";
               }

               fprintf(aux, "<text x=\"%f\" y=\"%f\" stroke=\"%s\" fill=\"%s\" font-family=\"%s\" font-size=\"%i\" font-weight=\"%s\" >%s</text>\n",
                         x, y, getTxtCorb(i), getTxtCorp(i), getTxtFamily(i), 
                         getTxtSize(i), getTxtWeight(i), getTxt(i));
               break;
          default:
               break;
     }
}
void gerarSvg(SmuTreap t, char* fn){
     FILE* f=fopen(fn, "w");
     if(f==NULL){
          return;
     }

     fprintf(f, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n");
     fprintf(f, "<svg version=\"1.1\" xmlns=\"[http://www.w3.org/2000/svg](http://www.w3.org/2000/svg)\">\n");

     visitaProfundidadeSmuT(t, &svgNo, f);

     fprintf(f, "</svg>\n"); 
}
