#ifndef CARTA_H
#define CARTA_H
#define HORARIO 0
#define ANTIHORARIO 1
#define TRUE 1
#define FALSE 0 

void pasar_turno(tjugadores *lj,int npos,int sentido);//pasas el npos posiciones en lj en sentido(en el caso de SKIP pasamos 2 posiciones)
int cambiar_sentido(int sentido);//cambiar sentido al sentido contrario
void inicializar_partida();//inicializar partida
int cambiar_color(tcarta c);//detectar numero tcarta c y cambiarlo en funcion de la jugada possible o cambiar color a elegir por el jugador 



#endif
