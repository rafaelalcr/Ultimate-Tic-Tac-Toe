#include <stdio.h>
#include "menu.h"

void menu() {
    jogo r;
    int opcao;
    do {
        printf("------------------------------------\n");
        printf("|               MENU               |\n");
        printf("------------------------------------\n\n");
        printf("1 - Jogador 1 vs Jogador 2\n");
        printf("2 - Jogador vs Computador\n");
        printf("3 - Terminar Jogo\n");
        printf("------------------------------------\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        putchar('\n');

        switch (opcao) {
            case 1:
                jogar_jogador(&r);
                break;
            case 2:
                jogar_computador(&r);
                break;
            default:
                break;
        }
    } while (opcao != 3);
}
