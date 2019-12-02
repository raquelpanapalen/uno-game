#include <stdio.h>
#include "carta.h"
#include "cartas.h"
#include "jugador.h"
#include "preguntas.h"
#include "colores.h"

void apodar_jugador(tjugador *j)
{
	char pregunta[20]="Tu nombre?";
	preguntar_cadena(pregunta, j->nombre);
}

