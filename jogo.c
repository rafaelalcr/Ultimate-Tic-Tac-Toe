// Rafaela Fonseca Santos nº 2017019717

#include "jogo.h"
#include "listaligada.h"
#include "resultados.h"

void inicializar(jogo *r) {
    r->contadorjogos = 0;
    r->vencedor = 0;
    r->jogadas = 0;
    r->jogador = 1;
    r->interrupcao = 0;

    r->contadorjogadas[0] = 0;
    r->contadorjogadas[1] = 0;
    r->contadorjogadas[2] = 0;
    r->contadorjogadas[3] = 0;
    r->contadorjogadas[4] = 0;
    r->contadorjogadas[5] = 0;
    r->contadorjogadas[6] = 0;
    r->contadorjogadas[7] = 0;
    r->contadorjogadas[8] = 0;
}

void inicio_jogo(jogo *r) {
    printf("------------------------------------\n");
    printf("|          INICIO DO JOGO          |\n");
    printf("------------------------------------\n");

    initRandom();
    r->tabuleiro = intUniformRnd(1, 9);
    printf("\n-> Jogar para o tabuleiro %d\n\n", r->tabuleiro);
}

void jogar_jogador(jogo *r) {
    char **mat = NULL;
    pjogada lista = NULL;

    lista = recuperarjogo(lista);
    inicio_jogo(r);
    mat = criaMat(N, N);
    inicializar(r);

    do {
        mostraMat(mat, N, N);
        jogada(r, mat, M, r->jogador);
        lista = inserejogada(lista, r->jogador, r->aux, r->posicaojogada, r->jogadas);

        if (verifica(mat, r->aux) == 1 || verifica(mat, r->aux) == -1) {
            r->vencedor = r->jogador;
            mostraMat(mat, N, N);
            escreve_resultado(r, r->vencedor);

        } else if (verifica(mat, r->aux) == 0 && r->contadorjogadas[r->aux - 1] == 9) {
            r->vencedor = 0;
            mostraMat(mat, N, N);
            escreve_resultado(r, r->vencedor);
        }

        listajogadas(lista);
        //r->interrupcao = interrompejogo(lista);

        r->jogador = r->jogador % 2 + 1;
        printf("\n-> Jogar para o tabuleiro %d\n\n", r->posicaojogada);

    } while (r->contadorjogos < N && r->jogadas < N * N /*&& r->interrupcao != 1*/);

    mostraMat(mat, N, N);
    libertaMat(mat, N);
    gravalistatxt(lista, "listajogadas.txt");
    libertalista(lista);
}

void jogada(jogo *r, char **mat, int n, int n_jogador) {
    r->aux = 0;
    printf("\n-> Vez do jogador %d\n", n_jogador);

    switch (r->tabuleiro) {
        case 1:
            escolhe_jogada(r, mat, n, 0, 0, n_jogador);
            r->aux = 1;
            break;
        case 2:
            escolhe_jogada(r, mat, n, 0, 3, n_jogador);
            r->aux = 2;
            break;
        case 3:
            escolhe_jogada(r, mat, n, 0, 6, n_jogador);
            r->aux = 3;
            break;
        case 4:
            escolhe_jogada(r, mat, n, 3, 0, n_jogador);
            r->aux = 4;
            break;
        case 5:
            escolhe_jogada(r, mat, n, 3, 3, n_jogador);
            r->aux = 5;
            break;
        case 6:
            escolhe_jogada(r, mat, n, 3, 6, n_jogador);
            r->aux = 6;
            break;
        case 7:
            escolhe_jogada(r, mat, n, 6, 0, n_jogador);
            r->aux = 7;
            break;
        case 8:
            escolhe_jogada(r, mat, n, 6, 3, n_jogador);
            r->aux = 8;
            break;
        case 9:
            escolhe_jogada(r, mat, n, 6, 6, n_jogador);
            r->aux = 9;
        default:
            break;
    }

    r->contadorjogadas[r->aux - 1]++;   // aux-1 porque o aux começa com valor 1, array tem que começar com índice 0
}

void escolhe_jogada(jogo *r, char **mat, int n, int x, int y, int n_jogador) {
    int value;

    do {
        printf("Posicao: ");
        value = scanf("%d", &r->posicaojogada);
        putchar('\n');

        if (value == 0) {
            fputs ("Opcao invalida.\n\n", stderr);
            empty_stdin();
        }

    } while(r->posicaojogada<1 || r->posicaojogada>N || mat[(r->posicaojogada-1)/n+x][(r->posicaojogada-1)%n+y] != '_');

    if(n_jogador == 1)
        setPos(mat, (r->posicaojogada-1)/n+x, (r->posicaojogada-1)%n+y, 'X');
    else
        setPos(mat, (r->posicaojogada-1)/n+x, (r->posicaojogada-1)%n+y, 'O');

    r->tabuleiro = r->posicaojogada;
    r->jogadas++;
}

int verifica(char **mat, int tabuleiro) {
    switch (tabuleiro) {
        case 1:
            return verifica_tabuleiro(mat, 0, 3, 0, 3);
        case 2:
            return verifica_tabuleiro(mat, 0, 3, 3, 6);
        case 3:
            return verifica_tabuleiro(mat, 0, 3, 6, 9);
        case 4:
            return verifica_tabuleiro(mat, 3, 6, 0, 3);
        case 5:
            return verifica_tabuleiro(mat, 3, 6, 3, 6);
        case 6:
            return verifica_tabuleiro(mat, 3, 6, 6, 9);
        case 7:
            return verifica_tabuleiro(mat, 6, 9, 0, 3);
        case 8:
            return verifica_tabuleiro(mat, 6, 9, 3, 6);
        case 9:
            return verifica_tabuleiro(mat, 6, 9, 6, 9);
        default:
            return 0;
    }
}

int verifica_tabuleiro(char **mat, int nlin, int linMax, int ncol, int colMax) {
    int linha, coluna;
    int contador;                                       // Se o contador chegar a 3, significa que há um vencedor

    for (linha = nlin; linha < linMax; ++linha) {        // Verifica Linha
        contador = 0;
        for (coluna = ncol; coluna < colMax; ++coluna) {
            contador += (mat[linha][coluna] == 'X') ? 1 :
                        (mat[linha][coluna] == 'O') ? -1 : 0;
        }
        if (contador == 3 || contador == -3)            // Se contador = 3 'X' ou 3 'O'
            return contador / abs(contador);            // Returna 1 ou -1
    }

    for (coluna = ncol; coluna < colMax; ++coluna) {    // Verifica Coluna
        contador = 0;
        for (linha = nlin; linha < linMax; ++linha) {
            contador += (mat[linha][coluna] == 'X') ? 1 :
                        (mat[linha][coluna] == 'O') ? -1 : 0;
        }
        if (contador == 3 || contador == -3)
            return contador / abs(contador);
    }

    for (linha = nlin; linha < linMax; ++linha) ;        // vai para a linha pretendida
    contador = 0;
    for (coluna = ncol; coluna < colMax; ++coluna) {    // Verifica Diagonal de cima para baixo da esquerda para direita
        contador += (mat[coluna][coluna] == 'X') ? 1 :
                    (mat[coluna][coluna] == 'O') ? -1 : 0;
    }
    if (contador == 3 || contador == -3)
        return contador / abs(contador);

    for (linha = nlin; linha < linMax; ++linha) ;        // vai para a linha pretendida
    contador = 0;
    for (coluna = ncol; coluna < colMax; ++coluna) {    // Verifica Diagonal de baixo para cima da esquerda para direita
        contador += (mat[coluna][2 - coluna] == 'X') ? 1 :
                    (mat[coluna][2 - coluna] == 'O') ? -1 : 0;
    }
    if (contador == 3 || contador == -3)
        return contador / abs(contador);

    return 0;
}