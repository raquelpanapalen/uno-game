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

void inicializar_partida(tpartida *p)
{
	int i;
	char pregunta[MAX_CAD]="Quieres ejecutar en modo COMPROBACION?:";	
	p->sentido=HORARIO;
	inicializar_jugadores(&p->lj);
	p->visible=preguntar_si_o_no(pregunta);
	printf("\n");
	inicializar_cartas(&p->lc);
	mezclar_cartas(&p->lc);
	inicializar_mazo_descartes(&p->lc, &p->mazo);
	p->turno=(rand()%(p->lj.num_jug));//Santi: inicializar el turno (turno lo he añadido en el struct tpartida para llevar el turno del jugador que le toca)
	for (i=0; i<p->lj.num_jug; i++)
	{
		repartir_cartas(7, &p->lj.lista_jug[i].mano, &p->lc);
	}	
	
}
void mostrar_estado_partida(tpartida p)
{
	mostrar_mazo(p.lc, p.visible);
	mostrar_mazo_descartes(p.mazo, p.sentido);
	mostrar_estado_jugadores(p.lj, p.visible);
	mostrar_turno(p);//Santi: esta en jugadas(creo que luego lo meteremos en jugadas posibles
}	
void mostrar_turno(tpartida p)
{
	int jug;
	tcarta carta_a_tirar;	
	printf("\n");
	cambiar_color_letra(RED);
	printf("Turno %s: ",p.lj.lista_jug[p.turno].nombre);
	default_attributes();
	jug=hay_jugadas(p.lj.lista_jug[p.turno].mano, p.mazo.cartas[0]);
	if (jug==TRUE)
	{
		printf("Jugadas posibles: ");
		calcular_jugadas_posibles(&p.pos_jug,p.mazo.cartas[0],p.lj.lista_jug[p.turno].mano);
		mostrar_jugadas(p.pos_jug);
		carta_a_tirar=elegir_jugada(p.turno, p.pos_jug);
		printf("Tira: |");
		mostrar_carta(carta_a_tirar);
		printf("|");
		
			
	}
	else
	{
		repartir_cartas(1, &p.lj.lista_jug[p.turno].mano, &p.lc);
		printf("Coge del mazo: |");
		mostrar_carta(p.lj.lista_jug[p.turno].mano.cartas[p.lj.lista_jug[p.turno].mano.nc -1]);
		printf("|");
	}
		
}
	
