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
#include "partida.h"
#include "preguntas.h"


void calcular_jugadas_posibles(tjugadas *pj,tcarta um,tcartas mano, tpartida p)
{
  int i;
	pj->njugadas=0;
	for(i=0;i<mano.nc;i++)
  {
		if(um.fig==mano.cartas[i].fig || p.color==mano.cartas[i].color || mano.cartas[i].fig=13)
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

void realizar_jugada(tcartas *mazo,tjugadas pj)
{
  int i,elec;
  char p[MAX_CAD]="Que cartas tiras? ";
  elec=preguntar_n_en_rango(p, 0,pj.njugadas-1);
  for(i=mazo->nc+1;i>0;i--)
  {
    mazo->cartas[i+1]=mazo->cartas[i];
  }
  mazo->cartas[1]=pj.jugs[elec].carta;
  mazo->nc++;
}

void realizar_jugada_robots(tcartas *mazo, tjugadas pj)
{
	int i, elec;
	elec=(rand() % (pj.njugadas-1));
	for (i=mazo->nc +1; i>0; i--)
	{
		mazo->cartas[i+1]=mazo->cartas[i];
	}
	mazo->cartas[1]=pj.jugs[elec].carta;
	mazo->nc++;
}

