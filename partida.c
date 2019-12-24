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
/*
*incializa la partida usando las funciones definidas en otras librerias. 
*/
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
/*
*p.visible==TRUE muestra:
->Primero la lista de cartas.
->Segundo la ultima carta del mazo de descartes, el numero de cartas que tiene este, el sentido de la partida y el color escojido en caso de W o W+4.
->Tercero las manos de los jugadores con los respectivos nombres de cada jugador. 
*p.visibles==FALSE muestra: 
->Primero la última carta de la lista de cartas de robar bocaabajo junto al número de cartas de este.
->Segundo la ultima carta del mazo de descartes, el numero de cartas que tiene este, el sentido de la partida y el color escojido en caso de W o W+4.
->Tercero la mano del jugador con el respectivo nombre de este y las manos de los robots boca abajo con sus respectivos nombres.
*/
void mostrar_estado_partida(tpartida p)
{
	mostrar_mazo(p.lc, p.visible);
	mostrar_mazo_descartes(p.mazo, p.sentido, p.color);
	mostrar_estado_jugadores(p.lj, p.visible);
}
/*
*Muestra el nombre del jugador que le toca tirar. 
*/
void mostrar_turno(tpartida p)
{
	printf("\n");
	cambiar_color_letra(RED);
	printf("Turno %s: ",p.lj.lista_jug[p.turno].nombre);
	default_attributes();
}
/*
*Muestra **UNO** si el jugador solo tiene una carta. 
*/
void mostrar_uno(tcartas mano)
{
	int uno;
	uno=ultima_carta(mano);
	if (uno==TRUE)
	{
		cambiar_color_letra(GREEN);
		printf(" ** UNO **");
		default_attributes();
		printf("  ");
	}
}
/*
*Si hay jugadas(contando W+4, en el caso que no haya cartas del color de partida) en la mano del jugador, las calculas y escoge una jugada mediante funciones definidas anteriormente.
*Si no hay jugadas(contando W+4, en el caso que no haya cartas del color de partida) en la mano del jugador:
->Comprueba si es el turno de la persona real para mostarla o no.
->Comprueba si la cara carta que roba puede ser tirada directamente(si es el caso se tira directamente, sino se añade a la mano y se pasa turno).
*Una vez realizada la jugada se comprueba si es una carta especial y se realiza la acción especifica de la carta en cuestión.
*Se comprueba si la partida ha finalizado o no.  
*/

void realizar_jugada(tpartida *p)
{
	int jug, pos, i;
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
		printf("Coge del mazo: ");
		if (p->turno==0)
			mostrar_carta(p->lc.cartas[0], TRUE);
		else
			mostrar_carta(p->lc.cartas[0], p->visible);
		printf("| ");
		jug=jugada_posible_scolor(p->lc.cartas[0], p->mazo.cartas[p->mazo.nc-1], p->color);
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
			robar_cartas(1, &p->lj.lista_jug[p->turno].mano, &p->lc,&p->mazo);
		}
	}
	printf("\n");
	esperar();
	printf("\n");
	p->fin_partida=fin_partida(*p);
	
}
/*
*Se suma tantas posiciones como marca npos en el sentido de p->sentido. 
*Si el el turno sobrepasa los limites de 0-4 se devuelve a su sitio correspondiente. 
*/
void pasar_turno(int npos, tpartida *p)
{
	p->turno=p->turno+npos*p->sentido;
	if (p->turno>=p->lj.num_jug)
		p->turno=npos-1;
	if (p->turno<=-1)
		p->turno=(p->lj.num_jug-npos);
}
/*
*Se invierte el sentido de la partida. 
*/
void reverse(tpartida *p)
{
	mostrar_uno(p->lj.lista_jug[p->turno].mano);
	p->sentido=p->sentido*-1;
}
/*
*Se obliga a robar 2 cartas de la lista de cartas al siguiente jugador
*Se pasa el turno del siguiente jugador.
*/
void mas_dos(tpartida *p)
{
	mostrar_uno(p->lj.lista_jug[p->turno].mano);
	pasar_turno(1, p);
	robar_cartas(2, &p->lj.lista_jug[p->turno].mano, &p->lc,&p->mazo);
}
/*
*Se cambia el color de la siguiente jugada. 
->turno==0--> el jugador real elige el color.
->turno!=0--> el robot elige un color aleatorio.
*Se obliga a robar 4 cartas de la lista de cartas al siguiente jugador 
*Se pasa el turno del siguiente jugador.
*/
void mas_cuatro(tpartida *p)
{
	if (p->turno==0)
		p->color=preguntar_color();
	else
		p->color=(rand()%(NUM_COLORES))+1;
	printf("Color escogido: |");
	cambiar_color_fondo(p->color);
	printf("   ");
	default_attributes();
	printf("| ");
	mostrar_uno(p->lj.lista_jug[p->turno].mano);
	pasar_turno(1, p);
	robar_cartas(4, &p->lj.lista_jug[p->turno].mano, &p->lc,&p->mazo);
}
/*
*Se cambia el color de la siguiente jugada. 
->turno==0--> el jugador real elige el color.
->turno!=0--> el robot elige un color aleatorio.
*/
void wild(tpartida *p)
{
	if (p->turno==0)
		p->color=preguntar_color();
	else
		p->color=(rand()%NUM_COLORES)+1;
	printf("Color escogido: |");
	cambiar_color_fondo(p->color);
	printf("   ");
	default_attributes();
	printf("| ");
	mostrar_uno(p->lj.lista_jug[p->turno].mano);
}
/*
*Se determina la acción de las cartas especiales.
*/
void opciones(tcarta c, tpartida *p)
{
	if(c.fig<10)
	{
		p->color=c.color;
		mostrar_uno(p->lj.lista_jug[p->turno].mano);
	}
	else if(c.fig==10)
		mas_dos(p);
	else if(c.fig==11)
	  reverse(p);
	else if(c.fig==12)
	{
		mostrar_uno(p->lj.lista_jug[p->turno].mano);
		pasar_turno(1,p);
	}
	else if(c.fig==13)
		wild(p);
	else
		mas_cuatro(p);
}	
/*
*Se muestra la carta c que se tira al mazo de descartes.
*Se marca el color de la partida como el color de la carta c tirada. 
*/
void mostrar_carta_tirada(tcarta c, tpartida *p)
{
	printf("Tira: ");
	mostrar_carta(c, TRUE);
	printf("| ");
	tirar_carta(c, &p->mazo);
	p->color=c.color;
}
/*
*return TRUE si algún jugador se queda sin cartas en su mano.
*return FALSE si todos los jugadores aún tienen cartas en su mano.
*/
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
/*
*Se muestra un mensaje de fin de partida.
*Se muestra el estado final de la partida.
*Se muestra el nombre del jugador ganador(que se queda sin cartas en la mano).
*/
void mostrar_ganador(tpartida p)
{
	int i=0, ganador=-1;
	printf("\n===>>> FIN PARTIDA <<<===\n");	
	p.visible=TRUE;
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


