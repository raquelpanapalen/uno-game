#ifndef CARTA_H
#define CARTA_H
#define TRUE 1
#define FALSE 0
typedef struct
{
   int color;//guarda el color de una carta de 0 a 4.
   int fig;//guarda la figura de la carta de 0 a 14.
}tcarta;

void mostrar_carta(tcarta c, int conf);

#endif
