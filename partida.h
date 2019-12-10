#ifndef PARTIDA_H
#define PARTIDA_H
#define HORARIO 1
#define ANTIHORARIO -1
#define TRUE 1
#define FALSE 0 

typedef struct
{
	int sentido, visible, fin_partida,turno, color;
	tjugadores lj;
	tjugadas pos_jug;
	tcartas lc, mazo;


}tpartida;

void pasar_turno(int npos, tpartida *p);//pasas el npos posiciones en lj en sentido(en el caso de SKIP pasamos 2 posiciones)
void inicializar_partida(tpartida *p);//inicializar partida
int cambiar_color(tcarta c);//detectar numero tcarta c y cambiarlo en funcion de la jugada possible o cambiar color a elegir por el jugador
void mostrar_estado_partida(tpartida p);
void mostrar_turno(tpartida p);
void reverse(tpartida *p);
void mas_dos(tpartida *p);
void mas_cuatro(tpartida *p);
void wild(tpartida *p);

#endif
