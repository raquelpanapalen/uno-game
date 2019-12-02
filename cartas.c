#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "carta.h"
#include "cartas.h"
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
/*void mostrar_cartas(tcartas lc,int conf)
{
}
int buscar_carta(tcarta c, tcartas lc)
{
}
void eliminar_cartas(int pos, tcartas *lc)
{
}
int posible_carta(tcarta c1, tcarta c2);//verifica si se puede colocar carta c1 sobre carta c2(return: FALSE no se puede y TRUE se puede)
void repartir_cartas(int nc, tcartas *mano, tcartas *lc);//pasa las primeras nc cartas de lc a mano(inicializar juego)

void tirar_carta(tcarta c,tcartas *mazo);//pasar carta c de mano del jugador a mazo de descartes
int ultima_carta(tcartas mano);//contar el numero de cartas de la mano(si es la ultima return=TRUE y sino es la ultima return=FALSE)
void recuperar_cartas(tcartas *mazo, tcartas *lc);//una vez se acaban las cartas de lc, se recuperan del mazo de descartes

*/

