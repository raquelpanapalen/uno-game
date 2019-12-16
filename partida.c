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
	p->sentido=HORARIO;
	p->fin_partida=FALSE;
	inicializar_jugadores(&p->lj);
	p->visible=preguntar_si_o_no("Quieres ejecutar en modo COMPROBACION?:");
	printf("\n");
	inicializar_cartas(&p->lc);
	mezclar_cartas(&p->lc);
	inicializar_mazo_descartes(&p->mazo, &p->lc);
	p->color=p->mazo.cartas[0].color;
	p->turno=(rand()%(p->lj.num_jug));
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
void mostrar_uno(tcartas mano)
{
	int uno;
	uno=ultima_carta(mano);
	if (uno==TRUE)
	{
		cambiar_color_letra(GREEN);
		printf(" ** UNO **");
		default_attributes();
	}
}
	
void realizar_jugada(tpartida *p)
{
	int jug, pos,i;
	tcarta carta_a_tirar;	
	mostrar_turno(*p);
	jug=hay_jugadas(p->lj.lista_jug[p->turno].mano, p->mazo.cartas[p->mazo.nc-1], p->color);
	if (jug==TRUE)
	{
		calcular_jugadas_posibles(&p->pos_jug,p->color, p->lj.lista_jug[p->turno].mano, p->mazo.cartas[p->mazo.nc-1]);
		if (p->turno==0 || p->visible==TRUE)
		{
			printf("Jugadas posibles: ");
			mostrar_jugadas(p->pos_jug);
		}
		carta_a_tirar=elegir_jugada(p->turno, p->pos_jug);
		mostrar_carta_tirada(carta_a_tirar, p);
		pos=buscar_carta(carta_a_tirar, p->lj.lista_jug[p->turno].mano);
		eliminar_cartas(pos, &p->lj.lista_jug[p->turno].mano);
		opciones(carta_a_tirar, p);
	}
	else
	{
		if(hay_mas_cuatro(p->lj.lista_jug[p->turno].mano)>0)
		{
		  p->pos_jug.njugadas=0;
		  for(i=0;i<hay_mas_cuatro(p->lj.lista_jug[p->turno].mano);i++)
 			{
				p->pos_jug.jugs[i].carta.fig=14;
				p->pos_jug.jugs[i].carta.color=0;
				p->pos_jug.njugadas++;
			}
			if (p->turno==0 || p->visible==TRUE)
			{
				printf("Jugadas posibles: ");
				mostrar_jugadas(p->pos_jug);
			}
			carta_a_tirar=elegir_jugada(p->turno, p->pos_jug);
			mostrar_carta_tirada(carta_a_tirar, p);
			pos=buscar_carta(carta_a_tirar, p->lj.lista_jug[p->turno].mano);
			eliminar_cartas(pos, &p->lj.lista_jug[p->turno].mano);
			mas_cuatro(p);
		}
		else
		{
			printf("Coge del mazo: ");
			if (p->turno==0)
				mostrar_carta(p->lc.cartas[0], TRUE);
			else
				mostrar_carta(p->lc.cartas[0], p->visible);
			printf("| ");
			jug=jugada_posible(p->lc.cartas[0], p->mazo.cartas[p->mazo.nc-1], p->color);
			if (jug==TRUE || p->lc.cartas[0].fig==14)
			{
				mostrar_carta_tirada(p->lc.cartas[0], p);
				carta_a_tirar=p->lc.cartas[0];
				eliminar_cartas(0, &p->lc);
				opciones(carta_a_tirar, p);	
			}
			else
			{
				printf("Ha pasado");
				robar_cartas(1, &p->lj.lista_jug[p->turno].mano, &p->lc);
			}
		}
	}
	printf("\n");
	esperar();
	printf("\n");
	p->fin_partida=fin_partida(*p);
	
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
	pasar_turno(1, p);
	robar_cartas(2, &p->lj.lista_jug[p->turno].mano, &p->lc);
}

void mas_cuatro(tpartida *p)
{
	if (p->turno==0)
		p->color=preguntar_color();
	else
		p->color=(rand()%(NUM_COLORES))+1;
	pasar_turno(1, p);
	robar_cartas(4, &p->lj.lista_jug[p->turno].mano, &p->lc);
}

void wild(tpartida *p)
{
	if (p->turno==0)
		p->color=preguntar_color();
	else
		p->color=(rand()%NUM_COLORES)+1;
}

void opciones(tcarta c, tpartida *p)
{
	if(c.fig<10)
		p->color=c.color;
	else if(c.fig==10)
		mas_dos(p);
	else if(c.fig==11)
	  reverse(p);
	else if(c.fig==12)
		pasar_turno(1,p);
	else if(c.fig==13)
		wild(p);
	else
		mas_cuatro(p);
}	

void mostrar_carta_tirada(tcarta c, tpartida *p)
{
	printf("Tira: ");
	mostrar_carta(c, TRUE);
	printf("| ");
	tirar_carta(c, &p->mazo);
	p->color=c.color;
}

int fin_partida(tpartida p)
{
	int i;
	while (i<p.lj.num_jug && p.fin_partida==FALSE)
	{
		if (p.lj.lista_jug[i].mano.nc==0)
			p.fin_partida=TRUE;
		else
			i++;
	}
	return p.fin_partida;
}

void mostrar_ganador(tpartida p)
{
	int i, ganador=-1;
	printf("\n===>>> FIN PARTIDA <<<===\n");
	mostrar_estado_partida(p);
	while (i<p.lj.num_jug && ganador==-1)
	{
		if (p.lj.lista_jug[i].mano.nc==0)
			ganador=i;
		else
			i++;
	}
	printf("\n===>>> HA GANADO %s. ¡FELICIDADES! <<<===\n", p.lj.lista_jug[ganador].nombre);
}


