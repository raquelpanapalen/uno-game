// Este fichero se le da al alumno
#include <stdio.h>
#include "colores.h"

// http://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c
// http://ascii-table.com/ansi-escape-sequences.php

/*
 * Dado un color (0-WHITE,  1-YELLOW, 2-RED, 3-GREEN, 4-BLUE, 5-BLACK), 
 * hace que el terminal a partir de ahora escriba los caracteres de ese color
 */
void cambiar_color_letra(int color) 
{
	switch (color) 
	{
		case  WHITE: 
			printf(ANSI_COLOR_WHITE); 
			break;
                case  YELLOW: 
			printf(ANSI_COLOR_YELLOW); 
			break;
		case  RED: 
			printf(ANSI_COLOR_RED); 
			break;
		case  GREEN: 
			printf(ANSI_COLOR_GREEN); 
			break;
		case  BLUE: 
			printf(ANSI_COLOR_BLUE); 
			break;
                case BLACK: 
			printf(ANSI_COLOR_BLACK); 
			break;  
	}
}

/*
 * Dado un color (0-WHITE,  1-YELLOW, 2-RED, 3-GREEN, 4-BLUE, 5-BLACK) 
 * hace que el terminal a partir de ahora escriba los caracteres con el 
 * fondo en ese color
 */
void cambiar_color_fondo(int color) 
{
	switch (color) 
	{
		case  WHITE: 
			printf(ANSI_BACKGROUND_WHITE); 
			break;
                case  YELLOW: 
			printf(ANSI_BACKGROUND_YELLOW); 
			break;
		case  RED: 
			printf(ANSI_BACKGROUND_RED); 
			break;
		case  GREEN: 
			printf(ANSI_BACKGROUND_GREEN); 
			break;
		case  BLUE: 
			printf(ANSI_BACKGROUND_BLUE); 
			break;
                case BLACK: 
			printf(ANSI_BACKGROUND_BLACK); 
			break;
                
	}
}

/*
 * Resetea el color de la letra y el fondo con su valor por defecto.
 */
void default_attributes()
{
    printf(ANSI_RESET); 
}

