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
* Inicializa las 108 cartas en lc(lista de cartas) de manera como marcan las normas del uno.
*/
void inicializar_cartas(tcartas *lc)
{
	int pos, i, j, c;
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
/*
*Mezcla las cartas aleatoriamente haciendo intercambios de las cartas en orden con otras escojidas al azar.
*/
void mezclar_cartas(tcartas *lc)
{
	int i, pos=0;
	tcarta aux;
	for (i=0; i<lc->nc; i++)
	{
		pos=(rand() % (lc->nc));
		aux=lc->cartas[i];
		lc->cartas[i]=lc->cartas[pos];
		lc->cartas[pos]=aux;
	}
}
/*
*si conf==1 Muestra lc(lista de cartas) en filas de 20 cartas y hace los saltos de línea automáticos cuando sobrepasa los 20.
*si conf==0 Muestra |UNO| y a continuación el número de cartas que quedan en lc.
*/
void mostrar_mazo(tcartas lc, int conf)
{
	int i, j;
	printf("Mazo:\n");
	if (conf==TRUE)
	{
	  for (i=0; i<lc.nc; i++)
	  {
			mostrar_carta(lc.cartas[i], TRUE);
			if ((i+1)%20 == 0)
			{
				printf("|\n");
				printf(" ");
				for (j=0; j<20; j++)
				{
					printf("---+");
				}
				printf("\n");
			}
		}
		if (i%20<20 && i%20!=0)
  	printf("|");
	}
	else
	{
		mostrar_carta(lc.cartas[lc.nc-1], FALSE);
		printf("|(%d)",lc.nc);
	}
  printf("\n");
}
/*
*Muestra la ultima carta del mazo de descartes y el sentido en el qual se realiza el paso de turno. 
*Aparte de esto aparece el color que se ha escojido en el caso de que la ultima carta sea un W o W+4.
*/
void mostrar_mazo_descartes(tcartas mazo, int sentido, int color)
{
	printf("Mazo Descartes:\n");
	mostrar_carta(mazo.cartas[mazo.nc-1], TRUE);
	printf("|(%d) ", mazo.nc);
	if (mazo.cartas[mazo.nc-1].fig>=13)
	{
		printf("Color escogido: |");
		cambiar_color_fondo(color);
		printf("   ");
		default_attributes();
		printf("| ");		
	}
	printf("Sentido: ");
	cambiar_color_letra(BLUE);
	if (sentido==HORARIO)
		printf("HORARIO\n");
	else
		printf("ANTIHORARIO\n");
	default_attributes();
}		
/*
*si conf==1-->Muestra la mano del jugador en filas de 20 cartas y hace los saltos de línea automáticos cuando sobrepasa los 20.
*si conf==0-->Muestra la cantidad de cartas del jugador pero aparece |UNO| envez de la cartas.
*/
void mostrar_cartas(tcartas lc,int conf)
{
	int i, j;
	for (i=0; i<lc.nc; i++)
	{
		mostrar_carta(lc.cartas[i], conf);
  	if ((i+1)%20 == 0)
  	{
  		printf("|\n");
  		printf(" ");
  		for (j=0; j<20; j++)
  		{
  			printf("---+");
  		}
  		printf("\n");

  	}
  }
  if (i%20<20 && i%20!=0)
  	printf("|");

}
/*
*si hay suficientes cartas para robar en lc, mueve numcart cartas a la mano introducida.
*si no hay suficiente cartas para robar en lc, primero mueve todas menos la ultima carta del mazo de descartes a lc(utilizando la función recuperar cartas) y a continuación mueve numcart de lc a mano.
*/
void robar_cartas(int numcart, tcartas *mano, tcartas *lc, tcartas *mazo)
{
	int i, j;
	for (i=0; i<numcart; i++)
	{
		mano->cartas[mano->nc]=lc->cartas[0];
		mano->nc++;
		for (j=0; j<lc->nc-1; j++)
		{
			lc->cartas[j]=lc->cartas[j+1];
		}
		lc->nc--;
		if(lc->nc<=0)
		{
			recuperar_cartas(mazo, lc);
			mezclar_cartas(lc);
		}
	}
}
/*
*Inicializa la mano del jugador introducido con 7 cartas moviendolas de lc.
*/
void inicializar_mano(tcartas *mano, tcartas *lc)
{
	int i, j;
  mano->nc=0;
	for (i=0; i<7; i++)
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
*Busca la primera carta de lc que no es especial y la mueve a la última posición del mazo de descartes.
*/
void inicializar_mazo_descartes(tcartas *mazo, tcartas *lc)
{
	int i=0, pos;
	mazo->nc=1;
	while (lc->cartas[i].fig>9)
	{
		i++;
	}
	if (lc->cartas[i].fig<=9)
	{
		mazo->cartas[0]=lc->cartas[i];
		pos=i;
	}
	for (i=pos; i<lc->nc-1; i++)
	{
		lc->cartas[i]=lc->cartas[i+1];
	}
	lc->nc=lc->nc-1;
}	
/*
*return TRUE si solo le queda una carta a la mano del jugador.
*return FALSE si le queda mas de una carta a la mano del jugador.
*/
int ultima_carta(tcartas mano)
{
	int ultima=FALSE;
	if (mano.nc==1)
		ultima=TRUE;
		
	return ultima;
}
/*
*return posicion de la carta c en la mano del jugador.
*/
int buscar_carta(tcarta c, tcartas mano)
{
	int i=0, pos;
	while (mano.cartas[i].fig != c.fig || mano.cartas[i].color != c.color)
	{
		i++;
	}
	if (mano.cartas[i].fig == c.fig && mano.cartas[i].color == c.color)
		pos=i;
	
	return pos;
}
/*
*Elimina la carta en la posicion pos de la mano del jugador introducido.
*/
void eliminar_cartas(int pos, tcartas *mano)
{
	int i;
	for (i=pos; i<mano->nc-1; i++)
	{
		mano->cartas[i]=mano->cartas[i+1];
	}
	mano->nc=mano->nc-1;
}
/*
*Copiar la carta c en la última posición del mazo de descartes.
*/
void tirar_carta(tcarta c,tcartas *mazo)
{
	mazo->cartas[mazo->nc]=c;
	mazo->nc+=1;
}
/*
*Pasar todas las cartas menos la ultima del mazo de descartes a lc.
*/
void recuperar_cartas(tcartas *mazo, tcartas *lc)
{
	int i,j;
	
	for (i=0; i<mazo->nc-1; i++)
	{
		lc->cartas[lc->nc]=mazo->cartas[i];
		lc->nc++;
	}
	j=mazo->nc-1;
	for (i=0; i<j; i++)
	{
		eliminar_cartas(0, mazo);
	}

}
	
	



