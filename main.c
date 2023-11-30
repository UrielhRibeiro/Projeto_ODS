//Inclusão das bibliotecas
#include <stdio.h>
#include <locale.h>

// Código main (função principal)
int main(){
// Declaração das variáveis
    int opcao;

// Iniciando o menu do programa
    do{

    printf("\n\n***** PROGAMA DE PESQUISA DUDH *****\n\n");
    
    printf("[1] - Responder pesquisa\n");
    printf("[2] - Listas dados dos respondentes\n");
    printf("[3] - Listar dados individuais\n");
    printf("[4] - Listar estatística\n");
    printf("[5] - Fim do programa\n");
    printf("\nInforme qual opção deseja escolher: ");
    scanf("%d", &opcao);

// Chamada das funções do programa
    switch (opcao) {
    case 1:

        break;

    case 2:

        break;

    case 3:

        break;

    case 4:

        break;
    
    case 5:

        break;
    
    default:

        break;
    }

    }while(opcao != 5);

    return 0;
}