// Rafaela Fonseca Santos nº 2017019717

#include "resultadosC.h"

void escreve_resultadoC(jogoC *s, int ganhou) {
    for(int i=0; i<N; i++) {
        if(s->tab_terminados[i] != s->ntabuleiro_ant) { // só mostra o resultado se o nº do tabuleiro não estiver no array
            s->tab_vencedores[s->njogos] = ganhou;
            s->tab_vencedores[s->njogos] = s->ntabuleiro_ant;
            s->njogos++;

            printf("\n------------------------------------\n");
            printf("|             RESULTADO            |\n");
            printf("------------------------------------\n");

            if (ganhou == VITORIA_JOGADOR1)
                printf("\nO jogador ganhou o jogo %d.\n\n", s->ntabuleiro_ant);
            else if (ganhou == VITORIA_JOGADOR2)
                printf("\nO Computador ganhou o jogo %d.\n\n", s->ntabuleiro_ant);
            else if (ganhou == EMPATE)
                printf("\nEmpate no jogo %d.\n\n", s->ntabuleiro_ant);

            printf("\n------------------------------------\n");
            printf("|        CONTINUACAO DO JOGO       |\n");
            printf("------------------------------------\n\n");
        }
    }
}

void resultados_jogosC(jogoC s) {
    printf("------------------------------------\n");
    printf("|        RESULTADO DOS JOGOS       |\n");
    printf("------------------------------------\n\n");

    if(s.njogos == 0) {
        printf("Sem resultados.\n\n");
    }
    else {
        for(int i=0; i < N; i++) {
            if (s.tab_vencedores[i] == VITORIA_JOGADOR1)
                printf("Jogador ganhou o jogo %d\n", s.tab_terminados[i]);
            else if (s.tab_vencedores[i] == VITORIA_JOGADOR2)
                printf("Computador ganhou o jogo %d\n", s.tab_terminados[i]);
            else if (s.tab_vencedores[i] == EMPATE)
                printf("Houve um empate no jogo %d\n", s.tab_terminados[i]);
        }
        tabuleiro_finalC(&s);
    }
}

void tabuleiro_finalC(jogoC *s) {
    char **mat = NULL;

    printf("\n------------------------------------\n");
    printf("|          TABULEIRO FINAL         |\n");
    printf("------------------------------------\n\n");

    mat = criaMat(M, M);

    for(int i = 0; i < N; i++) {
        if(s->tab_vencedores[i] == VITORIA_JOGADOR1)
            setPos(mat, (s->tab_terminados[i]-1)/M, (s->tab_terminados[i]-1)%M, 'X');
        else if(s->tab_vencedores[i] == VITORIA_JOGADOR2)
            setPos(mat, (s->tab_terminados[i]-1)/M, (s->tab_terminados[i]-1)%M, 'O');
        else if(s->tab_vencedores[i] == EMPATE)
            setPos(mat, (s->tab_terminados[i]-1)/M, (s->tab_terminados[i]-1)%M, '#');
    }

    if(verifica_tabuleiroC(mat, 0, 3, 0, 3) == 1)
        s->vencedortabfinal = VITORIA_JOGADOR1;
    else if(verifica_tabuleiroC(mat, 0, 3, 0, 3) == -1)
        s->vencedortabfinal = VITORIA_JOGADOR2;
    else if(verifica_tabuleiroC(mat, 0, 3, 0, 3) == 0)
        s->vencedortabfinal = EMPATE;

    mostraMat(mat, M, M);
    escreve_resultadoFinalC(s->vencedortabfinal);
    libertaMat(mat, M);
    putchar('\n');
}

void escreve_resultadoFinalC(int ganhou) {
    printf("\n------------------------------------\n");
    printf("|          RESULTADO FINAL         |\n");
    printf("------------------------------------\n\n");

    if (ganhou == VITORIA_JOGADOR1)
        printf("\nGanhou o jogador.\n\n");
    else if (ganhou == VITORIA_JOGADOR2)
        printf("\nGanhou o computador.\n\n");
    else if (ganhou == EMPATE)
        printf("\nEmpate.\n\n");
}
