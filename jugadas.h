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

int hay_jugadas(tcartas mano, tcarta um); //return cuantas cartas posibles hay
tcarta elegir_jugada(int tipo_jug, tjugadas pjugs);


#endif
