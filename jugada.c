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
*return TRUE si: 
->el color de la carta um(ultima mazo de descartes) o el escojido coinciden con la carta c.
->si la figura coincide de la carta um(ultima mazo de descartes) con la de la carta c, siempre que no sea un W+4. 
->si la figura de la carta c es un W.
*return FALSE si no se cumple ningún requisito anterior. 
*/
int jugada_posible_scolor(tcarta c, tcarta um, int color)
{
	int posible;
	if (c.color==color || (c.fig==um.fig && c.fig!=14) || c.fig==13)
		posible=TRUE;
	else
		posible=FALSE;
  return posible;
}
/*
*return TRUE si:
->si la figura de la carta um(ultima mazo de descartes) coincide con la de la carta c, siempre que no sea un W+4. 
->si la figura de la carta c es un W o un W+4.
*return FALSE si no se cumple ningún requisito anterior. 
*/
int jugada_posible_ncolor(tcarta c, tcarta um)
{
	int posible;
	if ((c.fig==um.fig && c.fig!=14) || c.fig>=13)
		posible=TRUE;
	else
		posible=FALSE;
  return posible;
}

