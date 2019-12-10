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

int jugada_posible(tcarta c, tcarta um, int color)
{
	int posible;
	if (c.color==color || c.fig==um.fig)
		posible=TRUE;
	else
		posible=FALSE;
  return posible;
}

