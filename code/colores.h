#ifndef COLORES_H
#define	COLORES_H

// http://stackoverflow.com/questions/3219393/stdlib-and-colored-output-in-c
// http://ascii-table.com/ansi-escape-sequences.php

#define ANSI_COLOR_WHITE   "\x1b[37;1m"
#define ANSI_COLOR_YELLOW  "\x1b[33;1m"
#define ANSI_COLOR_RED     "\x1b[31;1m"
#define ANSI_COLOR_GREEN   "\x1b[32;1m"
#define ANSI_COLOR_BLUE    "\x1b[36;1m"
#define ANSI_COLOR_BLACK   "\x1b[30;1m"

#define ANSI_BACKGROUND_WHITE   "\x1b[47m"
#define ANSI_BACKGROUND_YELLOW  "\x1b[43m"
#define ANSI_BACKGROUND_RED     "\x1b[41m"
#define ANSI_BACKGROUND_GREEN   "\x1b[42m"
#define ANSI_BACKGROUND_BLUE    "\x1b[46m"
#define ANSI_BACKGROUND_BLACK   "\x1b[40m"

#define ANSI_RESET   "\x1b[0m"

#define WHITE 0
#define YELLOW 1
#define RED 2
#define GREEN 3
#define BLUE 4
#define BLACK 5


void cambiar_color_letra(int color);
void cambiar_color_fondo(int color);
void default_attributes();


#endif	/* COLORES_H */

