// arquivo pesquisa.h 
#ifndef PESQUISA_H
#define PESQUISA_H

// Declaração das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "estilos.h"
#include "util.h"

#define MAX_PARTICIPANTES 100

// Adicionando as opções de violação
#define V1 'A'
#define V2 'B'
#define V3 'C'
#define V4 'D'

// Definição da estrutura de dados
typedef struct {
    char nome[100];
    int idade;
    char genero;
    char violacaoV1;
    char violacaoV2;
    char violacaoV3;
    char violacaoV4;
} Participante;

Participante participantes[MAX_PARTICIPANTES];
int numParticipantes = 0;

// Função de cadastrar participantes
void cadastrarParticipante(Participante *participante) {
    if (numParticipantes >= MAX_PARTICIPANTES) {
        printStyledText("Erro: Limite máximo de participantes atingido.\n", RED, BOLD);
        return;
    }

    printStyledText("======= DADOS PESSOAIS =======\n\n",WHITE,BOLD);

    printf("Digite seu nome: ");
    if (scanf("%99s", participante->nome) != 1) {
        printStyledText("Erro: Falha ao ler o nome.\n", RED, BOLD);
        return;
    }

    printf("\nDigite sua idade: ");
    if (scanf("%d", &participante->idade) != 1) {
        printStyledText("Erro: Falha ao ler a idade.\n", RED, BOLD);
        return;
    }

    printf("\nDigite seu gênero (M - Masculino, F - Feminino, O - Outros): ");
    if (scanf(" %c", &participante->genero) != 1) {
        printStyledText("Erro: Falha ao ler o gênero.\n", RED, BOLD);
        return;
    }

    printStyledText("\n\n======= VIOLAÇÕES =======\n",WHITE,BOLD);

    printf("\n[Violação 1]: ");
    printf("\nVocê sofreu discriminação ou racismo? (S - Sim, N - Não): ");
    if (scanf(" %c", &participante->violacaoV1) != 1) {
        printStyledText("Erro: Falha ao ler a resposta sobre discriminação ou racismo.\n", RED, BOLD);
        return;
    }

    printf("\n[Violação 2]: ");
    printf("\nVocê sofreu restrição à liberdade de expressão? (S - Sim, N - Não): ");
    if (scanf(" %c", &participante->violacaoV2) != 1) {
        printStyledText("Erro: Falha ao ler a resposta sobre restrição à liberdade de expressão.\n", RED, BOLD);
        return;
    }

    printf("\n[Violação 3]: ");
    printf("\nVocê sofreu tortura ou tratamento desumano? (S - Sim, N - Não): ");
    if (scanf(" %c", &participante->violacaoV3) != 1) {
        printStyledText("Erro: Falha ao ler a resposta sobre tortura ou tratamento desumano.\n", RED, BOLD);
        return;
    }

    printf("\n[Violação 4]: ");
    printf("\nVocê sofreu restrição ao direito de segurança? (S - Sim, N - Não): ");
    if (scanf(" %c", &participante->violacaoV4) != 1) {
        printStyledText("Erro: Falha ao ler a resposta sobre restrição ao direito de segurança.\n", RED, BOLD);
        return;
    }

    participantes[numParticipantes++] = *participante;
    printStyledText("Dados salvos com sucesso!\n", GREEN, BOLD);

    pausar();
    limparTela();
}

// Função para salvar os dados do participante em um arquivo .txt
void salvarDados(const Participante *participante) {
    FILE *arquivo = fopen("dados_pesquisa.txt", "a");

    if (arquivo == NULL) {
        printStyledText("Erro: Falha ao abrir ou criar o arquivo.\n", RED, BOLD);
        return;
    }

    int charsEscritos = fprintf(arquivo, "Nome: %s\nIdade: %d\nGênero: %c\n"
                                        "V1: %c\nV2: %c\nV3: %c\nV4: %c\n\n",
                                participante->nome, participante->idade, participante->genero,
                                participante->violacaoV1, participante->violacaoV2,
                                participante->violacaoV3, participante->violacaoV4);

    if (charsEscritos > 0) {
        printStyledText("Dados salvos com sucesso!\n", GREEN, BOLD);
    } else {
        printStyledText("Erro: Falha ao salvar os dados no arquivo.\n", RED, BOLD);
    }

    if (fclose(arquivo) != 0) {
        printStyledText("Erro: Falha ao fechar o arquivo.\n", RED, BOLD);
    }
}

//Função para lsitar todos os participantes
void listarParticipantes() {
    printf("\n\nLista de Participantes:\n\n");
    printf("%-20s | %-6s | %-8s | %-3s | %-3s | %-3s | %-3s\n", "Nome", "Idade", "Gênero", "V1", "V2", "V3", "V4");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < numParticipantes; i++) {
        printf("%-20s | %-6d | %-8c | %-3c | %-3c | %-3c | %-3c\n", participantes[i].nome,
               participantes[i].idade, participantes[i].genero, participantes[i].violacaoV1,
               participantes[i].violacaoV2, participantes[i].violacaoV3, participantes[i].violacaoV4);
        printf("---------------------------------------------------------------\n");
    }

    pausar();
    limparTela();
}

//Função para pesquisar um participante
void pesquisarParticipante(const char *nome) {
    int encontrado = 0;

    for (int i = 0; i < numParticipantes; i++) {
        if (strcmp(participantes[i].nome, nome) == 0) {
            encontrado = 1;
            printf("\n\nDados do participante %s:\n\n", nome);
            printf("%-20s | %-6s | %-8s | %-3s | %-3s | %-3s | %-3s\n", "Nome", "Idade", "Gênero", "V1", "V2", "V3", "V4");
            printf("--------------------------------------------------------------\n");
            printf("%-20s | %-6d | %-8c | %-3c | %-3c | %-3c | %-3c\n", participantes[i].nome,
                   participantes[i].idade, participantes[i].genero, participantes[i].violacaoV1,
                   participantes[i].violacaoV2, participantes[i].violacaoV3, participantes[i].violacaoV4);
            break;
        }
    }

    if (!encontrado) {
        printf("\nParticipante %s não encontrado.\n", nome);
    }

    pausar();
    limparTela();
}

//Função para listar as estatisticas do formulario
void listarEstatisticas() {
    int totalGeral = numParticipantes;
    int totalViolacaoV1 = 0, totalViolacaoV2 = 0, totalViolacaoV3 = 0, totalViolacaoV4 = 0;
    int totalGeneroM = 0, totalGeneroF = 0, totalGeneroO = 0;
    int totalMenores18 = 0, totalMaiores18 = 0;

    for (int i = 0; i < numParticipantes; i++) {
        // Adapte conforme suas violações
        if (participantes[i].violacaoV1 == 'S') {
            totalViolacaoV1++;
        }
        if (participantes[i].violacaoV2 == 'S') {
            totalViolacaoV2++;
        }
        if (participantes[i].violacaoV3 == 'S') {
            totalViolacaoV3++;
        }
        if (participantes[i].violacaoV4 == 'S') {
            totalViolacaoV4++;
        }

        // Adapte conforme seus gêneros
        if (participantes[i].genero == 'M') {
            totalGeneroM++;
        } else if (participantes[i].genero == 'F') {
            totalGeneroF++;
        } else if (participantes[i].genero == 'O') {
            totalGeneroO++;
        }

        // Adapte conforme suas faixas etárias
        if (participantes[i].idade < 18) {
            totalMenores18++;
        } else {
            totalMaiores18++;
        }
    }
  printStyledText("\n\n ESTATÍSTICAS GERAIS: \n\n",WHITE,BOLD);
    printf("\n----------------------------------------------\n\n");
    printf(" Total geral de participantes:            %-4d\n", totalGeral);
    printf("\n----------------------------------------------\n\n");
    printf(" V1 (Discriminação ou racismo):           %-4d\n", totalViolacaoV1);
    printf(" V2 (Restrição à liberdade de expressão): %-4d\n", totalViolacaoV2);
    printf(" V3 (Tortura ou tratamento desumano):     %-4d\n", totalViolacaoV3);
    printf(" V4 (Restrição ao direito de segurança):  %-4d\n", totalViolacaoV4);
    printf("\n----------------------------------------------\n\n");
    printf(" Gênero - Masculino:                      %-4d\n", totalGeneroM);
    printf(" Gênero - Feminino:                       %-4d\n", totalGeneroF);
    printf(" Gênero - Outros:                         %-4d\n", totalGeneroO);
    printf("\n----------------------------------------------\n\n");
    printf(" Menores de 18 anos:                      %-4d\n", totalMenores18);
    printf(" Maiores ou iguais a 18 anos:             %-4d\n", totalMaiores18);
    printf("\n----------------------------------------------\n\n");

    pausar();
    limparTela();
}

#endif
