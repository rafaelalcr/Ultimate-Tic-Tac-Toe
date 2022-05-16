#include "jogo.h"

void jogar_jogador(jogo *r) {
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
            if(linha(mat, M, r->tabuleiro) == 1 || linha(mat, M, r->tabuleiro) == -1) {
                if(coluna(mat, M, r->tabuleiro) == 1 || coluna(mat, M, r->tabuleiro) == -1) {
                    if(diagonal(mat, M, r->tabuleiro) == 1 || diagonal(mat, M, r->tabuleiro) == -1) {
                        r->vencedor = r->jogador;
                        r->vencedortab[r->aux] = r->jogador;  // guarda num array quem ganha cada jogo
                        escreve_resultado(r, r->vencedor);
                        r->contadorjogos++;                  // número de jogos já terminados
                        r->vencedor = 0;
                        escolhe_tabuleiro(r->posicaojogada);
                    }
                }
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

void escolhe_jogada(jogo *r, char **p, int n, int n_jogador) {
    r->aux = 0;
    printf("\n-> Vez do jogador %d\n", n_jogador);

    //do{
        printf("Posicao: ");
        scanf("%d", &r->posicaojogada);
        putchar('\n');
    //}while(r->posicaojogada<1 || r->posicaojogada>n*n || p[(r->posicaojogada-1)/n][(r->posicaojogada-1)%n] != '_');

    if(r->tabuleiro == 1) {
        if(n_jogador == 1)
            setPos(p, (r->posicaojogada-1)/n+0, (r->posicaojogada-1)%n+0, 'X');
        else
            setPos(p, (r->posicaojogada-1)/n+0, (r->posicaojogada-1)%n+0, 'O');
        r->aux = 1;
    }
    else if(r->tabuleiro == 2) {
        if(n_jogador == 1)
            setPos(p, (r->posicaojogada-1)/n+0, (r->posicaojogada-1)%n+3, 'X');
        else
            setPos(p, (r->posicaojogada-1)/n+0, (r->posicaojogada-1)%n+3, 'O');
        r->aux = 2;
    }
    else if(r->tabuleiro == 3) {
        if(n_jogador == 1)
            setPos(p, (r->posicaojogada-1)/n+0, (r->posicaojogada-1)%n+6, 'X');
        else
            setPos(p, (r->posicaojogada-1)/n+0, (r->posicaojogada-1)%n+6, 'O');
        r->aux = 3;
    }
    else if(r->tabuleiro == 4) {
        if(n_jogador == 1)
            setPos(p, (r->posicaojogada-1)/n+3, (r->posicaojogada-1)%n+0, 'X');
        else
            setPos(p, (r->posicaojogada-1)/n+3, (r->posicaojogada-1)%n+0, 'O');
        r->aux = 4;
    }
    else if(r->tabuleiro == 5) {
        if(n_jogador == 1)
            setPos(p, (r->posicaojogada-1)/n+3, (r->posicaojogada-1)%n+3, 'X');
        else
            setPos(p, (r->posicaojogada-1)/n+3, (r->posicaojogada-1)%n+3, 'O');
        r->aux = 5;
    }
    else if(r->tabuleiro == 6) {
        if(n_jogador == 1)
            setPos(p, (r->posicaojogada-1)/n+3, (r->posicaojogada-1)%n+6, 'X');
        else
            setPos(p, (r->posicaojogada-1)/n+3, (r->posicaojogada-1)%n+6, 'O');
        r->aux = 6;
    }
    else if(r->tabuleiro == 7) {
        if(n_jogador == 1)
            setPos(p, (r->posicaojogada-1)/n+6, (r->posicaojogada-1)%n+0, 'X');
        else
            setPos(p, (r->posicaojogada-1)/n+6, (r->posicaojogada-1)%n+0, 'O');
        r->aux = 7;
    }
    else if(r->tabuleiro == 8) {
        if(n_jogador == 1)
            setPos(p, (r->posicaojogada-1)/n+6, (r->posicaojogada-1)%n+3, 'X');
        else
            setPos(p, (r->posicaojogada-1)/n+6, (r->posicaojogada-1)%n+3, 'O');
        r->aux = 8;
    }
    else if(r->tabuleiro == 9) {
        if(n_jogador == 1)
            setPos(p, (r->posicaojogada-1)/n+6, (r->posicaojogada-1)%n+6, 'X');
        else
            setPos(p, (r->posicaojogada-1)/n+6, (r->posicaojogada-1)%n+6, 'O');
        r->aux = 9;
    }

    r->tabuleiro = r->posicaojogada;
}

int linha(char **p, int n, int tabuleiro) {
    int linha, coluna;
    int contador;       // Se chegar a 3 então há 3 'X' em linha. Se chegar a -3 então há 3 'O' em linha

    if(tabuleiro == 1) {
        for(linha = 0; linha < n; ++linha) {
            contador = 0;
            for (coluna = 0; coluna < n; ++coluna) {
                contador += (p[linha][coluna] == 'X') ? 1 :
                            (p[linha][coluna] == 'O') ? -1 : 0;
            }
            if (contador == n || contador == -n)        // Se contador = 3 'X' ou 3 'O'
                return contador / abs(contador);        // Returna 1 ou -1
        }
    }
    else if(tabuleiro == 2) {
        for(linha = 0; linha < n; ++linha) {
            contador = 0;
            for(coluna=n; coluna < 6; ++coluna) {
                contador += (p[linha][coluna] == 'X')?  1 :
                            (p[linha][coluna] == 'O')? -1 : 0;
            }
            if (contador == n || contador == -n)
                return contador / abs(contador);
        }
    }
    else if(tabuleiro == 3) {
        for (linha = 0; linha < n; ++linha) {
            contador = 0;
            for (coluna = 6; coluna < 9; ++coluna) {
                contador += (p[linha][coluna] == 'X') ? 1 :
                            (p[linha][coluna] == 'O') ? -1 : 0;
            }
            if (contador == n || contador == -n)
                return contador / abs(contador);
        }
    }
    else if(tabuleiro == 4) {
        for (linha = n; linha < 6; ++linha) {
            contador = 0;
            for (coluna = 0; coluna < n; ++coluna) {
                contador += (p[linha][coluna] == 'X') ? 1 :
                            (p[linha][coluna] == 'O') ? -1 : 0;
            }
            if (contador == n || contador == -n)
                return contador / abs(contador);
        }
    }
    else if(tabuleiro == 5) {
        for (linha = n; linha < 6; ++linha) {
            contador = 0;
            for (coluna = n; coluna < 6; ++coluna) {
                contador += (p[linha][coluna] == 'X') ? 1 :
                            (p[linha][coluna] == 'O') ? -1 : 0;
            }
            if (contador == n || contador == -n)
                return contador / abs(contador);
        }
    }
    else if(tabuleiro == 6) {
        for (linha = n; linha < 6; ++linha) {
            contador = 0;
            for (coluna = 6; coluna < 9; ++coluna) {
                contador += (p[linha][coluna] == 'X') ? 1 :
                            (p[linha][coluna] == 'O') ? -1 : 0;
            }
            if (contador == n || contador == -n)
                return contador / abs(contador);
        }
    }
    else if(tabuleiro == 7) {
        for (linha = 6; linha < 9; ++linha) {
            contador = 0;
            for (coluna = 0; coluna < n; ++coluna) {
                contador += (p[linha][coluna] == 'X') ? 1 :
                            (p[linha][coluna] == 'O') ? -1 : 0;
            }
            if (contador == n || contador == -n)
                return contador / abs(contador);
        }
    }
    else if(tabuleiro == 8) {
        for (linha = 6; linha < 9; ++linha) {
            contador = 0;
            for (coluna = n; coluna < 6; ++coluna) {
                contador += (p[linha][coluna] == 'X') ? 1 :
                            (p[linha][coluna] == 'O') ? -1 : 0;
            }
            if (contador == n || contador == -n)
                return contador / abs(contador);
        }
    }
    else if(tabuleiro == 9) {
        for (linha = 6; linha < 9; ++linha) {
            contador = 0;
            for (coluna = 6; coluna < 9; ++coluna) {
                contador += (p[linha][coluna] == 'X') ? 1 :
                            (p[linha][coluna] == 'O') ? -1 : 0;
            }
            if (contador == n || contador == -n)
                return contador / abs(contador);
        }
    }
    return 0;
}

int coluna(char **p, int n, int tabuleiro) {
    int linha, coluna;
    int contador;

    if(tabuleiro == 1) {
        for (coluna = 0; coluna < n; ++coluna) {
            contador = 0;
            for (linha = 0; linha < n; ++linha) {
                contador += (p[linha][coluna] == 'X') ? 1 :
                            (p[linha][coluna] == 'O') ? -1 : 0;
            }
            if (contador == n || contador == -n)
                return contador / abs(contador);
        }
    }
    else if(tabuleiro == 2) {
        for (coluna = n; coluna < 6; ++coluna) {
            contador = 0;
            for (linha = 0; linha < n; ++linha) {
                contador += (p[linha][coluna] == 'X') ? 1 :
                            (p[linha][coluna] == 'O') ? -1 : 0;
            }
            if (contador == n || contador == -n)
                return contador / abs(contador);
        }
    }
    else if(tabuleiro == 3) {
        for (coluna = 6; coluna < 9; ++coluna) {
            contador = 0;
            for (linha = 0; linha < n; ++linha) {
                contador += (p[linha][coluna] == 'X') ? 1 :
                            (p[linha][coluna] == 'O') ? -1 : 0;
            }
            if (contador == n || contador == -n)
                return contador / abs(contador);
        }
    }
    else if(tabuleiro == 4) {
        for (coluna = 0; coluna < n; ++coluna) {
            contador = 0;
            for (linha = n; linha < 6; ++linha) {
                contador += (p[linha][coluna] == 'X') ? 1 :
                            (p[linha][coluna] == 'O') ? -1 : 0;
            }
            if (contador == n || contador == -n)
                return contador / abs(contador);
        }
    }
    else if(tabuleiro == 5) {
        for (coluna = n; coluna < 6; ++coluna) {
            contador = 0;
            for (linha = n; linha < 6; ++linha) {
                contador += (p[linha][coluna] == 'X') ? 1 :
                            (p[linha][coluna] == 'O') ? -1 : 0;
            }
            if (contador == n || contador == -n)
                return contador / abs(contador);
        }
    }
    else if(tabuleiro == 6) {
        for (coluna = 6; coluna < 9; ++coluna) {
            contador = 0;
            for (linha = n; linha < 6; ++linha) {
                contador += (p[linha][coluna] == 'X') ? 1 :
                            (p[linha][coluna] == 'O') ? -1 : 0;
            }
            if (contador == n || contador == -n)
                return contador / abs(contador);
        }
    }
    else if(tabuleiro == 7) {
        for (coluna = 0; coluna < n; ++coluna) {
            contador = 0;
            for (linha = 6; linha < 9; ++linha) {
                contador += (p[linha][coluna] == 'X') ? 1 :
                            (p[linha][coluna] == 'O') ? -1 : 0;
            }
            if (contador == n || contador == -n)
                return contador / abs(contador);
        }
    }
    else if(tabuleiro == 8) {
        for (coluna = n; coluna < 6; ++coluna) {
            contador = 0;
            for (linha = 6; linha < 9; ++linha) {
                contador += (p[linha][coluna] == 'X') ? 1 :
                            (p[linha][coluna] == 'O') ? -1 : 0;
            }
            if (contador == n || contador == -n)
                return contador / abs(contador);
        }
    }
    else if(tabuleiro == 9) {
        for (coluna = 6; coluna < 9; ++coluna) {
            contador = 0;
            for (linha = 6; linha < 9; ++linha) {
                contador += (p[linha][coluna] == 'X') ? 1 :
                            (p[linha][coluna] == 'O') ? -1 : 0;
            }
            if (contador == n || contador == -n)
                return contador / abs(contador);
        }
    }
    return 0;
}

int diagonal(char **p, int n, int tabuleiro) {
    int coluna;
    int contador;

    if(tabuleiro == 1 || tabuleiro == 4 || tabuleiro == 7) {
        contador = 0;
        for(coluna = 0; coluna < n; ++coluna) {     // Verifica a Diagonal de cima para baixo da esquerda para direita
            contador += (p[coluna][coluna] == 'X')?  1 :
                        (p[coluna][coluna] == 'O')? -1 : 0;
        }
        if (contador == n || contador == -n)
            return contador / abs(contador);

        contador = 0;
        for (coluna = 0; coluna < n; ++coluna) {    // Verifica a Diagonal de baixo para cima da esquerda para direita
            contador += (p[coluna][2 - coluna] == 'X') ? 1 :
                        (p[coluna][2 - coluna] == 'O') ? -1 : 0;
        }
        if (contador == n || contador == -n)
            return contador / abs(contador);
    }
    else if(tabuleiro == 2 || tabuleiro == 5 || tabuleiro == 8) {
        contador = 0;
        for (coluna = n; coluna < 6; ++coluna) {
            contador += (p[coluna][coluna] == 'X') ? 1 :
                        (p[coluna][coluna] == 'O') ? -1 : 0;
        }
        if (contador == n || contador == -n)
            return contador / abs(contador);

        contador = 0;
        for (coluna = n; coluna < 6; ++coluna) {
            contador += (p[coluna][2 - coluna] == 'X') ? 1 :
                        (p[coluna][2 - coluna] == 'O') ? -1 : 0;
        }
        if (contador == n || contador == -n)
            return contador / abs(contador);
    }
    else if(tabuleiro == 3 || tabuleiro == 6 || tabuleiro == 9) {
        contador = 0;
        for (coluna = 6; coluna < 9; ++coluna) {
            contador += (p[coluna][coluna] == 'X') ? 1 :
                        (p[coluna][coluna] == 'O') ? -1 : 0;
        }
        if (contador == n || contador == -n)
            return contador / abs(contador);

        contador = 0;
        for (coluna = 6; coluna < 9; ++coluna) {
            contador += (p[coluna][2 - coluna] == 'X') ? 1 :
                        (p[coluna][2 - coluna] == 'O') ? -1 : 0;
        }
        if (contador == n || contador == -n)
            return contador / abs(contador);
    }

    return 0;
}

void escolhe_tabuleiro(int posicao) {
    printf("\n-> Jogar para o tabuleiro %d\n\n", posicao);
}