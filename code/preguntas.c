// Este fichero se le da al alumno
#include <stdio.h>
#include "colores.h"
#include "preguntas.h"

/*
 * Esta función devuelve cierto si n está fuera del rango [min, max] y 
 * falso en caso contrario.
 */
int fuera_de_rango(int n, int min, int max) 
{
	return ((n < min) || (n > max));
}

/*
 * Esta función pide al usuario un valor dentro del rango [min, max] y lo devuelve.
 * El parámetro s indica el mensaje que se muestra por pantalla al pedirle el dato al usuario.
 */
int preguntar_n_en_rango(char *s, int min, int max) 
{
	int n, uno;
	char car;

	do {
		printf("%s [%d-%d]: ", s, min, max);
		uno = scanf("%d", &n);
		do {
			scanf("%c", &car);
		} while (car!='\n');
	} while (uno != 1 || fuera_de_rango(n, min, max));
	
	return n;
}

/*
 * Esta función pide al usuario que responda  sí (s) o no (n). Devuelve cierto si responde sí y falso si responde no.
 * El parámetro s indica la pregunta que se muestra por pantalla al usuario.
 */
int preguntar_si_o_no(char *s) 
{
    char resp[MAX_CAD];

    do {
            printf("%s [s/n]: ", s);
            scanf("%[^\n]", resp);
            scanf("%*c");
    }while (resp[1]!='\0' || (resp[0]!='s' && resp[0]!='S' && resp[0]!='n' && resp[0]!='N'));
    
    return (resp[0]=='s' || resp[0]=='S');		
}

/*
 * Esta función pide al usuario una cadena de caracteres no vacía y la devuelve a través del parámero cad.
 * El parámetro msg indica el mensaje que se muestra por pantalla al pedirle la cadena al usuario.
 */
void preguntar_cadena(char *msg, char *cad)
{
    
    do {
        printf("%s", msg);
        scanf("%[^\n]", cad);
        scanf("%*c");
    } while (cad[0]=='\0');
}

/*
 * Esta función pide al usuario que escoja un color entre el 1-amarillo, 2-rojo, 3-verde y 4-azul y devuelve el color 
 * escogido.
 */

int preguntar_color () 
{
	int i, color, uno;
        char car;

        default_attributes();
        do 
        {
            printf("Que color escoges? [ ");
            for (i=1; i<=NUM_COLORES; i++) 
            {
		printf("%d(|", i);
                cambiar_color_fondo(i);
                printf("   "); 
                default_attributes();
                printf("|) ");                        
            }
            printf("]: ");
            uno = scanf("%d", &color);
            do {
		scanf("%c", &car);
            } while (car!='\n');
        }while (color<1 || color>NUM_COLORES);
        return color;
}

/*
 * Esta función pide al usuario que pique la tecla <return> para continuar
 */

void esperar()
{
    char c=' ';
    
    default_attributes();
    printf("Press return to continue...");
    while (c!='\n')
        scanf("%c", &c);
}
