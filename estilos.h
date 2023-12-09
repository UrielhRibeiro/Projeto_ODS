//Arquivo para definir estilos (fonte e cor do texto do programa)
#ifndef ESTILOS_H
#define ESTILOS_H

#include <stdio.h>

// Definição de cores
#define RESET_COLOR "\x1b[0m"
#define BLACK "\x1b[30m"
#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN "\x1b[36m"
#define WHITE "\x1b[37m"

// Definição de estilos de fonte
#define RESET_FONT "\x1b[0m"
#define BOLD "\x1b[1m"
#define UNDERLINE "\x1b[4m"
#define REVERSE "\x1b[7m"

// Função para imprimir texto com estilo
void printStyledText(const char *text, const char *color, const char *font){

      printf("%s%s%s%s\n", color, font, text, RESET_COLOR RESET_FONT);
}

#endif 
