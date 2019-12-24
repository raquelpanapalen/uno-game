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
*Inicializa el jugador real y los robots pidiendo primero el nombre del jugador real y a continuación poniendo nombre a los robots según el orden numérico. 
*/
void inicializar_jugadores(tjugadores *lj)
{
	int i;
	lj->num_jug=preguntar_n_en_rango("Cuantos jugadores?", 3, 5);
	apodar_jugador(&lj->lista_jug[0]);
  for (i=1; i<lj->num_jug; i++)
  {
  	lj->lista_jug[i].nombre[0]='R';
  	lj->lista_jug[i].nombre[1]='o';
  	lj->lista_jug[i].nombre[2]='b';
  	lj->lista_jug[i].nombre[3]='o';
  	lj->lista_jug[i].nombre[4]='t';
  	lj->lista_jug[i].nombre[5]='0'+i;
	lj->lista_jug[i].nombre[6]='\0';
  }
}
/*
*conf==TRUE-->Muestra el estado de todos los jugadores, con las cartas boca arriba.
*conf==FALSE-->Muestra el estado de todos los jugadores, pero solo muestra las cartas boca arriba del jugador real y los robots tienen las cartas boca abajo. 
*/
void mostrar_estado_jugadores(tjugadores lj, int conf)
{
	int i=0, uno;
	printf("%s:\n", lj.lista_jug[i].nombre);
	mostrar_cartas(lj.lista_jug[i].mano, TRUE);
	mostrar_uno(lj.lista_jug[i].mano);
	printf("\n");
	for (i=1; i<lj.num_jug; i++)
	{
		printf("%s:\n", lj.lista_jug[i].nombre);
		mostrar_cartas(lj.lista_jug[i].mano, conf);
		mostrar_uno(lj.lista_jug[i].mano);
		printf("\n");
	}
}


	
