#include <stdio.h>
#include "carta.h"
#include "colores.h"

void mostrar_carta(tcarta c)
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
  	default_attributes();
}


