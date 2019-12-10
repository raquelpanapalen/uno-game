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
	p->turno=(rand()%(p->lj.num_jug));
	for (i=0; i<p->lj.num_jug; i++)
	{
		repartir_cartas(7, &p->lj.lista_jug[i].mano, &p->lc);
	}	
	
}
void mostrar_estado_partida(tpartida p)
{
	mostrar_mazo(p.lc, p.visible);
	mostrar_mazo_descartes(p.mazo, p.sentido,p.color);
	mostrar_estado_jugadores(p.lj, p.visible);
	if(p.turno==0)
	{
		mostrar_turno(p);
		calcular_jugadas_posibles(&p.pos_jug,p.mazo.cartas[0],p.lj.lista_jug[p.turno].mano);
		mostrar_jugadas(p.pos_jug);
		realizar_jugada(&p.mazo,p.pos_jug);
		//FALTA SACAR LA CARTA DEL MAZO DEL JUGADOR Y LO MISMO PARA ROBOTS
	}
	if(p.turno!=0)
	{
	  mostrar_turno(p);
	  calcular_jugadas_posibles(&p.pos_jug,p.mazo.cartas[0],p.lj.lista_jug[p.turno].mano);
		mostrar_jugadas(p.pos_jug);
		realizar_jugada_robots(&p.mazo,p.pos_jug);//FALTA POR HACER
	}	
}	
void mostrar_turno(tpartida p)
{
	printf("\n");
	cambiar_color_letra(RED);
	printf("Turno %s: ",p.lj.lista_jug[p.turno].nombre);
	default_attributes();
	printf("Jugadas posibles: ");
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
	robar_cartas(2, &p->lj.lista_jug[&p->turno+1].cartas, &p->lc);
	pasar_turno(2, &p);
}

void mas_cuatro(tpartida *p)
{
	if (p->turno==0)
		p->color=preguntar_color();
	else
		p->color=(rand()%(NUM_COLORES))+1;
	robar_cartas(4, &p->lj.lista_jug[&p->turno+1].cartas, &p->lc);
	pasar_turno(2, &p);
}

void wild(tpartida *p)
{
	if (p->turno==0)
		p->color=preguntar_color();
	else
		p->color=(rand()%(NUM_COLORES))+1;
}
	
