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
/*
*Apoda al jugador real pidiendo el nombre por teclado mediante la función preguntar_cadena. 
*/
void apodar_jugador(tjugador *j)
{
	preguntar_cadena("Tu nombre? ", j->nombre);
}

