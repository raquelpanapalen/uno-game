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

void mostrar_carta(tcarta c, int conf)
{
	printf("|");
	if (conf==TRUE)
	{
		cambiar_color_fondo(c.color);
			if (c.fig<=9)
				printf(" %d ", c.fig);
			else if (c.fig==10)
				printf("+2 ");
			else if (c.fig==11)
				printf(" R ");
			else if (c.fig==12)
				printf(" S ");
			else if (c.fig==13)
			{
				cambiar_color_letra(BLACK);
				printf(" W ");
			}
			else
			{
				cambiar_color_letra(BLACK);
				printf("W+4");
			}
	}
	else
	{
		cambiar_color_fondo(WHITE);
  	cambiar_color_letra(RED);
		printf("UNO");
	}
	default_attributes();
}


