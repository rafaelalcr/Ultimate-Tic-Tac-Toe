// Rafaela Fonseca Santos nº 2017019717

#include "menu.h"

void menu() {
    jogo r;
    jogoC s;
    int opcao, valor;
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
        valor = scanf("%d", &opcao);
        putchar('\n');

        if (valor == 0) {   // impedir que seja introduzido algo diferente de um inteiro
            fputs ("Opcao invalida.\n\n", stderr);
            empty_stdin();
        }

        switch (opcao) {
            case 1:
                jogar_jogador(&r);
                break;
            case 2:
                jogar_computador(&s);
                break;
            case 3:
                resultados_jogos(r);
                break;
            case 4:
                resultados_jogosC(s);
                break;
            default:
                break;
        }
    } while (opcao != 5);
}