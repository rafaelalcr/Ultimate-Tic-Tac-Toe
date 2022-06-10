// Rafaela Fonseca Santos nº 2017019717

#include "jogo.h"
#include "listaligada.h"
#include "resultados.h"

void inicializar(jogo *r) {
    r->njogos = 0;
    r->njogadas = 0;
    r->posicao = 0;
    r->njogador = 1;
    r->vencedor = 0;
    r->vencedortabfinal = 0;
    r->ntabuleiro = 0;
    r->ntabuleiro_ant = 0;
    r->interrupcao = 0;

    for(int i=0; i<N; i++)
        r->tab_jogadas[i] = EM_JOGO;

    for(int i=0; i<N; i++)
        r->tab_terminados[i] = EM_JOGO;

    for(int i=0; i<N; i++)
        r->tab_vencedores[i] = EM_JOGO;
}

void inicio_jogo(jogo *r) {
    printf("------------------------------------\n");
    printf("|          INICIO DO JOGO          |\n");
    printf("------------------------------------\n");

    initRandom();
    r->ntabuleiro = intUniformRnd(1, 9);
    printf("\n-> Jogar para o tabuleiro %d\n\n", r->ntabuleiro);
}

void jogar_jogador(jogo *r) {
    char **mat = NULL, *nomeF = NULL;
    pjogada lista = NULL;

    inicializar(r);
    lista = recuperarjogo(lista);
    inicio_jogo(r);
    mat = criaMat(N, N);

    do {
        mostraMat(mat, N, N);
        jogada(r, mat, M, r->njogador);

        if (verifica(mat, r->ntabuleiro_ant) == 1 || verifica(mat, r->ntabuleiro_ant) == -1) {
            r->vencedor = r->njogador;
            mostraMat(mat, N, N);
            escreve_resultado(r, r->vencedor);

        } else if (verifica(mat, r->ntabuleiro_ant) == 0 && r->tab_jogadas[r->ntabuleiro_ant - 1] == 9) {
            r->vencedor = EMPATE;
            mostraMat(mat, N, N);
            escreve_resultado(r, r->vencedor);
        }

        lista = insereinfo(lista, r->njogador, r->ntabuleiro_ant, r->posicao, r->njogadas, r->njogos,
                           r->tab_vencedores, r->tab_terminados, r->tab_jogadas);

        if (r->njogos < N && r->njogadas < N*N) {   // para não aparecer quando o jogo tiver terminado
            listajogadas(lista);
            r->interrupcao = interrompejogo(lista);
        }

        if (r->interrupcao != 1 && r->njogos < N && r->njogadas < N*N) {
            r->njogador = r->njogador % 2 + 1;
            printf("\n-> Jogar para o tabuleiro %d\n\n", r->posicao);
        }

    } while (r->interrupcao != 1 && r->njogos < N && r->njogadas < N*N);

    //if(r->interrupcao == 0)   // o jogo é guardado só quando todos os tabuleiros foram terminados
        gravalistatxt(lista);

    libertaMat(mat, N);
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
        default:
            break;
    }

    r->tab_jogadas[r->ntabuleiro_ant - 1]++;   // aux-1 porque o aux começa com valor 1, array tem que começar com índice 0
}

void escolhe_jogada(jogo *r, char **mat, int dim, int x, int y, int njogador) {
    int valor;

    do {
        printf("Posicao: ");
        valor = scanf("%d", &r->posicao);
        putchar('\n');

        if (valor == 0) {
            fputs ("Opcao invalida.\n\n", stderr);
            empty_stdin();
        }

    } while(r->posicao < 1 || r->posicao > N || mat[(r->posicao-1)/dim + x][(r->posicao-1)%dim + y] != '_');

    if(njogador == 1)
        setPos(mat, (r->posicao-1)/dim + x, (r->posicao-1)%dim + y, 'X');
    else
        setPos(mat, (r->posicao-1)/dim + x, (r->posicao-1)%dim + y, 'O');

    r->ntabuleiro = r->posicao;
    r->njogadas++;
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
    contador = 0;
    for (linha = linInicial; linha < linMax; ++linha) {
        for (coluna = colInicial; coluna < colMax; ++coluna) {
            contador += (mat[linha][coluna] == 'X') ? 1 :
                        (mat[linha][coluna] == 'O') ? -1 : 0;
        }
        if (contador == 3 || contador == -3)
            return contador / abs(contador);
    }

    // Verifica Colunas
    contador = 0;
    for (coluna = colInicial; coluna < colMax; ++coluna) {
        for (linha = linInicial; linha < linMax; ++linha) {
            contador += (mat[linha][coluna] == 'X') ? 1 :
                        (mat[linha][coluna] == 'O') ? -1 : 0;
        }
        if (contador == 3 || contador == -3)
            return contador / abs(contador);
    }

    /*              Verifica Diagonal \               */
    contador = 0;
    for (linha = linInicial; linha < linMax; ++linha) {
        contador += (mat[linha][linha] == 'X') ? 1 :
                    (mat[linha][linha] == 'O') ? -1 : 0;
    }
    if (contador == 3 || contador == -3)
        return contador / abs(contador);

    /*               Verifica Diagonal /                  */
    contador = 0;
    for (linha = linInicial, coluna = 2; linha < linMax && coluna >= 0; ++linha, --coluna) {
        contador += (mat[linha][coluna] == 'X') ? 1 :
                    (mat[linha][coluna] == 'O') ? -1 : 0;
    }
    if (contador == 3 || contador == -3)
        return contador / abs(contador);

    return 0;
}