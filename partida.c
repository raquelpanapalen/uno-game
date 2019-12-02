#include <stdio.h>
#include "partida.h"
#include "preguntas.h"
#include "carta.h"
#include "cartas.h"
#include "jugador.h"
#include "jugadores.h"
#include "colores.h"

void inicializar_partida(tpartida *p)
{
	char preg="Cuantos jugadores?", msg="Tu nombre?", s="Quieres ejecutar en modo COMPROBACION?: [s/n]:";
	int min=3, max=5;	
	p->sentido=HORARIO;
	p->j.num_jug=preguntar_n_en_rango(char *preg, int min, int max);
	preguntar_cadena(char *msg, char *p->j.lista_jug[0].nombre[MN]);
	p->visible=preguntar_si_o_no(char *s);
	inicializar_cartas(tcartas &p->lc);
	mezclar_cartas(tcartas &p->lc);
}
	
	
