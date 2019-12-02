#ifndef JUGADOR_H
#define JUGADOR_H
#define MN 20
#define TRUE 1
#define FALSE 0

typedef struct
{
   char nombre[MN];
   tcartas mano;
}tjugador;


tcarta seleccionar_jugada();//elegir opcion desde teclado y return tcarta escojida
void apodar_jugador(tjugador *j);//definir el nombre del jugador
void estado_jugador(tjugador j);//imprime estado jugador j

#endif
