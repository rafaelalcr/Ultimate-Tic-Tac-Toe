// Rafaela Fonseca Santos nº 2017019717

#include "resultados.h"

void resultados_jogos(jogo r) {
    printf("------------------------------------\n");
    printf("|        RESULTADO DOS JOGOS       |\n");
    printf("------------------------------------\n\n");

    if(r.contadorjogos == 0)
        printf("Sem resultados.\n\n");
    else {
        for(int i=0; i < N; i++) {
            if(r.vencedortab[i] == 0)
                printf("Houve um empate no jogo %d\n", r.minitab[i]);
            else
                printf("Jogador %d ganhou o jogo %d\n", r.vencedortab[i], r.minitab[i]);
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
        if(r->vencedortab[i] == 1)
            setPos(mat, (r->minitab[i]-1)/M, (r->minitab[i]-1)%M, 'X');
        else if(r->vencedortab[i] == 2)
            setPos(mat, (r->minitab[i]-1)/M, (r->minitab[i]-1)%M, 'O');
        else if(r->vencedortab[i] == 0)
            setPos(mat, (r->minitab[i]-1)/M, (r->minitab[i]-1)%M, '#');
    }

    if(verifica_tabuleiro(mat, 0, 3, 0, 3) == 1)
        r->vencedortabfinal = 1;
    else if(verifica_tabuleiro(mat, 0, 3, 0, 3) == -1)
        r->vencedortabfinal = 2;
    else if(verifica_tabuleiro(mat, 0, 3, 0, 3) == 0)
        r->vencedortabfinal = 0;

    mostraMatFinal(mat, M, M);
    escreve_resultadoFinal(r->vencedortabfinal);
    libertaMat(mat, M);
    putchar('\n');
}

void escreve_resultadoFinal(int ganhou) {
    printf("\n------------------------------------\n");
    printf("|          RESULTADO FINAL         |\n");
    printf("------------------------------------\n\n");

    if(ganhou == 0)
        printf("\nEmpate.\n\n");
    else
        printf("\nGanhou o jogador %d.\n\n", ganhou);
}