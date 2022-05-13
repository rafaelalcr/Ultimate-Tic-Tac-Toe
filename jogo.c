#include "jogo.h"

void jogar(jogo *r) {
    char **mat = NULL;
    r->contadorjogos = 0;

    do {
        r->vencedor = 0;
        r->jogadas = 0;
        r->jogador = 1;

        mat = criaMat(N, N);
        printf("\n\nJogar para o tabuleiro %d.\n\n", r->contadorjogos+1);
        do {
            mostraMat(mat, N, N);
            escolhe_jogada(r, mat, N, r->jogador);
            r->jogadas++;
            if(verifica(mat, N) == 1 || verifica(mat, N) == -1) {
                r->vencedor = r->jogador;
                r->vencedortab[r->contadorjogos] = r->jogador;
            }
            else
                r->jogador = r->jogador % 2 + 1;
        }while(r->vencedor == 0 && r->jogadas < N*N);

        mostraMat(mat, N, N);
        escreve_resultado(r->vencedor);
        libertaMat(mat, N);
        r->contadorjogos++;

    } while (r->contadorjogos < N * N);
}

void jogar2(jogo *r) {
    char **mat = NULL;

    r->contadorjogos = 0;

    printf("------------------------------------\n");
    printf("|          INICIO DO JOGO          |\n");
    printf("------------------------------------\n");

    initRandom();
    r->tabuleiro = intUniformRnd(1, 9);
    escolhe_tabuleiro(r->tabuleiro);

    do {
        r->vencedor = 0;
        r->jogadas = 0;
        r->jogador = 1;

        mat = criaMat(N, N);

        do {
            mostraMat(mat, N, N);
            escolhe_jogada(r, mat, M, r->jogador);
            r->jogadas++;
            if(verifica(mat, M) == 1 || verifica(mat, M) == -1) {
                r->vencedor = r->jogador;
                r->vencedortab[r->contadorjogos] = r->jogador;  // guarda num array quem ganha cada jogo
                escreve_resultado(r->vencedor);
                escolhe_tabuleiro(r->posicaojogada);
                r->contadorjogos++;                             // número de jogos já terminados
            }
            else {
                r->jogador = r->jogador % 2 + 1;
                escolhe_tabuleiro(r->posicaojogada);
            }
        }while(r->jogadas < N*N);

        mostraMat(mat, N, N);

    } while (r->contadorjogos < M * M);

    libertaMat(mat, N);
}

/*
void jogar_jogador(jogo *r) {

    char **t1 = NULL, **t2 = NULL, **t3 = NULL, **t4 = NULL, **t5 = NULL;
    char **t6 = NULL, **t7 = NULL, **t8 = NULL, **t9 = NULL;

    r->contadorjogos = 0;

    initRandom();
    r->posicaojogada = intUniformRnd(1, 9);
    escolhe_tabuleiro(r->posicaojogada);

    do {
        r->vencedor = 0;
        r->jogadas = 0;
        r->jogador = 1;

        t1 = criaMat(N, N); t2 = criaMat(N, N);
        t3 = criaMat(N, N); t4 = criaMat(N, N);
        t5 = criaMat(N, N); t6 = criaMat(N, N);
        t7 = criaMat(N, N); t8 = criaMat(N, N);
        t9 = criaMat(N, N);

        if(r->posicaojogada == 1) {
            do {
                printf("Tabuleiro 1\n");
                mostraMat(t1, N, N);
                escolhe_jogada(r, t1, N, r->jogador);
                for(int i=0; i<N*N; i++) {          // verificar se o tabuleiro para onde se vai jogar está disponivel
                    if(r->posicaojogada == r->vencedortab[i]) {
                        printf("Jogo do tabuleiro %d ja foi terminado.\n", r->posicaojogada);
                        escolhe_jogada(r, t1, N, r->jogador);
                    }
                }
                mostraMat(t1, N, N);

                if(verifica(t1, N) == 1 || verifica(t1, N) == -1) {     // Se returnar 1 ('X') ou -1 ('O')
                    r->vencedor = r->jogador;
                    r->vencedortab[0] = r->jogador;                       // guarda num array quem ganha cada jogo
                    escreve_resultado(r->vencedor);
                    r->contadorjogos++;                                 // contador para o número de jogos já terminados
                    libertaMat(t1, N);
                }
                else {
                    r->jogador = r->jogador % 2 + 1;
                    escolhe_tabuleiro(r->posicaojogada);                // vai para o tabuleiro seguinte
                }
            }while(r->vencedor == 0 && r->jogadas < N*N);
        }
        else if(r->posicaojogada == 2) {
            do {
                printf("Tabuleiro 2\n");
                mostraMat(t2, N, N);
                escolhe_jogada(r, t2, N, r->jogador);
                mostraMat(t2, N, N);

                if(verifica(t2, N) == 1 || verifica(t2, N) == -1) {
                    r->vencedor = r->jogador;
                    r->vencedortab[1] = r->jogador;
                    escreve_resultado(r->vencedor);
                    r->contadorjogos++;
                    libertaMat(t2, N);
                }
                else {
                    r->jogador = r->jogador % 2 + 1;
                    escolhe_tabuleiro(r->posicaojogada);
                }
            }while(r->vencedor == 0 && r->jogadas < N*N);
        }
        else if(r->posicaojogada == 3) {
            do {
                printf("Tabuleiro 3\n");
                mostraMat(t3, N, N);
                escolhe_jogada(r, t3, N, r->jogador);
                mostraMat(t3, N, N);

                if(verifica(t3, N) == 1 || verifica(t3, N) == -1) {
                    r->vencedor = r->jogador;
                    r->vencedortab[2] = r->jogador;
                    escreve_resultado(r->vencedor);
                    r->contadorjogos++;
                    libertaMat(t3, N);
                }
                else {
                    r->jogador = r->jogador % 2 + 1;
                    escolhe_tabuleiro(r->posicaojogada);
                }
            }while(r->vencedor == 0 && r->jogadas < N*N);
        }
        else if(r->posicaojogada == 4) {
            do {
                printf("Tabuleiro 4\n");
                mostraMat(t4, N, N);
                escolhe_jogada(r, t4, N, r->jogador);
                mostraMat(t4, N, N);

                if(verifica(t4, N) == 1 || verifica(t4, N) == -1) {
                    r->vencedor = r->jogador;
                    r->vencedortab[3] = r->jogador;
                    escreve_resultado(r->vencedor);
                    r->contadorjogos++;
                    libertaMat(t4, N);
                }
                else {
                    r->jogador = r->jogador % 2 + 1;
                    escolhe_tabuleiro(r->posicaojogada);
                }
            }while(r->vencedor == 0 && r->jogadas < N*N);
        }
        else if(r->posicaojogada == 5) {
            do {
                printf("Tabuleiro 5\n");
                mostraMat(t5, N, N);
                escolhe_jogada(r, t5, N, r->jogador);
                mostraMat(t5, N, N);

                if(verifica(t5, N) == 1 || verifica(t5, N) == -1) {
                    r->vencedor = r->jogador;
                    r->vencedortab[4] = r->jogador;
                    escreve_resultado(r->vencedor);
                    r->contadorjogos++;
                    libertaMat(t5, N);
                }
                else {
                    r->jogador = r->jogador % 2 + 1;
                    escolhe_tabuleiro(r->posicaojogada);
                }
            }while(r->vencedor == 0 && r->jogadas < N*N);
        }
        else if(r->posicaojogada == 6) {
            do {
                printf("Tabuleiro 6\n");
                mostraMat(t6, N, N);
                escolhe_jogada(r, t6, N, r->jogador);
                mostraMat(t6, N, N);

                if(verifica(t6, N) == 1 || verifica(t6, N) == -1) {
                    r->vencedor = r->jogador;
                    r->vencedortab[5] = r->jogador;
                    escreve_resultado(r->vencedor);
                    r->contadorjogos++;
                    libertaMat(t6, N);
                }
                else {
                    r->jogador = r->jogador % 2 + 1;
                    escolhe_tabuleiro(r->posicaojogada);
                }
            }while(r->vencedor == 0 && r->jogadas < N*N);
        }
        else if(r->posicaojogada == 7) {
            do {
                printf("Tabuleiro 7\n");
                mostraMat(t7, N, N);
                escolhe_jogada(r, t7, N, r->jogador);
                mostraMat(t7, N, N);

                if(verifica(t7, N) == 1 || verifica(t7, N) == -1) {
                    r->vencedor = r->jogador;
                    r->vencedortab[6] = r->jogador;
                    escreve_resultado(r->vencedor);
                    r->contadorjogos++;
                    libertaMat(t7, N);
                }
                else {
                    r->jogador = r->jogador % 2 + 1;
                    escolhe_tabuleiro(r->posicaojogada);
                }
            }while(r->vencedor == 0 && r->jogadas < N*N);
        }
        else if(r->posicaojogada == 8) {
            do {
                printf("Tabuleiro 8\n");
                mostraMat(t8, N, N);
                escolhe_jogada(r, t8, N, r->jogador);
                mostraMat(t8, N, N);

                if(verifica(t8, N) == 1 || verifica(t8, N) == -1) {
                    r->vencedor = r->jogador;
                    r->vencedortab[7] = r->jogador;
                    escreve_resultado(r->vencedor);
                    r->contadorjogos++;
                    libertaMat(t8, N);
                }
                else {
                    r->jogador = r->jogador % 2 + 1;
                    escolhe_tabuleiro(r->posicaojogada);
                }
            }while(r->vencedor == 0 && r->jogadas < N*N);
        }
        else if(r->posicaojogada == 9) {
            do {
                printf("Tabuleiro 9\n");
                mostraMat(t9, N, N);
                escolhe_jogada(r, t9, N, r->jogador);
                mostraMat(t9, N, N);

                if(verifica(t9, N) == 1 || verifica(t9, N) == -1) {
                    r->vencedor = r->jogador;
                    r->vencedortab[8] = r->jogador;
                    escreve_resultado(r->vencedor);
                    r->contadorjogos++;
                    libertaMat(t9, N);
                }
                else {
                    r->jogador = r->jogador % 2 + 1;
                    escolhe_tabuleiro(r->posicaojogada);
                }
            }while(r->vencedor == 0 && r->jogadas < N*N);
        }

        libertaMat(t1, 3);  libertaMat(t2, 3);
        libertaMat(t3, 3);  libertaMat(t4, 3);
        libertaMat(t5, 3);  libertaMat(t6, 3);
        libertaMat(t7, 3);  libertaMat(t8, 3);
        libertaMat(t9, 3);

    } while(r->contadorjogos < N*N);

}
*/

void escolhe_jogada(jogo *r, char **p, int n, int n_jogador) {
    printf("\n-> Vez do jogador %d\n", n_jogador);

    do{
        printf("Posicao: ");
        scanf("%d", &r->posicaojogada);
        putchar('\n');
    }while(r->posicaojogada<1 || r->posicaojogada>n*n || p[(r->posicaojogada-1)/n][(r->posicaojogada-1)%n] != '_');

    if(r->tabuleiro == 1) {
        if(n_jogador == 1)
            setPos(p, (r->posicaojogada-1)/n+0, (r->posicaojogada-1)%n+0, 'X');
        else
            setPos(p, (r->posicaojogada-1)/n+0, (r->posicaojogada-1)%n+0, 'O');
    }
    else if(r->tabuleiro == 2) {
        if(n_jogador == 1)
            setPos(p, (r->posicaojogada-1)/n+0, (r->posicaojogada-1)%n+3, 'X');
        else
            setPos(p, (r->posicaojogada-1)/n+0, (r->posicaojogada-1)%n+3, 'O');
    }
    else if(r->tabuleiro == 3) {
        if(n_jogador == 1)
            setPos(p, (r->posicaojogada-1)/n+0, (r->posicaojogada-1)%n+6, 'X');
        else
            setPos(p, (r->posicaojogada-1)/n+0, (r->posicaojogada-1)%n+6, 'O');
    }
    else if(r->tabuleiro == 4) {
        if(n_jogador == 1)
            setPos(p, (r->posicaojogada-1)/n+3, (r->posicaojogada-1)%n+0, 'X');
        else
            setPos(p, (r->posicaojogada-1)/n+3, (r->posicaojogada-1)%n+0, 'O');
    }
    else if(r->tabuleiro == 5) {
        if(n_jogador == 1)
            setPos(p, (r->posicaojogada-1)/n+3, (r->posicaojogada-1)%n+3, 'X');
        else
            setPos(p, (r->posicaojogada-1)/n+3, (r->posicaojogada-1)%n+3, 'O');
    }
    else if(r->tabuleiro == 6) {
        if(n_jogador == 1)
            setPos(p, (r->posicaojogada-1)/n+3, (r->posicaojogada-1)%n+6, 'X');
        else
            setPos(p, (r->posicaojogada-1)/n+3, (r->posicaojogada-1)%n+6, 'O');
    }
    else if(r->tabuleiro == 7) {
        if(n_jogador == 1)
            setPos(p, (r->posicaojogada-1)/n+6, (r->posicaojogada-1)%n+0, 'X');
        else
            setPos(p, (r->posicaojogada-1)/n+6, (r->posicaojogada-1)%n+0, 'O');
    }
    else if(r->tabuleiro == 8) {
        if(n_jogador == 1)
            setPos(p, (r->posicaojogada-1)/n+6, (r->posicaojogada-1)%n+3, 'X');
        else
            setPos(p, (r->posicaojogada-1)/n+6, (r->posicaojogada-1)%n+3, 'O');
    }
    else if(r->tabuleiro == 9) {
        if(n_jogador == 1)
            setPos(p, (r->posicaojogada-1)/n+6, (r->posicaojogada-1)%n+6, 'X');
        else
            setPos(p, (r->posicaojogada-1)/n+6, (r->posicaojogada-1)%n+6, 'O');
    }

    r->tabuleiro = r->posicaojogada;
}

void escolhe_tabuleiro(int posicao) {
    printf("\n-> Jogar para o tabuleiro %d\n\n", posicao);
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
    printf("\n------------------------------------\n");
    printf("|             RESULTADO            |\n");
    printf("------------------------------------\n\n");
    if(ganhou == 0)
        printf("\nEmpate.\n\n");
    else
        printf("\nGanhou o jogador %d.\n\n", ganhou);
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
