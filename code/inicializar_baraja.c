#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "colores.h"
#define DIM 108
typedef struct
{
	int num;
	int color;
}tcarta;

typedef struct
{
	tcarta cartas[DIM];
	int num_cartas;
}tbaraja;

int main()
{
	srand (time(NULL)); 
	tbaraja baraja;
	int pos, i, j, c;
	tcarta aux;
	pos=0;
	//inicializar todas las cartas
	for (c=1; c<=4; c++)
	{
		baraja.cartas[pos].color=c;
		baraja.cartas[pos].num=0;
		pos++;
		for (i=0; i<2; i++)
		{
			for (j=1; j<=12; j++)
			{
				baraja.cartas[pos].color=c;
				baraja.cartas[pos].num=j;
				pos++;
			}
		}
	}
	for (i=0; i<8; i++)
	{
		baraja.cartas[pos].color=0;
		if (i<4)
		{
			baraja.cartas[pos].num=13;
		}
		else
		{
			baraja.cartas[pos].num=14;
		}
		pos++;
	}
	//print random
	for (i=0; i<108; i++)
	{
		pos=(rand() % (108));
		aux=baraja.cartas[i];
		baraja.cartas[i]=baraja.cartas[pos];
		baraja.cartas[pos]=aux;
	}
	printf("|");
	for (i=0; i<108; i++)
	{
		cambiar_color_fondo(baraja.cartas[i].color);
		if (baraja.cartas[i].num<=9)
			printf(" %d ", baraja.cartas[i].num);
		else if (baraja.cartas[i].num==10)
			printf("+2 ");
		else if (baraja.cartas[i].num==11)
			printf(" R ");
		else if (baraja.cartas[i].num==12)
			printf(" S ");
		else if (baraja.cartas[i].num==13)
			printf(" W ");
		else
			printf("W+4");
  	default_attributes();
  	
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
