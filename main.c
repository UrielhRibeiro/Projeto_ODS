//Declaração das bibliotecas
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include "estilos.h"
#include "util.h"
#include "pesquisa.h"

//Inicio da função principal do programa
int main() {
    //Definição da linguagem do código - Português
    UINT CPAGE_UTF8 = 65001;
    UINT CPAGE_DEFAULT = GetConsoleOutputCP();
    SetConsoleOutputCP(CPAGE_UTF8);

    int opcao;

    //Inicio do menu
    do {
        printStyledText("\n\n***** PROGRAMA DE PESQUISA DUDH *****\n\n",WHITE,BOLD);
        printStyledText("[1] - Responder pesquisa\n",GREEN,BOLD);
        printStyledText("[2] - Listar dados dos respondentes\n",YELLOW,BOLD);
        printStyledText("[3] - Listar dados individuais\n",BLUE,BOLD);
        printStyledText("[4] - Listar estatísticas\n",MAGENTA,BOLD);
        printStyledText("[5] - Fim do programa\n",RED,BOLD);
        printf("\nInforme qual opção deseja escolher: ");

        if (scanf("%d", &opcao) != 1) {
            printStyledText("\nErro: Por favor, digite um número válido.\n", RED, BOLD);
            pausar();
            limparTela();
            while (getchar() != '\n');
            continue;
        }

        switch (opcao) {
            case 1: // Cadastrar participante
                limparTela();
                {
                    Participante novoParticipante;
                    cadastrarParticipante(&novoParticipante);
                    salvarDados(&novoParticipante);
                }
                break;

            case 2: // Listar participantes
                limparTela();
                listarParticipantes();
                break;

            case 3: // Pesquisa participante 
                limparTela();
                {
                    char nomePesquisa[100];
                    printf("Digite o nome da pessoa para pesquisa: ");
                    scanf("%s", nomePesquisa);
                    pesquisarParticipante(nomePesquisa);
                }
                break;

            case 4:// Listar participante
                limparTela();
                listarEstatisticas();
                break;

            case 5: // Fim do programa
                printStyledText("\nFim do programa. Até mais!\n",YELLOW,BOLD);
                break;

            default:
                printStyledText("\nErro: Opção inválida. Por favor, escolha uma opção válida.\n", RED, BOLD);
                pausar();
                limparTela();
                break;
        }

    } while (opcao != 5);

    return 0;
}
