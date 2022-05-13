#include "menu.h"

void menu() {
    jogo r;
    jogoC s;
    int opcao;
    do {
        printf("------------------------------------\n");
        printf("|               MENU               |\n");
        printf("------------------------------------\n\n");
        printf("1 - Jogador 1 vs Jogador 2\n");
        printf("2 - Jogador vs Computador\n");
        printf("\nResultados: \n");
        printf("    3 - Jogador 1 vs Jogador 2\n");
        printf("    4 - Jogador vs Computador\n");
        printf("5 - Terminar Jogo\n");
        printf("------------------------------------\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        putchar('\n');

        switch (opcao) {
            case 1:
                //jogar_jogador(&r);
                jogar2(&r);
                break;
            case 2:
                jogarComputador(&s);
                break;
            case 3:
                resultados_jogos(r);
                break;
            case 4:
                resultadosJogosComputador(s, 9);
                break;
            default:
                break;
        }
    } while (opcao != 5);
}
