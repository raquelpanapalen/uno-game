#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "carta.h"
#include "cartas.h"
#include "jugador.h"
#include "jugadores.h"
#include "jugada.h"
#include "jugadas.h"
#include "partida.h"
#include "preguntas.h"
#include "colores.h"

void apodar_jugador(tjugador *j)
{
	char pregunta[20]="Tu nombre?";
	preguntar_cadena(pregunta, j->nombre);
}

