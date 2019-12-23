#ifndef JUGADORES_H
#define JUGADORES_H
#define MJ 5
#define TRUE 1
#define FALSE 0 

typedef struct
{
   int num_jug;//guarda el número de jugadores.
   tjugador lista_jug[MJ];//guarda los jugadores en un vector de tipo tjugador.
}tjugadores;

void inicializar_jugadores(tjugadores *lj);
void mostrar_estado_jugadores(tjugadores lj, int conf);



#endif
