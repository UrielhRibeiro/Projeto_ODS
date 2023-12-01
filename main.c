#include <stdio.h>
#include <locale.h>
#include <stdlib.h> 
#include "estilos.h"
#include "util.h"

int main() {
    setlocale(LC_ALL, "Portuguese");

    int opcao;

    do {
        printf("\n\n***** PROGRAMA DE PESQUISA DUDH *****\n\n");
        printf("[1] - Responder pesquisa\n");
        printf("[2] - Listar dados dos respondentes\n");
        printf("[3] - Listar dados individuais\n");
        printf("[4] - Listar estatísticas\n");
        printf("[5] - Fim do programa\n");
        printf("\nInforme qual opção deseja escolher: ");

        // Verificando se a entrada é um número
        if (scanf("%d", &opcao) != 1) {
            printStyledText("\nErro: Por favor, digite um número válido.\n",RED,BOLD);
            pausar();
            limparTela();
            // Limpa o buffer de entrada para evitar loops infinitos em caso de entrada inválida
            while (getchar() != '\n');
            continue;
        }

        // Chamada das funções do programa
        switch (opcao) {
            case 1:
               
                break;

            case 2:
                

            case 3:
               
                break;

            case 4:
              
                break;

            case 5:
                printf("\nFim do programa. Até mais!\n");
                break;

            default:
                printStyledText("\nErro: Opção inválida. Por favor, escolha uma opção válida.\n",RED,BOLD);
                pausar();
                limparTela();
                break;
        }

    } while (opcao != 5);

    return 0;
}
