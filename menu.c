#include "menu.h"

void menu() {
    dados r;
    int opcao;
    do {
        printf("--------------- MENU ---------------\n\n");
        printf("1 - Jogador 1 vs Jogador 2\n");
        printf("2 - Jogador vs Computador\n");
        printf("3 - Resultados\n");
        printf("4 - Terminar Jogo\n");
        printf("------------------------------------\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        putchar('\n');

        switch (opcao) {
            case 1:
                jogar(&r);
                break;
            case 2:
                break;
            case 3:
                resultadosJogos(r, 9);
                break;
            case 4:
                break;
        }
    } while (opcao != 4);
}
