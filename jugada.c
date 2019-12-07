#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "carta.h"
#include "cartas.h"
#include "jugador.h"
#include "jugadores.h"
#include "jugada.h"
#include "jugadas.h"
#include "colores.h"

int jugada_posible(tcarta c, tcarta um)
{
	int posible;
	if (c.color==um.color || c.fig==um.fig)
		posible=TRUE;
	else
		posible=FALSE;
  return posible;
}

