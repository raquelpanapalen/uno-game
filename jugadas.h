#ifndef JUGADAS_H
#define JUGADAS_H
#define MJUGADAS 108
#define TRUE 1
#define FALSE 0

typedef struct
{
   int njugadas;
   tjugada jugadas[MJUGADAS];
}tjugadas;

void mostrar_jugadas(tjugadas pj);
void calcular_jugadas_posibles(tjugadas *pj,tcarta um,tcartas mano);//um es ultima carta mazo de descartes
int hay_jugadas(tcarta um,tcartas mano);//busca si hay jugadas o no y devuelve TRUE si es diferente de 0 o FALSE si es 0.






#endif
