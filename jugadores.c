#include <stdio.h>
#include "carta.h"
#include "cartas.h"
#include "jugador.h"
#include "preguntas.h"
#include "jugadores.h"
#include "colores.h"
#include "jugada.h"
#include "jugadas.h"

void inicializar_jugadores(tjugadores *lj)
{
	int i;
	char preg[MAX_CAD]="Cuantos jugadores?";
	int min=3, max=5;
	lj->num_jug=preguntar_n_en_rango(preg, min, max);
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
void mostrar_estado_jugadores(tjugadores lj, int conf)
{
	int i=0;
	printf("%s:\n", lj.lista_jug[i].nombre);
	mostrar_cartas(lj.lista_jug[i].mano, TRUE);
	for (i=1; i<lj.num_jug; i++)
	{
		printf("%s:\n", lj.lista_jug[i].nombre);
		mostrar_cartas(lj.lista_jug[i].mano, conf);
	}
}
