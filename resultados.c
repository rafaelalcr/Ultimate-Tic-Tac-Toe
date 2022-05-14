#include "resultados.h"

void escreve_resultado(jogo *r, int ganhou) {
    printf("\n------------------------------------\n");
    printf("|             RESULTADO            |\n");
    printf("------------------------------------\n\n");
    if(ganhou == 0)
        printf("\nEmpate no jogo %d.\n\n", r->aux);
    else
        printf("\nO jogador %d ganhou o jogo %d.\n\n", ganhou, r->aux);
    printf("\n------------------------------------\n");
    printf("|        CONTINUACAO DO JOGO       |\n");
    printf("------------------------------------\n");
}

void escreve_resultadoFinal(int ganhou) {
    printf("------------------------------------\n");
    printf("|          RESULTADO FINAL         |\n");
    printf("------------------------------------\n\n");
    if(ganhou == 0)
        printf("\nEmpate.\n\n");
    else
        printf("\nGanhou o jogador %d.\n\n", ganhou);
}

void resultados_jogos(jogo r) {
    printf("------------------------------------\n");
    printf("|        RESULTADO DOS JOGOS       |\n");
    printf("------------------------------------\n\n");
    if(r.contadorjogos == 0)
        printf("Sem resultados.\n\n");
    else {
        for(int i=0; i < N*N; i++) {
            if(r.vencedortab[i] == 0)
                printf("Houve um empate no jogo %d\n", i+1);
            else
                printf("Jogador %d ganhou o jogo %d\n", r.vencedortab[i], i+1);
        }
        tabuleiro_final(&r);
    }
}

void tabuleiro_final(jogo *r) {
    char **mat = NULL;
    printf("------------------------------------\n");
    printf("|          TABULEIRO FINAL         |\n");
    printf("------------------------------------\n\n");

    r->vencedortabfinal = 0;
    mat = criaMat(N, N);

    for(int i=0; i < N*N; i++) {
        if(r->vencedortab[i] == 1)                  // Se o jogador 1 ganhou
            setPos(mat, i/N, i%N, 'X');
        else if(r->vencedortab[i] == 2)             // Se o jogador 2 ganhou
            setPos(mat, i/N, i%N, 'O');
        else if(r->vencedortab[i] == 0)             // Se empatou
            setPos(mat, i/N, i%N, '#');
    }

    if(verifica(mat, N) == 1)
        r->vencedortabfinal = 1;
    else if(verifica(mat, N) == -1)
        r->vencedortabfinal = 2;
    else if(verifica(mat, N) == 0)
        r->vencedortabfinal = 0;

    mostraMat(mat, N, N);
    escreve_resultadoFinal(r->vencedortabfinal);
    libertaMat(mat, N);
    putchar('\n');
}