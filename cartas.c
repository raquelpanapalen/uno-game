#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "carta.h"
#include "cartas.h"
#include "jugador.h"
#include "jugadores.h"
#include "colores.h"

void inicializar_cartas(tcartas *lc)
{
	int pos, i, j, c;
	tcarta aux;
	lc->nc=108;
	pos=0;
	for (c=1; c<=4; c++)
	{
		lc->cartas[pos].color=c;
		lc->cartas[pos].fig=0;
		pos++;
		for (i=0; i<2; i++)
		{
			for (j=1; j<=12; j++)
			{
				lc->cartas[pos].color=c;
				lc->cartas[pos].fig=j;
				pos++;
			}
		}
	}
	for (i=0; i<8; i++)
	{
		lc->cartas[pos].color=0;
		if (i<4)
		{
			lc->cartas[pos].fig=13;
		}
		else
		{
			lc->cartas[pos].fig=14;
		}
		pos++;
	}
}
void mezclar_cartas(tcartas *lc)
{
	int i, pos=0;
	tcarta aux;
	srand (time(NULL)); 
	for (i=0; i<108; i++)
	{
		pos=(rand() % (108));
		aux=lc->cartas[i];
		lc->cartas[i]=lc->cartas[pos];
		lc->cartas[pos]=aux;
	}
}
void mostrar_mazo(tcartas lc, int conf)
{
	int i, j;
	printf("Mazo:\n|");
	if (conf==TRUE)
	{
	  for (i=0; i<lc.nc; i++)
	  {
			mostrar_carta(lc.cartas[i]);
  		printf("|");
			if ((i+1)%20 == 0)
			{
				printf("\n");
				printf(" ");
				for (j=0; j<20; j++)
				{
					printf("---+");
				}
				printf("\n");
				printf("|");
			}
		}
	}
	else
	{
		cambiar_color_fondo(WHITE);
  	cambiar_color_letra(RED);
		printf("UNO");
		default_attributes();
		printf("|(%d)",lc.nc);
	}
  printf("\n");
}
void mostrar_cartas(tcartas lc,int conf)
{
	int i, j;
	printf("|");
	for (i=0; i<lc.nc; i++)
	{
		if (conf==TRUE)
			mostrar_carta(lc.cartas[i]);
		else
		{
			cambiar_color_fondo(WHITE);
			cambiar_color_letra(RED);
			printf("UNO");
			default_attributes();
		}
  	printf("|");
  	if ((i+1)%20 == 0)
  	{
  		printf("\n");
  		printf(" ");
  		for (j=0; j<20; j++)
  		{
  			printf("---+");
  		}
  		printf("\n");
  		printf("|");
  	}
  }
  printf("\n");
}
void repartir_cartas(int numcart, tcartas *mano, tcartas *lc)
{
	int i, j;
	
	for (i=0; i<numcart; i++)
	{
		mano->cartas[mano->nc]=lc->cartas[i];
		mano->nc++;
		for (j=0; j<lc->nc-1; j++)
		{
			lc->cartas[j]=lc->cartas[j+1];
		}
		lc->nc--;
	}
}
/*
int buscar_carta(tcarta c, tcartas lc)
{
}
void eliminar_cartas(int pos, tcartas *lc)
{
}
int posible_carta(tcarta c1, tcarta c2);//verifica si se puede colocar carta c1 sobre carta c2(return: FALSE no se puede y TRUE se puede)

void tirar_carta(tcarta c,tcartas *mazo);//pasar carta c de mano del jugador a mazo de descartes
int ultima_carta(tcartas mano);//contar el numero de cartas de la mano(si es la ultima return=TRUE y sino es la ultima return=FALSE)
void recuperar_cartas(tcartas *mazo, tcartas *lc);//una vez se acaban las cartas de lc, se recuperan del mazo de descartes

*/

