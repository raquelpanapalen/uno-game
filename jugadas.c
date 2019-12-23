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
#include "preguntas.h"
#include "partida.h"
/*
*Calcula las posibles jugadas usando las funciones de jugada_posible: 
->Con los parametros del color de la ultima carta o color escojido.
->Con la carta um(ultima del mazo de descartes).
 *Todo comparado con la mano del jugador introducido y guardado en el struct tjugadas pj(posibles jugadas).
*/
void calcular_jugadas_posibles(tjugadas *pj, int color,tcartas mano, tcarta um)
{
  int i, posible, hay_col;
	pj->njugadas=0;
	hay_col=hay_color(color, mano);
	if (hay_col==TRUE)
	{
		for(i=0;i<mano.nc;i++)
		{
			posible=jugada_posible_scolor(mano.cartas[i], um, color);
			if(posible==TRUE)
			{
				pj->jugs[pj->njugadas].carta=mano.cartas[i];
				pj->jugs[pj->njugadas].pos=i;
				pj->njugadas++;
			}
		}
	}
	else
	{
		for(i=0;i<mano.nc;i++)
		{
			posible=jugada_posible_ncolor(mano.cartas[i], um);
			if(posible==TRUE)
			{
				pj->jugs[pj->njugadas].carta=mano.cartas[i];
				pj->jugs[pj->njugadas].pos=i;
				pj->njugadas++;
			}
		}
	}
}
/*
*return TRUE si encuntra una carta en la mano del jugador que tenga el color introducido.  
*return FALSE si no se encuentra ninguna coincidencia de color. 
*/
int hay_color(int color, tcartas mano)
{
	int encontrado=FALSE, i=0;
	while (i<mano.nc && encontrado==FALSE)
	{
		if (mano.cartas[i].color==color)
			encontrado=TRUE;
		else
			i++;
	}
	return encontrado;
}	
/*
*Muestra el vector de pj(posibles jugadas).
*/	
void mostrar_jugadas(tjugadas pj)
{
	int i; 
	for(i=0;i<pj.njugadas;i++)
	{
		printf("%d(",i);
		mostrar_carta(pj.jugs[i].carta, TRUE);
		printf("|) ");
	}
	printf("   ");
}
/*
*return TRUE si hay alguna jugada posible en la mano del jugador.
*return FALSE si hay ninguna jugada posible en la mano del jugador.
*/
int hay_jugadas(tcartas mano, tcarta um, int color)
{
	int i=0, encontrada=FALSE;
	encontrada=hay_color(color, mano);
	while (i<mano.nc && encontrada!=TRUE)
	{
		encontrada=jugada_posible_ncolor(mano.cartas[i], um);
		i++;
	}
	return encontrada;
}
/*
*tipo_jug==0(caso de la persona real)->return la carta escojida por el jugador entre las jugadas posibles.
*tipo_jug!=0(caso del robot) -> return una carta aleatoria entre las jugadas posibles.
*/
tcarta elegir_jugada(int tipo_jug, tjugadas jugadas)
{
	int pos;
	tcarta elegida;
	if (tipo_jug==0)
	{
		printf("\n");
		pos=preguntar_n_en_rango("Que carta tiras?", 0, jugadas.njugadas-1);
	}
	else
		pos=(rand()%(jugadas.njugadas));
	
	elegida=jugadas.jugs[pos].carta;	
	return elegida;
}

