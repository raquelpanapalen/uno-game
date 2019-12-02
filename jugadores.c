#include <stdio.h>
#include "carta.h"
#include "cartas.h"
#include "jugador.h"
#include "preguntas.h"
#include "jugadores.h"
#include "colores.h"

void inicializar_jugadores(tjugadores *lj)
{
	char preg[MAX_CAD]="Cuantos jugadores?";
	int min=3, max=5;
	lj->num_jug=preguntar_n_en_rango(preg, min, max);
	apodar_jugador(&lj->lista_jug[0]);
}
