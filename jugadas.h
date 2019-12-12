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
void calcular_jugadas_posibles(tjugadas *pj,int color,tcartas mano, tcarta um);//um es ultima carta mazo de descartes
int hay_mas_cuatro(tcartas mano);
int hay_jugadas(tcartas mano, tcarta um, int color); //return cuantas cartas posibles hay
tcarta elegir_jugada(int tipo_jug, tjugadas pjugs);


#endif
