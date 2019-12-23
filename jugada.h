#ifndef JUGADA_H
#define JUGADA_H
#define TRUE 1
#define FALSE 0

typedef struct
{
   int pos;//guarda la posición de la carta jugada en la mano.
   tcarta carta;//guara la carta jugada.
}tjugada;

int jugada_posible_scolor(tcarta c, tcarta um, int color);
int jugada_posible_ncolor(tcarta c, tcarta um);

#endif
