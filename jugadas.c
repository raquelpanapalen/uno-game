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


void calcular_jugadas_posibles(tjugadas *pj,tcarta um,tcartas mano)
{
  int i;
	pj->njugadas=0;
	for(i=0;i<mano.nc;i++)
  {
		if(um.fig==mano.cartas[i].fig || um.color==mano.cartas[i].color)
		{
		  pj->jugs[pj->njugadas].carta=mano.cartas[i];
		  pj->jugs[pj->njugadas].pos=i;
		  pj->njugadas++;
		}
	}
}
void mostrar_jugadas(tjugadas pj)
{
	int i; 
	for(i=0;i<pj.njugadas;i++)
	{
		printf("%d(|",i);
		mostrar_carta(pj.jugs[i].carta);
		printf("|) ");
	}
}

int hay_jugadas(tcartas mano, tcarta um)
{
	int i=0, encontrada=FALSE;
	while (encontrada==FALSE)
	{
		if(um.fig==mano.cartas[i].fig || um.color==mano.cartas[i].color)
			encontrada=TRUE;
		i++;
	}
	return encontrada;
}

tcarta elegir_jugada(int tipo_jug, tjugadas jugadas)
{
	char preg[MAX_CAD]="Que carta tiras?";
	int pos;
	tcarta elegida;
	if (tipo_jug==0)
	{
		printf("\n");
		pos=preguntar_n_en_rango(preg, 0, jugadas.njugadas-1);
		printf("\n");
	}
	else
		pos=(rand()%(jugadas.njugadas));
	
	elegida=jugadas.jugs[pos].carta;	
	return elegida;
}

