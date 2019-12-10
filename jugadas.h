#ifndef JUGADAS_H
#define JUGADAS_H
#define MJUGADAS 108
#define TRUE 1
#define FALSE 0

typedef struct
{
   int njugadas;
   tjugada jugs[MJUGADAS];
}tjugadas;

void mostrar_jugadas(tjugadas pj);
void calcular_jugadas_posibles(tjugadas *pj,tcarta um,tcartas mano);//um es ultima carta mazo de descartes
void realizar_jugada(tcartas *mazo,tjugadas pj);
 void realizar_jugada_robots(tcartas *mazo, tjugadas pj);


#endif
