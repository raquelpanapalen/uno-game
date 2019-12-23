#ifndef JUGADOR_H
#define JUGADOR_H
#define MN 20
#define TRUE 1
#define FALSE 0

typedef struct
{
   char nombre[MN];//guarda el nombre del jugador en un vector de char.
   tcartas mano;//guarda la mano del jugador en un struct tipo tcartas.
}tjugador;

void apodar_jugador(tjugador *j);

#endif
