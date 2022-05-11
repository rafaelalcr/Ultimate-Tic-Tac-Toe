#include "jogoC.h"

void jogarComputador(jogoC *r) {
    char **mat = NULL;
    int n_jogador, n_jogadas, n_jogos = 0, ganhou;

    r->contadorjogos = 0;

    do {
        ganhou = 0;
        n_jogadas = 0;
        n_jogador = 1;

        printf("------------------------------------\n");
        printf("|         INICIO DO JOGO %d         |\n", n_jogos + 1);
        printf("------------------------------------\n\n");
        mat = criaMat(N, N);
        do {
            mostraMat(mat, N, N);
            escolhe_jogadaComputador(mat, N, n_jogador);
            n_jogadas++;
            if(verifica(mat, N) == 1 || verifica(mat, N) == -1) {     // Se returnar 1 ('X') ou -1 ('O')
                ganhou = n_jogador;
                r->resminitab[n_jogos] = n_jogador;
            }
            else
                n_jogador = n_jogador % 2 + 1;
        }while(ganhou == 0 && n_jogadas < N*N);

        mostraMat(mat, N, N);
        escreve_resultadoComputador(ganhou);
        libertaMat(mat, N);

        n_jogos++;
        r->contadorjogos++;

    } while (n_jogos < N * N);
}

void escolhe_jogadaComputador(char **p, int n, int n_jogador) {
    int pos;

    if(n_jogador == 1) {
        printf("\n-> Vez do jogador \n");
        do{
            printf("Posicao: ");
            scanf("%d", &pos);
            putchar('\n');
        }while(pos<1 || pos>n*n || p[(pos-1)/n][(pos-1)%n] != '_');
    }
    else if(n_jogador == 2) {
        printf("\n-> Vez do computador \n");
        do {
            pos = intUniformRnd(1, 9);
        } while(pos<1 || pos>n*n || p[(pos-1)/n][(pos-1)%n] != '_');
    }

    if(n_jogador == 1)
        setPos(p, (pos-1)/n, (pos-1)%n, 'X');
    else
        setPos(p, (pos-1)/n, (pos-1)%n, 'O');
}

void escreve_resultadoComputador(int ganhou) {
    printf("\n------------------------------------\n");
    printf("|             RESULTADO            |\n");
    printf("------------------------------------\n");
    if(ganhou == 0)
        printf("\nEmpate.\n\n");
    else if(ganhou == 1)
        printf("\nGanhou o jogador.\n\n");
    else if(ganhou == 2)
        printf("\nGanhou o computador.\n\n");
}

void escreve_resultadoFinalComputador(int ganhou) {
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

void resultadosJogosComputador(jogoC r, int n_jogos) {
    printf("------------------------------------\n");
    printf("|        RESULTADO DOS JOGOS       |\n");
    printf("------------------------------------\n\n");
    if(r.contadorjogos == 0) {
        printf("Sem resultados.\n\n");
    }
    else {
        for(int i=0; i < n_jogos; i++) {
            if(r.resminitab[i] == 1)
                printf("Jogador ganhou o jogo %d\n", i+1);
            else if(r.resminitab[i] == 2)
                printf("Computador ganhou o jogo %d\n", i+1);
            else if(r.resminitab[i] == 0)
                printf("Empate no jogo %d\n", i+1);
        }
        tabuleiroFinalComputador(&r);
    }
}

void tabuleiroFinalComputador(jogoC *r) {
    char **mat = NULL;
    printf("\n------------------------------------\n");
    printf("|          TABULEIRO FINAL         |\n");
    printf("------------------------------------\n\n");
    r->restabfinal = 0;
    mat = criaMat(N, N);
    for(int i=0; i < N*N; i++) {
        if(r->resminitab[i] == 1) {                 // Se o jogador 1 ganhou
            setPos(mat, i/N, i%N, 'X');
        }
        else if(r->resminitab[i] == 2) {            // Se o jogador 2 ganhou
            setPos(mat, i/N, i%N, 'O');
        }
        else if(r->resminitab[i] == 0) {            // Se empatou
            setPos(mat, i/N, i%N, '#');
        }
    }

    if(verifica(mat, N) == 1)
        r->restabfinal = 1;
    else if(verifica(mat, N) == -1)
        r->restabfinal = 2;
    else if(verifica(mat, N) == 0)
        r->restabfinal = 0;

    mostraMat(mat, N, N);
    escreve_resultadoFinalComputador(r->restabfinal);
    libertaMat(mat, N);
    putchar('\n');
}

