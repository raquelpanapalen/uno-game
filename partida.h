#ifndef PARTIDA_H
#define PARTIDA_H
#define HORARIO 1
#define ANTIHORARIO -1
#define TRUE 1
#define FALSE 0 

typedef struct
{
	int sentido, visible, fin_partida, turno, color;
	/*
	*sentido-> controla el sentido de la partida basandose en las constantes de HORARIO 1 y ANTIHORARIO -1.
	*visibles-> controla la configuración de modo comprobación.
	*fin_partida-> controla cuando la partida esta finalizada.
	*turno-> controla el turno del jugador que debe realizar la jugada(turno==0; jugador real).
	*color-> es una variable que unicamente presenta utilidad para saber que color se ha escojido en el caso de W o W+4. 
	*/
	tjugadores lj;//guarda el vector de los jugadores con el número de estos.
	tjugadas pos_jug;//guara las posibles jugadas de la persona a la qual le toque el turno.
	tcartas lc, mazo;
	/*
	*lc-> guarda la lista de cartas de robar.
	*mazo-> guarda la lista de cartas del mazo de descartes.
	*/
}tpartida;

void pasar_turno(int npos, tpartida *p);
void inicializar_partida(tpartida *p);
void mostrar_estado_partida(tpartida p);
void realizar_jugada(tpartida *p);
void mostrar_turno(tpartida p);
void reverse(tpartida *p);
void mas_dos(tpartida *p);
void mas_cuatro(tpartida *p);
void wild(tpartida *p);
void opciones(tcarta c, tpartida *p);
void mostrar_carta_tirada(tcarta c, tpartida *p);
int fin_partida(tpartida p);
void mostrar_ganador(tpartida p);
void mostrar_uno(tcartas mano);

#endif
