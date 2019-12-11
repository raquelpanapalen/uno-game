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
	p->fin_partida=FALSE;
	inicializar_jugadores(&p->lj);
	p->visible=preguntar_si_o_no(pregunta);
	printf("\n");
	inicializar_cartas(&p->lc);
	mezclar_cartas(&p->lc);
	inicializar_mazo_descartes(&p->mazo, &p->lc);
	p->color=p->mazo.cartas[0].color;
	p->turno=(rand()%(p->lj.num_jug));//Santi: inicializar el turno (turno lo he añadido en el struct tpartida para llevar el turno del jugador que le toca)
	for (i=0; i<p->lj.num_jug; i++)
	{
		inicializar_mano(&p->lj.lista_jug[i].mano, &p->lc);
	}	
	
}
void mostrar_estado_partida(tpartida p)
{
	mostrar_mazo(p.lc, p.visible);
	mostrar_mazo_descartes(p.mazo, p.sentido, p.color);
	mostrar_estado_jugadores(p.lj, p.visible);
}
void mostrar_turno(tpartida p)
{
	printf("\n");
	cambiar_color_letra(RED);
	printf("Turno %s: ",p.lj.lista_jug[p.turno].nombre);
	default_attributes();
}
	
void realizar_jugada(tpartida *p)
{
	int jug, pos;
	tcarta carta_a_tirar;	
	mostrar_turno(*p);
	jug=hay_jugadas(p->lj.lista_jug[p->turno].mano, p->mazo.cartas[p->mazo.nc-1], p->color);
	if (jug==TRUE)
	{
		if (p->turno==0 || p->visible==TRUE)
		{
			printf("Jugadas posibles: ");
			calcular_jugadas_posibles(&p->pos_jug,p->color, p->lj.lista_jug[p->turno].mano, p->mazo.cartas[p->mazo.nc-1]);
			mostrar_jugadas(p->pos_jug);
		}
		carta_a_tirar=elegir_jugada(p->turno, p->pos_jug);
		printf("Tira: |");
		mostrar_carta(carta_a_tirar, TRUE);
		printf("|");
		/*FALTA COLOR ESCOGIDO*/
		/*de momento p->color=carta_a_tirar.color*/
		p->color=carta_a_tirar.color;	
		tirar_carta(carta_a_tirar, &p->mazo);
		pos=buscar_carta(carta_a_tirar, p->lj.lista_jug[p->turno].mano);
		eliminar_cartas(pos, &p->lj.lista_jug[p->turno].mano);
	}
	else
	{
		/*tiene mas cuatro?*/
		printf("Coge del mazo: |");
		if (p->turno==0)
			mostrar_carta(p->lc.cartas[0], TRUE);
		else
			mostrar_carta(p->lc.cartas[0], p->visible);
		printf("| ");
		jug=jugada_posible(p->lc.cartas[0], p->mazo.cartas[p->mazo.nc-1], p->color);
		if (jug==TRUE)
		{
			printf("Tira: |");
			mostrar_carta(p->lc.cartas[0], TRUE);
			printf("|");
			p->color=carta_a_tirar.color;	
			tirar_carta(p->lc.cartas[0], &p->mazo);
			eliminar_cartas(0, &p->lc);
		}
		else
		{
			printf("Ha pasado");
			robar_cartas(1, &p->lj.lista_jug[p->turno].mano, &p->lc);
		}
	}
	printf("\n");
	esperar();
	
}

void pasar_turno(int npos, tpartida *p)
{
	p->turno=p->turno+npos*p->sentido;
	if (p->turno>=p->lj.num_jug)
		p->turno=npos-1;
	if (p->turno<=-1)
		p->turno=(p->lj.num_jug-npos);
}
void reverse(tpartida *p)
{
	p->sentido=p->sentido*-1;
}

void mas_dos(tpartida *p)
{
	robar_cartas(2, &p->lj.lista_jug[p->turno+1].mano, &p->lc);
	pasar_turno(2, p);
}

void mas_cuatro(tpartida *p)
{
	if (p->turno==0)
		p->color=preguntar_color();
	else
		p->color=(rand()%(NUM_COLORES))+1;
	robar_cartas(4, &p->lj.lista_jug[p->turno+1].mano, &p->lc);
	pasar_turno(2, p);
}

void wild(tpartida *p)
{
	if (p->turno==0)
		p->color=preguntar_color();
	else
		p->color=(rand()%(NUM_COLORES))+1;
}








