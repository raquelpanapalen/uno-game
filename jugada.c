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

int jugada_posible_scolor(tcarta c, tcarta um, int color)
{
	int posible;
	if (c.color==color || (c.fig==um.fig && c.fig!=14) || c.fig==13)
		posible=TRUE;
	else
		posible=FALSE;
  return posible;
}

int jugada_posible_ncolor(tcarta c, tcarta um)
{
	int posible;
	if ((c.fig==um.fig && c.fig!=14) || c.fig>=13)
		posible=TRUE;
	else
		posible=FALSE;
  return posible;
}

