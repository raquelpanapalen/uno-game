#ifndef CARTAS_H
#define CARTAS_H
#define MC 108
#define TRUE 1
#define FALSE 0
#define HORARIO 1
#define ANTIHORARIO -1

typedef struct
{
   int nc;//número de cartas del vector carta[MC].
   tcarta cartas[MC];//vector de tcarta con MC espacios.
}tcartas;

void inicializar_cartas(tcartas *lc); 
void mezclar_cartas(tcartas *lc);
void mostrar_cartas(tcartas lc,int conf); 
void inicializar_mano(tcartas *mano, tcartas *lc);
void robar_cartas(int numcart, tcartas *mano, tcartas *lc, tcartas *mazo);
void mostrar_mazo(tcartas lc,int conf);
void mostrar_mazo_descartes(tcartas mazo, int sentido, int color);
void inicializar_mazo_descartes(tcartas *mazo, tcartas *lc);
int ultima_carta(tcartas mano);
int buscar_carta(tcarta c, tcartas mano);
void eliminar_cartas(int pos, tcartas *mano);
void tirar_carta(tcarta c,tcartas *mazo);
void recuperar_cartas(tcartas *mazo, tcartas *lc);

#endif
