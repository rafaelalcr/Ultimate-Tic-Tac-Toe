// Rafaela Fonseca Santos nº 2017019717

#include "resultados.h"

void escreve_resultado(jogo *r, int ganhou) {
    // só mostra o resultado se o nº do tabuleiro não estiver no array
    if (r->tab_terminados[0] != r->ntabuleiro_ant && r->tab_terminados[1] != r->ntabuleiro_ant &&
        r->tab_terminados[2] != r->ntabuleiro_ant && r->tab_terminados[3] != r->ntabuleiro_ant &&
        r->tab_terminados[4] != r->ntabuleiro_ant && r->tab_terminados[5] != r->ntabuleiro_ant &&
        r->tab_terminados[6] != r->ntabuleiro_ant && r->tab_terminados[7] != r->ntabuleiro_ant &&
        r->tab_terminados[8] != r->ntabuleiro_ant) {

        r->tab_vencedores[r->njogos] = ganhou;
        r->tab_terminados[r->njogos] = r->ntabuleiro_ant;
        r->njogos++;

        printf("\n------------------------------------\n");
        printf("|             RESULTADO            |\n");
        printf("------------------------------------\n\n");

        if (ganhou == VITORIA_JOGADOR1)
            printf("\nO jogador %d ganhou o jogo %d.\n\n", VITORIA_JOGADOR1, r->ntabuleiro_ant);
        else if (ganhou == VITORIA_JOGADOR2)
            printf("\nO jogador %d ganhou o jogo %d.\n\n", VITORIA_JOGADOR2, r->ntabuleiro_ant);
        else if (ganhou == EMPATE)
            printf("\nEmpate no jogo %d.\n\n", r->ntabuleiro_ant);

        printf("\n------------------------------------\n");
        printf("|        CONTINUACAO DO JOGO       |\n");
        printf("------------------------------------\n\n");
    }
}

void resultados_jogos(jogo r) {
    printf("------------------------------------\n");
    printf("|        RESULTADO DOS JOGOS       |\n");
    printf("------------------------------------\n\n");

    if(r.njogos == 0)
        printf("Sem resultados.\n\n");
    else {
        for(int i=0; i < N; i++) {
            if (r.tab_vencedores[i] == VITORIA_JOGADOR1)
                printf("Jogador %d ganhou o jogo %d\n", VITORIA_JOGADOR1, r.tab_terminados[i]);
            else if (r.tab_vencedores[i] == VITORIA_JOGADOR2)
                printf("Jogador %d ganhou o jogo %d\n", VITORIA_JOGADOR2, r.tab_terminados[i]);
            else if (r.tab_vencedores[i] == EMPATE)
                printf("Houve um empate no jogo %d\n", r.tab_terminados[i]);
        }
        tabuleiro_final(&r);
    }
}

void tabuleiro_final(jogo *r) {
    char **mat = NULL;

    printf("\n------------------------------------\n");
    printf("|          TABULEIRO FINAL         |\n");
    printf("------------------------------------\n\n");

    mat = criaMat(M, M);

    for(int i = 0; i < N; i++) {
        if(r->tab_vencedores[i] == VITORIA_JOGADOR1)
            setPos(mat, (r->tab_terminados[i]-1)/M, (r->tab_terminados[i]-1)%M, 'X');
        else if(r->tab_vencedores[i] == VITORIA_JOGADOR2)
            setPos(mat, (r->tab_terminados[i]-1)/M, (r->tab_terminados[i]-1)%M, 'O');
        else if(r->tab_vencedores[i] == EMPATE)
            setPos(mat, (r->tab_terminados[i]-1)/M, (r->tab_terminados[i]-1)%M, '#');
    }

    if(verifica_tabuleiro(mat, 0, 3, 0, 3) == 1)
        r->vencedortabfinal = VITORIA_JOGADOR1;
    else if(verifica_tabuleiro(mat, 0, 3, 0, 3) == -1)
        r->vencedortabfinal = VITORIA_JOGADOR2;
    else if(verifica_tabuleiro(mat, 0, 3, 0, 3) == 0)
        r->vencedortabfinal = EMPATE;

    mostraMatFinal(mat, M, M);
    escreve_resultadoFinal(r->vencedortabfinal);
    libertaMat(mat, M);
    putchar('\n');
}

void escreve_resultadoFinal(int ganhou) {
    printf("\n------------------------------------\n");
    printf("|          RESULTADO FINAL         |\n");
    printf("------------------------------------\n\n");

    if (ganhou == VITORIA_JOGADOR1)
        printf("\nGanhou o jogador %d.\n\n", VITORIA_JOGADOR1);
    else if (ganhou == VITORIA_JOGADOR2)
        printf("\nGanhou o jogador %d.\n\n", VITORIA_JOGADOR2);
    else if (ganhou == EMPATE)
        printf("\nEmpate.\n\n");
}