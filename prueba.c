#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "carta.h"
#include "cartas.h"
#include "jugador.h"
#include "jugada.h"
#include "jugadas.h"
#include "jugadores.h"
#include "partida.h"
#include "preguntas.h"
#include "colores.h"


int main()
{
	tpartida p;
	srand (time(NULL));
	inicializar_partida(&p);
	mostrar_estado_partida(p);
	while (p.fin_partida!=TRUE)
	{
		realizar_jugada(&p);
		mostrar_estado_partida(p);
		if (p.fin_partida==FALSE)
			pasar_turno(1, &p);
	}
/*	mostrar_ganador(p);*/	
}

	

