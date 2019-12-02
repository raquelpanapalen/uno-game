#ifndef JUGADORES_H
#define JUGADORES_H
#define MJ 5
#define TRUE 1
#define FALSE 0 

typedef struct
{
   int num_jug;
   tjugador lista_jug[MJ];
}tjugadores;

void inicializar_jugadores(tjugadores *lj);
void estado_jugadores(tjugadores lj);//imprime estado jugadores


#endif
