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
	char pregunta[MAX_CAD]="Quieres ejecutar en modo COMPROBACION?:";	
	p->sentido=HORARIO;
	inicializar_jugadores(&p->lj);
	p->visible=preguntar_si_o_no(pregunta);
	inicializar_cartas(&p->lc);
	mezclar_cartas(&p->lc);
	mostrar_cartas(p->lc, p->visible);
	
}
	
	
