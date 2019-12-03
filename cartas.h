#ifndef CARTAS_H
#define CARTAS_H
#define MC 108
#define TRUE 1
#define FALSE 0

typedef struct
{
   int nc;
   tcarta cartas[MC];
}tcartas;

void inicializar_cartas(tcartas *lc); //inicializa las 108 cartas en lc (sin barajar random)
void mezclar_cartas(tcartas *lc);//mezcla cartas lc
void mostrar_cartas(tcartas lc,int conf); //mostrar lc si conf = TRUE o mostrar |UNO| si conf = FALSE
void repartir_cartas(int numcart, tcartas *mano, tcartas *lc);//pasa las primeras nc cartas de lc a mano(inicializar juego)
void mostrar_mazo(tcartas lc,int conf);
/*
int buscar_carta(tcarta c, tcartas lc);//return posicion de c en lc
void eliminar_cartas(int pos, tcartas *lc);//elimina carta de lc en posicion pos
int posible_carta(tcarta c1, tcarta c2);//verifica si se puede colocar carta c1 sobre carta c2(return: FALSE no se puede y TRUE se puede)
void tirar_carta(tcarta c,tcartas *mazo);//pasar carta c de mano del jugador a mazo de descartes
int ultima_carta(tcartas mano);//contar el numero de cartas de la mano(si es la ultima return=TRUE y sino es la ultima return=FALSE)
void recuperar_cartas(tcartas *mazo, tcartas *lc);//una vez se acaban las cartas de lc, se recuperan del mazo de descartes
*/

#endif
