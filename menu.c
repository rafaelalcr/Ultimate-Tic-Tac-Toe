#include "menu.h"

void menu() {
    dados r;
    int opcao;
    do {
        printf("------------------------------------\n");
        printf("|               MENU               |\n");
        printf("------------------------------------\n\n");
        printf("1 - Jogador 1 vs Jogador 2\n");
        printf("2 - Jogador vs Computador\n");
        printf("    Resultados: \n");
        printf("        3 - Jogador 1 vs Jogador 2\n");
        printf("        4 - Jogador vs Computador\n");
        printf("5 - Terminar Jogo\n");
        printf("------------------------------------\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        putchar('\n');

        switch (opcao) {
            case 1:
                jogarJogador(&r);
                break;
            case 2:
                jogarComputador(&r);
                break;
            case 3:
                resultadosJogos(r, 9);
                break;
            case 4:
                resultadosJogosComputador(r, 9);
                break;
            case 5:
                break;
        }
    } while (opcao != 5);
}
