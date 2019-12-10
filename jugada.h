#ifndef JUGADA_H
#define JUGADA_H
#define TRUE 1
#define FALSE 0

typedef struct
{
   int pos;
   tcarta carta;
}tjugada;

int jugada_posible(tcarta c, tcarta um, int color);


#endif
