//Trabalho Pr�tico 3 da mat�ria de Algoritmos e T�cnicas de Programa��o 2
//Integrantes: Daniel Henrique Peres Servejeira e Pedro Alonso Oliveira dos Santos

#include<stdio.h>
#include<stdlib.h>
#include<locale.h>
#include "functions.h"

void main() {
    setlocale(LC_ALL, "Portuguese");
//    printf("%d\n", sizeof(JOGADOR));

    int menu, n;
    FILE *file;

    do {
        file = fopen("banco.dat", "rb");
        numeroDeJogadores(file, &n);
        printf("\n\tMENU\n\n");
        printf("01 - Escrever novo jogador\n");
        printf("02 - Listar jogadores em ordem alfab�tica\n");
        printf("03 - Listar posi��o dos jogadores no ranking\n");
        printf("04 - Listar jogadores com mais vit�rias\n");
        printf("05 - Alterar Dados de um Jogador\n");
        printf("06 - Inserir e Atualizar Pontua��o no Campeonato\n");
        printf("07 - Listar Classifica��o do Campeonato\n");
        printf("08 - Listar Jogadores com Pontua��o Maior que um Valor\n");
        printf("09 - Listar Jogadores com Pontua��o Menor que um Valor\n");
        printf("10 - Buscar Jogador por Nome\n");
        printf("11 - Buscar Jogador por Posi��o no Ranking\n");
        printf("12 - Mostrar a Quantidade M�dia de Seguidores de um Jogador\n");
        printf("00 - Sair\n\n");
        scanf("%d", &menu);
        system("cls");

        switch(menu) {
        case 0:
            return;
        case 1:
            file = fopen("banco.dat", "ab+");
            escreverJogador(file, n);
            break;
        case 2:
            file = fopen("banco.dat", "rb");
            listarJogadoresAlfabetica(file, n);
            fclose(file);
            break;
        case 3:
            file = fopen("banco.dat", "rb");
            listarJogadoresRanking(file, n);
            fclose(file);
            break;
        case 4:
            file = fopen("banco.dat", "rb");
            listarJogadoresVitorias(file, n);
            fclose(file);
            break;
        case 5:
            file = fopen("banco.dat", "rb+");
            alterarJogador(file, &n);
            break;
        case 6:
            file = fopen("banco.dat", "rb+");
            inserirResultado(file, n);
            break;
        case 7:
            file = fopen("banco.dat", "rb");
            listarClassificacao(file, n);
            fclose(file);
            break;
        case 8:
            file = fopen("banco.dat", "rb");
            pontuacaoMaiorQue(file, n);
            break;
        case 9:
            file = fopen("banco.dat", "rb");
            pontuacaoMenorQue(file, n);
            fclose(file);
            break;
        case 10:
            file = fopen("banco.dat", "rb");
            buscarJogadorNome(file, n);
            fclose(file);
            break;
        case 11:
            file = fopen("banco.dat", "rb");
            buscarJogadorRanking(file);
            fclose(file);
            break;
        case 12:
            file = fopen("banco.dat", "rb");
            mediaDeSeguidores(file, n);
            fclose(file);
            break;
        default:
            printf("\n\tInsira um comando v�lido.\n\n");
            break;
        }
        system("Pause");
        system("cls");
    } while(menu != 0);
}
