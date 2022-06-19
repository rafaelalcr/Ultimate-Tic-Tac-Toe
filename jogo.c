// Rafaela Fonseca Santos nº 2017019717

#include "jogo.h"
#include "listaligada.h"
#include "resultados.h"

void jogar_jogador(jogo *r) {
    char **mat = NULL, **tab = NULL;
    pjogada lista = NULL;

    mat = criaMat(N, N);
    tab = criaMat(M, M);

    r->njogos = 0;
    r->njogadas = 0;
    r->posicao = 0;
    r->njogador = 1;
    r->vencedor = 0;
    r->vencedortabfinal = 0;
    r->ntabuleiro = 0;
    r->ntabuleiro_ant = 0;
    r->interrupcao = 0;
    r->estadojogo = EM_JOGO;

    for(int i=0; i<N; i++)
        r->tab_jogadas[i] = EM_JOGO;

    for(int i=0; i<N; i++)
        r->tab_terminados[i] = EM_JOGO;

    lista = recuperarjogo(lista);

    printf("------------------------------------\n");
    printf("|          INICIO DO JOGO          |\n");
    printf("------------------------------------\n");

    initRandom();
    r->ntabuleiro = intUniformRnd(1, 9);

    printf("\n------------------------------------\n");
    printf("|            TABULEIRO %d          |\n", r->ntabuleiro);
    printf("------------------------------------\n\n");

    do {
        mostraMat(mat, N, N);
        jogada(r, mat, M, r->njogador);

        if (verifica(mat, r->ntabuleiro_ant) == 1 || verifica(mat, r->ntabuleiro_ant) == -1) {
            r->vencedor = r->njogador;
            mostraMat(mat, N, N);
            escreve_resultado(r, tab, r->vencedor);
        }
        else if (verifica(mat, r->ntabuleiro_ant) == 0 && r->tab_jogadas[r->ntabuleiro_ant - 1] == 9) {
            r->vencedor = EMPATE;
            mostraMat(mat, N, N);
            escreve_resultado(r, tab, r->vencedor);
        }

        lista = insereinfo(lista, r->njogador, r->ntabuleiro_ant, r->posicao);

        // verifica o tabuleiro final 3x3
        if(verifica_tabuleiro(tab, 0, 3, 0, 3) == 1) {
            r->vencedortabfinal = VITORIA_JOGADOR1;
            mostraMatFinal(tab, M, M);
            escreve_resultadoFinal(r->vencedortabfinal);
            r->estadojogo = JOGO_TERMINADO;
        }
        else if(verifica_tabuleiro(tab, 0, 3, 0, 3) == -1) {
            r->vencedortabfinal = VITORIA_JOGADOR2;
            mostraMatFinal(tab, M, M);
            escreve_resultadoFinal(r->vencedortabfinal);
            r->estadojogo = JOGO_TERMINADO;
        }
        else if(verifica_tabuleiro(tab, 0, 3, 0, 3) == 0 && r->njogos == 9) {
            r->vencedortabfinal = EMPATE;
            mostraMatFinal(tab, M, M);
            escreve_resultadoFinal(r->vencedortabfinal);
            r->estadojogo = JOGO_TERMINADO;
        }

        if(r->estadojogo != JOGO_TERMINADO) {
            listajogadas(lista);
            r->interrupcao = interrompejogo(lista);
        }

        if (r->interrupcao != 1 && r->estadojogo != JOGO_TERMINADO) {
            r->njogador = r->njogador % 2 + 1;
            printf("\n------------------------------------\n");
            printf("|            TABULEIRO %d          |\n", r->ntabuleiro);
            printf("------------------------------------\n\n");
        }

    } while (r->interrupcao != 1 && r->estadojogo != JOGO_TERMINADO && r->njogos < N && r->njogadas < N*N);

    if(r->interrupcao == 0 && r->estadojogo == JOGO_TERMINADO)
        gravalistatxt(lista);
    libertaMat(mat, N);
    libertaMat(tab, M);
    libertalista(lista);
}

void jogada(jogo *r, char **mat, int dim, int njogador) {
    printf("\n-> Vez do jogador %d\n", njogador);

    switch (r->ntabuleiro) {
        case 1:
            escolhe_jogada(r, mat, dim, 0, 0, njogador);
            r->ntabuleiro_ant = 1;
            break;
        case 2:
            escolhe_jogada(r, mat, dim, 0, 3, njogador);
            r->ntabuleiro_ant = 2;
            break;
        case 3:
            escolhe_jogada(r, mat, dim, 0, 6, njogador);
            r->ntabuleiro_ant = 3;
            break;
        case 4:
            escolhe_jogada(r, mat, dim, 3, 0, njogador);
            r->ntabuleiro_ant = 4;
            break;
        case 5:
            escolhe_jogada(r, mat, dim, 3, 3, njogador);
            r->ntabuleiro_ant = 5;
            break;
        case 6:
            escolhe_jogada(r, mat, dim, 3, 6, njogador);
            r->ntabuleiro_ant = 6;
            break;
        case 7:
            escolhe_jogada(r, mat, dim, 6, 0, njogador);
            r->ntabuleiro_ant = 7;
            break;
        case 8:
            escolhe_jogada(r, mat, dim, 6, 3, njogador);
            r->ntabuleiro_ant = 8;
            break;
        case 9:
            escolhe_jogada(r, mat, dim, 6, 6, njogador);
            r->ntabuleiro_ant = 9;
            break;
        default:
            break;
    }

    r->tab_jogadas[r->ntabuleiro_ant - 1]++;
}

void escolhe_jogada(jogo *r, char **mat, int dim, int x, int y, int njogador) {
    do {
        printf("Posicao: ");
        scanf("%d", &r->posicao);
    } while(r->posicao < 1 || r->posicao > N || mat[(r->posicao-1)/dim + x][(r->posicao-1)%dim + y] != '_');

    if(njogador == 1)
        setPos(mat, (r->posicao-1)/dim + x, (r->posicao-1)%dim + y, 'X');
    else
        setPos(mat, (r->posicao-1)/dim + x, (r->posicao-1)%dim + y, 'O');

    r->ntabuleiro = r->posicao;
    r->njogadas++;
    putchar('\n');
}

int verifica(char **mat, int ntabuleiro) {
    switch (ntabuleiro) {
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

int verifica_tabuleiro(char **mat, int linInicial, int linMax, int colInicial, int colMax) {
    int linha, coluna;
    int contador;

    // Verifica Linhas
    for (linha = linInicial; linha < linMax; ++linha) {
        contador = 0;
        for (coluna = colInicial; coluna < colMax; ++coluna) {
            contador += (mat[linha][coluna] == 'X') ? 1 :
                        (mat[linha][coluna] == 'O') ? -1 : 0;
        }
        if (contador == 3 || contador == -3)
            return contador / abs(contador);
    }

    // Verifica Colunas
    for (coluna = colInicial; coluna < colMax; ++coluna) {
        contador = 0;
        for (linha = linInicial; linha < linMax; ++linha) {
            contador += (mat[linha][coluna] == 'X') ? 1 :
                        (mat[linha][coluna] == 'O') ? -1 : 0;
        }
        if (contador == 3 || contador == -3)
            return contador / abs(contador);
    }

    //              Verifica Diagonal \

    contador = 0;
    for (linha = linInicial; linha < linMax; ++linha) {
        contador += (mat[linha][linha] == 'X') ? 1 :
                    (mat[linha][linha] == 'O') ? -1 : 0;
    }
    if (contador == 3 || contador == -3)
        return contador / abs(contador);

    //               Verifica Diagonal /

    contador = 0;
    for (linha = linInicial, coluna = 2; linha < linMax && coluna >= 0; ++linha, --coluna) {
        contador += (mat[linha][coluna] == 'X') ? 1 :
                    (mat[linha][coluna] == 'O') ? -1 : 0;
    }
    if (contador == 3 || contador == -3)
        return contador / abs(contador);

    return 0;
}