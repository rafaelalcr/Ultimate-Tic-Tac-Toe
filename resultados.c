// Rafaela Fonseca Santos nº 2017019717

#include "resultados.h"

void escreve_resultado(jogo *r, char **tab, int ganhou) {
    // só mostra o resultado se o nº do tabuleiro não estiver no array

    if (r->tab_terminados[0] != r->ntabuleiro_ant && r->tab_terminados[1] != r->ntabuleiro_ant &&
        r->tab_terminados[2] != r->ntabuleiro_ant && r->tab_terminados[3] != r->ntabuleiro_ant &&
        r->tab_terminados[4] != r->ntabuleiro_ant && r->tab_terminados[5] != r->ntabuleiro_ant &&
        r->tab_terminados[6] != r->ntabuleiro_ant && r->tab_terminados[7] != r->ntabuleiro_ant &&
        r->tab_terminados[8] != r->ntabuleiro_ant) {
        r->tab_terminados[r->njogos] = r->ntabuleiro_ant;
        r->njogos++;

        // Há medida que os tabuleiros vão terminando, vai se pondo os caracteres no tabuleiro final
        if(r->vencedor == VITORIA_JOGADOR1)
            setPos(tab, (r->ntabuleiro_ant-1)/M, (r->ntabuleiro_ant-1)%M, 'X');
        else if(r->vencedor == VITORIA_JOGADOR2)
            setPos(tab, (r->ntabuleiro_ant-1)/M, (r->ntabuleiro_ant-1)%M, 'O');
        else if(r->vencedor == EMPATE)
            setPos(tab, (r->ntabuleiro_ant-1)/M, (r->ntabuleiro_ant-1)%M, '#');

        printf("\n------------------------------------\n");
        printf("|             RESULTADO            |\n");
        printf("------------------------------------\n\n");

        if (ganhou == VITORIA_JOGADOR1)
            printf("\nO jogador %d ganhou o jogo %d.\n", VITORIA_JOGADOR1, r->ntabuleiro_ant);
        else if (ganhou == VITORIA_JOGADOR2)
            printf("\nO jogador %d ganhou o jogo %d.\n", VITORIA_JOGADOR2, r->ntabuleiro_ant);
        else if (ganhou == EMPATE)
            printf("\nEmpate no jogo %d.\n", r->ntabuleiro_ant);

        printf("\n\n");
    }
}

void escreve_resultadoFinal(int ganhou) {
    printf("\n------------------------------------\n");
    printf("|          RESULTADO FINAL         |\n");
    printf("------------------------------------\n\n");

    if (ganhou == VITORIA_JOGADOR1)
        printf("\nGanhou o jogador %d.\n", VITORIA_JOGADOR1);
    else if (ganhou == VITORIA_JOGADOR2)
        printf("\nGanhou o jogador %d.\n", VITORIA_JOGADOR2);
    else if (ganhou == EMPATE)
        printf("\nEmpate.\n");
    printf("\n\n");
}

void escreve_resultadoC(jogo *r, char **tab, int ganhou) {
   if (r->tab_terminados[0] != r->ntabuleiro_ant && r->tab_terminados[1] != r->ntabuleiro_ant &&
       r->tab_terminados[2] != r->ntabuleiro_ant && r->tab_terminados[3] != r->ntabuleiro_ant &&
       r->tab_terminados[4] != r->ntabuleiro_ant && r->tab_terminados[5] != r->ntabuleiro_ant &&
       r->tab_terminados[6] != r->ntabuleiro_ant && r->tab_terminados[7] != r->ntabuleiro_ant &&
       r->tab_terminados[8] != r->ntabuleiro_ant) {
        r->tab_terminados[r->njogos] = r->ntabuleiro_ant;
        r->njogos++;

        if(r->vencedor == VITORIA_JOGADOR1)
            setPos(tab, (r->ntabuleiro_ant-1)/M, (r->ntabuleiro_ant-1)%M, 'X');
        else if(r->vencedor == VITORIA_JOGADOR2)
            setPos(tab, (r->ntabuleiro_ant-1)/M, (r->ntabuleiro_ant-1)%M, 'O');
        else if(r->vencedor == EMPATE)
            setPos(tab, (r->ntabuleiro_ant-1)/M, (r->ntabuleiro_ant-1)%M, '#');

        printf("\n------------------------------------\n");
        printf("|             RESULTADO            |\n");
        printf("------------------------------------\n\n");

        if (ganhou == VITORIA_JOGADOR1)
            printf("\nO jogador ganhou o jogo %d.\n", r->ntabuleiro_ant);
        else if (ganhou == VITORIA_JOGADOR2)
            printf("\nO Computador ganhou o jogo %d.\n", r->ntabuleiro_ant);
        else if (ganhou == EMPATE)
            printf("\nEmpate no jogo %d.\n", r->ntabuleiro_ant);

        printf("\n\n");
    }
}

void escreve_resultadoFinalC(int ganhou) {
    printf("\n------------------------------------\n");
    printf("|          RESULTADO FINAL         |\n");
    printf("------------------------------------\n\n");

    if (ganhou == VITORIA_JOGADOR1)
        printf("\nGanhou o jogador.\n");
    else if (ganhou == VITORIA_JOGADOR2)
        printf("\nGanhou o computador.\n");
    else if (ganhou == EMPATE)
        printf("\nEmpate.\n");
    printf("\n\n");
}