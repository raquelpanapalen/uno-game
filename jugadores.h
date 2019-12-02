#ifndef CARTA_H
#define CARTA_H
#define MJ 5
#define TRUE 1
#define FALSE 0 

typedef struct
{
   int num_jug;
   tjugador lista_jug[MJ];
}tjugadores;


void inicializar_jugadores(tjugadores *lj);//inicializar jugadores
void estado_jugadores(tjugadores lj);//imprime estado jugadores


#endif
