// Rafaela Fonseca Santos nº 2017019717

#include "resultadosC.h"

void escreve_resultadoC(jogoC *s, int ganhou) {
    // se o número do tabuleiro não estiver guardado no array, aparece o resultado
    if(s->minitab[0] != s->aux && s->minitab[1] != s->aux && s->minitab[2] != s->aux &&
       s->minitab[3] != s->aux && s->minitab[4] != s->aux && s->minitab[5] != s->aux &&
       s->minitab[6] != s->aux && s->minitab[7] != s->aux && s->minitab[8] != s->aux) {

        s->vencedortab[s->jogos] = ganhou;
        s->minitab[s->jogos] = s->aux;
        s->jogos++;

        printf("\n------------------------------------\n");
        printf("|             RESULTADO            |\n");
        printf("------------------------------------\n");

        if (ganhou == 0)
            printf("\nEmpate no jogo %d.\n\n", s->aux);
        else if (ganhou == 1)
            printf("\nO jogador ganhou o jogo %d.\n\n", s->aux);
        else if (ganhou == 2)
            printf("\nO computador ganhou o jogo %d.\n\n", s->aux);

        printf("\n------------------------------------\n");
        printf("|        CONTINUACAO DO JOGO       |\n");
        printf("------------------------------------\n\n");
    }
}

void resultados_jogosC(jogoC s) {
    printf("------------------------------------\n");
    printf("|        RESULTADO DOS JOGOS       |\n");
    printf("------------------------------------\n\n");

    if(s.jogos == 0) {
        printf("Sem resultados.\n\n");
    }
    else {
        for(int i=0; i < N; i++) {
            if(s.vencedortab[i] == 1)
                printf("Jogador ganhou o jogo %d\n", s.minitab[i]);
            else if(s.vencedortab[i] == 2)
                printf("Computador ganhou o jogo %d\n", s.minitab[i]);
            else if(s.vencedortab[i] == 0)
                printf("Houve um empate no jogo %d\n", s.minitab[i]);
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
        if(s->vencedortab[i] == 1)
            setPos(mat, (s->minitab[i]-1)/M, (s->minitab[i]-1)%M, 'X');
        else if(s->vencedortab[i] == 2)
            setPos(mat, (s->minitab[i]-1)/M, (s->minitab[i]-1)%M, 'O');
        else if(s->vencedortab[i] == 0)
            setPos(mat, (s->minitab[i]-1)/M, (s->minitab[i]-1)%M, '#');
    }

    if(verifica_tabuleiroC(mat, 0, 3, 0, 3) == 1)
        s->vencedortabfinal = 1;
    else if(verifica_tabuleiroC(mat, 0, 3, 0, 3) == -1)
        s->vencedortabfinal = 2;
    else if(verifica_tabuleiroC(mat, 0, 3, 0, 3) == 0)
        s->vencedortabfinal = 0;

    mostraMat(mat, M, M);
    escreve_resultadoFinalC(s->vencedortabfinal);
    libertaMat(mat, M);
    putchar('\n');
}

void escreve_resultadoFinalC(int ganhou) {
    printf("\n------------------------------------\n");
    printf("|          RESULTADO FINAL         |\n");
    printf("------------------------------------\n\n");

    if(ganhou == 0)
        printf("\nEmpate.\n\n");
    else if(ganhou == 1)
        printf("\nGanhou o jogador.\n\n");
    else if(ganhou == 2)
        printf("\nGanhou o computador.\n\n");
}
