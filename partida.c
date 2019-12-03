#include <stdio.h>
#include "carta.h"
#include "cartas.h"
#include "jugador.h"
#include "jugadores.h"
#include "partida.h"
#include "preguntas.h"
#include "colores.h"

void inicializar_partida(tpartida *p)
{
	int i;
	char pregunta[MAX_CAD]="Quieres ejecutar en modo COMPROBACION?:";	
	p->sentido=HORARIO;
	inicializar_jugadores(&p->lj);
	p->visible=preguntar_si_o_no(pregunta);
	inicializar_cartas(&p->lc);
	mezclar_cartas(&p->lc);
	for (i=0; i<p->lj.num_jug; i++)
	{
		repartir_cartas(7, &p->lj.lista_jug[i].mano, &p->lc);
	}
	mostrar_mazo(p->lc, p->visible);
	mostrar_estado_jugadores(p->lj, p->visible);
	
	
}
	
	
