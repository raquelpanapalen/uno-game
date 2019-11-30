#include <stdio.h>
#include "carta.h"
#include "cartas.h"
#include "colores.h"

int main()
{
	int i,j;
	tcartas b;
	inicializar_cartas(&b);
	for (i=0; i<b.nc; i++)
	{
		printf("|");
		mostrar_carta(b.cartas[i]); 
  	if ((i+1)%12 == 0)
  		printf("|\n");
  }
  printf("\n");
}

	

