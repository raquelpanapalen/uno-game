#ifndef CARTA_H
#define CARTA_H
#define TRUE 1
#define FALSE 0
typedef struct
{
   int color;
   int fig;
}tcarta;

void mostrar_carta(tcarta c, int conf);

#endif
