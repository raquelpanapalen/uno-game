#ifndef CARTAS_H
#define CARTAS_H
#define MC 108
#define TRUE 1
#define FALSE 0
#define HORARIO 1
#define ANTIHORARIO -1

typedef struct
{
   int nc;
   tcarta cartas[MC];
}tcartas;

void inicializar_cartas(tcartas *lc); //inicializa las 108 cartas en lc (sin barajar random)
void mezclar_cartas(tcartas *lc);//mezcla cartas lc
void mostrar_cartas(tcartas lc,int conf); //mostrar lc si conf = TRUE o mostrar |UNO| si conf = FALSE
void inicializar_mano(tcartas *mano, tcartas *lc);//pasa las primeras 7 cartas de lc a mano(inicializar juego)
void robar_cartas(int numcart, tcartas *mano, tcartas *lc); //robar cartas al pasar turno o cartas especiales
void mostrar_mazo(tcartas lc,int conf);
void mostrar_mazo_descartes(tcartas mazo, int sentido, int color);
void inicializar_mazo_descartes(tcartas *mazo, tcartas *lc);
int ultima_carta(tcartas mano);//contar el numero de cartas de la mano(si es la ultima return=TRUE y sino es la ultima return=FALSE)
int buscar_carta(tcarta c, tcartas mano);//return posicion de c en mano
void eliminar_cartas(int pos, tcartas *mano);//elimina carta de mano en posicion pos
void tirar_carta(tcarta c,tcartas *mazo);//pasar carta c de mano del jugador a mazo de descartes
void recuperar_cartas(tcartas *mazo, tcartas *lc);//una vez se acaban las cartas de lc, se recuperan del mazo de descartes


#endif
