//Arquivo de funções utilitárias (funções genéricas)
#ifndef UTIL_H
#define UTIL_H

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

//Função que limpa a tela em sistemas windows e linux
void limparTela() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

//Função que pausa a tela em sistemas windows e linux
void pausar() {
#ifdef _WIN32
    system("pause");
#else
    printf("Pressione Enter para continuar...");
    while (getchar() != '\n');
#endif
}

// Função que gera um delay em uma certa quantidade de tempo
void delay(int milliseconds) {
#ifdef _WIN32
    Sleep(milliseconds);
#else
    usleep(milliseconds * 1000);
#endif
}

#endif