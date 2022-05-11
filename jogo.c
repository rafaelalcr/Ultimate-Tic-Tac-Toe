#include "jogo.h"

void jogar_jogador(jogo *r) {
    char **t1 = NULL, **t2 = NULL, **t3 = NULL, **t4 = NULL, **t5 = NULL;
    char **t6 = NULL, **t7 = NULL, **t8 = NULL, **t9 = NULL;
    //char **mat = NULL;
    int n_jogador, n_jogadas, ganhou;

    t1 = criaMat(N, N); t2 = criaMat(N, N); t3 = criaMat(N, N); t4 = criaMat(N, N); t5 = criaMat(N, N);
    t6 = criaMat(N, N); t7 = criaMat(N, N); t8 = criaMat(N, N); t9 = criaMat(N, N);

    pjogo p;
    r->contadorjogos = 0;

    initRandom();
    r->posicaojogada = intUniformRnd(1, 9);
    escolhe_tabuleiro(r->posicaojogada);

    do {
        ganhou = 0;
        n_jogadas = 0;
        n_jogador = 1;

        if(r->posicaojogada == 1) {
            do {
                mostraMat(t1, N, N);
                escolhe_jogada(r, t1, N, n_jogador);
                for(int i=0; i<N*N; i++) {          // verificar se o tabuleiro para onde se vai jogar está disponivel
                    if(r->posicaojogada == r->resminitab[i]) {
                        printf("Jogo do tabuleiro %d ja foi terminado.\n", r->posicaojogada);
                        escolhe_jogada(r, t1, N, n_jogador);
                    }
                }
                mostraMat(t1, N, N);

                if(verifica(t1, N) == 1 || verifica(t1, N) == -1) {     // Se returnar 1 ('X') ou -1 ('O')
                    ganhou = n_jogador;
                    r->resminitab[0] = n_jogador;                       // guarda num array quem ganha cada jogo
                    escreve_resultado(ganhou);
                    libertaMat(t1, N);
                    r->contadorjogos++;                                 // contador para o número de jogos já terminados
                }
                else {
                    n_jogador = n_jogador % 2 + 1;
                    escolhe_tabuleiro(r->posicaojogada);                // vai para o tabuleiro seguinte
                    p = p->prox;                                        // vai para a matriz seguinte
                }

            }while(ganhou == 0 && n_jogadas < N*N);
        }
        else if(r->posicaojogada == 2) {
            do {
                mostraMat(t2, N, N);
                escolhe_jogada(r, t2, N, n_jogador);
                for(int i=0; i<N*N; i++) {
                    if(r->posicaojogada == r->resminitab[i]) {
                        printf("Jogo do tabuleiro %d ja foi terminado.\n", r->posicaojogada);
                        escolhe_jogada(r, t2, N, n_jogador);
                    }
                }
                mostraMat(t2, N, N);

                if(verifica(t2, N) == 1 || verifica(t2, N) == -1) {
                    ganhou = n_jogador;
                    r->resminitab[1] = n_jogador;
                    escreve_resultado(ganhou);
                    libertaMat(t2, N);
                    r->contadorjogos++;
                }
                else {
                    n_jogador = n_jogador % 2 + 1;
                    escolhe_tabuleiro(r->posicaojogada);
                    p = p->prox;
                }

            }while(ganhou == 0 && n_jogadas < N*N);
        }
        else if(r->posicaojogada == 3) {
            do {
                mostraMat(t3, N, N);
                escolhe_jogada(r, t3, N, n_jogador);
                for(int i=0; i<N*N; i++) {
                    if(r->posicaojogada == r->resminitab[i]) {
                        printf("Jogo do tabuleiro %d ja foi terminado.\n", r->posicaojogada);
                        escolhe_jogada(r, t3, N, n_jogador);
                    }
                }
                mostraMat(t3, N, N);

                if(verifica(t3, N) == 1 || verifica(t3, N) == -1) {
                    ganhou = n_jogador;
                    r->resminitab[2] = n_jogador;
                    escreve_resultado(ganhou);
                    libertaMat(t3, N);
                    r->contadorjogos++;
                }
                else {
                    n_jogador = n_jogador % 2 + 1;
                    escolhe_tabuleiro(r->posicaojogada);
                    p = p->prox;
                }

            }while(ganhou == 0 && n_jogadas < N*N);
        }
        else if(r->posicaojogada == 4) {
            do {
                mostraMat(t4, N, N);
                escolhe_jogada(r, t4, N, n_jogador);
                for(int i=0; i<N*N; i++) {
                    if(r->posicaojogada == r->resminitab[i]) {
                        printf("Jogo do tabuleiro %d ja foi terminado.\n", r->posicaojogada);
                        escolhe_jogada(r, t4, N, n_jogador);
                    }
                }
                mostraMat(t4, N, N);

                if(verifica(t4, N) == 1 || verifica(t4, N) == -1) {
                    ganhou = n_jogador;
                    r->resminitab[3] = n_jogador;
                    escreve_resultado(ganhou);
                    libertaMat(t4, N);
                    r->contadorjogos++;
                }
                else {
                    n_jogador = n_jogador % 2 + 1;
                    escolhe_tabuleiro(r->posicaojogada);
                    p = p->prox;
                }

            }while(ganhou == 0 && n_jogadas < N*N);
        }
        else if(r->posicaojogada == 5) {
            do {
                mostraMat(t5, N, N);
                escolhe_jogada(r, t5, N, n_jogador);
                for(int i=0; i<N*N; i++) {
                    if(r->posicaojogada == r->resminitab[i]) {
                        printf("Jogo do tabuleiro %d ja foi terminado.\n", r->posicaojogada);
                        escolhe_jogada(r, t5, N, n_jogador);
                    }
                }
                mostraMat(t5, N, N);

                if(verifica(t5, N) == 1 || verifica(t5, N) == -1) {
                    ganhou = n_jogador;
                    r->resminitab[4] = n_jogador;
                    escreve_resultado(ganhou);
                    libertaMat(t5, N);
                    r->contadorjogos++;
                }
                else {
                    n_jogador = n_jogador % 2 + 1;
                    escolhe_tabuleiro(r->posicaojogada);
                    p = p->prox;
                }

            }while(ganhou == 0 && n_jogadas < N*N);
        }
        else if(r->posicaojogada == 6) {
            do {
                mostraMat(t6, N, N);
                escolhe_jogada(r, t6, N, n_jogador);
                for(int i=0; i<N*N; i++) {
                    if(r->posicaojogada == r->resminitab[i]) {
                        printf("Jogo do tabuleiro %d ja foi terminado.\n", r->posicaojogada);
                        escolhe_jogada(r, t6, N, n_jogador);
                    }
                }
                mostraMat(t6, N, N);

                if(verifica(t6, N) == 1 || verifica(t6, N) == -1) {
                    ganhou = n_jogador;
                    r->resminitab[5] = n_jogador;
                    escreve_resultado(ganhou);
                    libertaMat(t6, N);
                    r->contadorjogos++;
                }
                else {
                    n_jogador = n_jogador % 2 + 1;
                    escolhe_tabuleiro(r->posicaojogada);
                    p = p->prox;
                }

            }while(ganhou == 0 && n_jogadas < N*N);
        }
        else if(r->posicaojogada == 7) {
            do {
                mostraMat(t7, N, N);
                escolhe_jogada(r, t7, N, n_jogador);
                for(int i=0; i<N*N; i++) {
                    if(r->posicaojogada == r->resminitab[i]) {
                        printf("Jogo do tabuleiro %d ja foi terminado.\n", r->posicaojogada);
                        escolhe_jogada(r, t7, N, n_jogador);
                    }
                }
                mostraMat(t7, N, N);

                if(verifica(t7, N) == 1 || verifica(t7, N) == -1) {
                    ganhou = n_jogador;
                    r->resminitab[6] = n_jogador;
                    escreve_resultado(ganhou);
                    libertaMat(t7, N);
                    r->contadorjogos++;
                }
                else {
                    n_jogador = n_jogador % 2 + 1;
                    escolhe_tabuleiro(r->posicaojogada);
                    p = p->prox;
                }

            }while(ganhou == 0 && n_jogadas < N*N);
        }
        else if(r->posicaojogada == 8) {
            do {
                mostraMat(t8, N, N);
                escolhe_jogada(r, t8, N, n_jogador);
                for(int i=0; i<N*N; i++) {
                    if(r->posicaojogada == r->resminitab[i]) {
                        printf("Jogo do tabuleiro %d ja foi terminado.\n", r->posicaojogada);
                        escolhe_jogada(r, t8, N, n_jogador);
                    }
                }
                mostraMat(t8, N, N);

                if(verifica(t8, N) == 1 || verifica(t8, N) == -1) {
                    ganhou = n_jogador;
                    r->resminitab[7] = n_jogador;
                    escreve_resultado(ganhou);
                    libertaMat(t8, N);
                    r->contadorjogos++;
                }
                else {
                    n_jogador = n_jogador % 2 + 1;
                    escolhe_tabuleiro(r->posicaojogada);
                    p = p->prox;
                }

            }while(ganhou == 0 && n_jogadas < N*N);
        }
        else if(r->posicaojogada == 9) {
            do {
                mostraMat(t9, N, N);
                escolhe_jogada(r, t9, N, n_jogador);
                for(int i=0; i<N*N; i++) {
                    if(r->posicaojogada == r->resminitab[i]) {
                        printf("Jogo do tabuleiro %d ja foi terminado.\n", r->posicaojogada);
                        escolhe_jogada(r, t9, N, n_jogador);
                    }
                }
                mostraMat(t9, N, N);

                if(verifica(t9, N) == 1 || verifica(t9, N) == -1) {
                    ganhou = n_jogador;
                    r->resminitab[8] = n_jogador;
                    escreve_resultado(ganhou);
                    libertaMat(t9, N);
                    r->contadorjogos++;
                }
                else {
                    n_jogador = n_jogador % 2 + 1;
                    escolhe_tabuleiro(r->posicaojogada);
                    p = p->prox;
                }

            }while(ganhou == 0 && n_jogadas < N*N);
        }

    } while(r->contadorjogos < N*N);

    libertaMat(t1, 3);  libertaMat(t2, 3);  libertaMat(t3, 3);  libertaMat(t4, 3);  libertaMat(t5, 3);
    libertaMat(t6, 3);  libertaMat(t7, 3);  libertaMat(t8, 3);  libertaMat(t9, 3);

/*
    do {
        ganhou = 0;
        n_jogadas = 0;
        n_jogador = 1;

        mat = criaMat(N, N);

        do {
            mostraMat(mat, N, N);
            escolhe_jogada(r, mat, N, n_jogador);
            n_jogadas++;
            if(verifica(mat, N) == 1 || verifica(mat, N) == -1) {     // Se returnar 1 ('X') ou -1 ('O')
                ganhou = n_jogador;
                r->resminitab[n_jogos] = n_jogador;
            }
            else
                n_jogador = n_jogador % 2 + 1;
        }while(ganhou == 0 && n_jogadas < N*N);

        mostraMat(mat, N, N);
        escreve_resultado(ganhou);
        libertaMat(mat, N);

        n_jogos++;
        r->contadorjogos++;

    } while (n_jogos < N * N);*/
}

void escolhe_jogada(jogo *r, char **p, int n, int n_jogador) {
    int pos;
    printf("\n-> Vez do jogador %d\n", n_jogador);
    do{
        printf("Posicao: ");
        scanf("%d", &pos);
        putchar('\n');
    }while(pos<1 || pos>n*n || p[(pos-1)/n][(pos-1)%n] != '_');

    if(n_jogador == 1)
        setPos(p, (pos-1)/n, (pos-1)%n, 'X');
    else
        setPos(p, (pos-1)/n, (pos-1)%n, 'O');

    r->posicaojogada = pos;
}

void escolhe_tabuleiro(int posicao) {
    printf("------------------------------------\n");
    printf("|              JOGO %d             |\n", posicao);
    printf("------------------------------------\n\n");
}

int verifica(char **p, int n) {
    int linha, coluna;
    int contador;   // Se chegar a 3 então há 3 'X' em linha/coluna/diagonal
                        // Se chegar a -3 então há 3 'O' em linha/coluna/diagonal
    // Verifica as N linhas
    for(linha = 0; linha < n; ++linha) {
        contador = 0;
        for(coluna=0; coluna < n; ++coluna) {
            contador += (p[linha][coluna] == 'X')?  1 :
            (p[linha][coluna] == 'O')? -1 : 0;
        }
        if (contador == n || contador == -n)        // Se contador = 3 'X' ou 3 'O'
            return contador / abs(contador);        // Returna 1 ou -1
        }

    // Verifica as N colunas
    for(coluna = 0; coluna < n; ++coluna) {
        contador = 0;
        for(linha=0; linha < n; ++linha) {
            contador += (p[linha][coluna] == 'X')?  1 :
            (p[linha][coluna] == 'O')? -1 : 0;
        }
        if (contador == n || contador == -n)    // Se contador = 3 'X' ou 3 'O'
            return contador / abs(contador);    // Returna 1 ou -1
        }

    // Verifica a Diagonal de cima para baixo da esquerda para direita
    contador = 0;
    for(coluna = 0; coluna < n; ++coluna) {
        contador += (p[coluna][coluna] == 'X')?  1 :
        (p[coluna][coluna] == 'O')? -1 : 0;
    }
    if (contador == n || contador == -n)        // Se contador = 3 'X' ou 3 'O'
        return contador / abs(contador);        // Returna 1 ou -1

    // Verifica a Diagonal de baixo para cima da esquerda para direita
    contador = 0;
    for(coluna = 0; coluna < n; ++coluna) {
        contador += (p[coluna][2-coluna] == 'X')?  1 :
        (p[coluna][2-coluna] == 'O')? -1 : 0;
    }
    if (contador == n || contador == -n)        // Se contador = 3 'X' ou 3 'O'
        return contador / abs(contador);        // Returna 1 ou -1

    return 0;
}

void escreve_resultado(int ganhou) {
    printf("------------------------------------\n");
    printf("|             RESULTADO            |\n");
    printf("------------------------------------\n\n");
    if(ganhou == 0)
        printf("\nEmpate.\n\n");
    else
        printf("\nGanhou o jogador %d.\n\n", ganhou);
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

void resultados_jogos(jogo r, int n_jogos) {
    printf("------------------------------------\n");
    printf("|        RESULTADO DOS JOGOS       |\n");
    printf("------------------------------------\n\n");
    if(r.contadorjogos == 0) {
        printf("Sem resultados.\n\n");
    }
    else {
        for(int i=0; i < n_jogos; i++) {
            if(r.resminitab[i] == 0) {
                printf("Empate no jogo %d\n", i+1);
            }
            else {
                printf("Jogador %d ganhou o jogo %d\n", r.resminitab[i], i+1);
            }
        }
        tabuleiro_final(&r);
    }
}

void tabuleiro_final(jogo *r) {
    char **mat = NULL;
    printf("------------------------------------\n");
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
    escreve_resultadoFinal(r->restabfinal);
    libertaMat(mat, N);
    putchar('\n');
}

void criaFicheiroTXT() {
    FILE *f;
    jogo r;
    char *nome = NULL;
    printf("\nNome do ficheiro: ");
    scanf("%s", nome);
    f = fopen(nome, "wt");
    while(fwrite(&r, sizeof(jogo), 1, f) == 1) {

    }
    fclose(f);
}
