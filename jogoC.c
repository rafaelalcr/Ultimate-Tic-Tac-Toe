// Rafaela Fonseca Santos nº 2017019717

#include "jogoC.h"
#include "listaligadaC.h"
#include "resultadosC.h"

void inicializarC(jogoC *s) {
    s->jogos = 0;
    s->vencedor = 0;
    s->jogadas = 0;
    s->jogador = 1;
    s->interrupcao = 0;

    s->jogadastab[0] = 0;
    s->jogadastab[1] = 0;
    s->jogadastab[2] = 0;
    s->jogadastab[3] = 0;
    s->jogadastab[4] = 0;
    s->jogadastab[5] = 0;
    s->jogadastab[6] = 0;
    s->jogadastab[7] = 0;
    s->jogadastab[8] = 0;

}

void inicio_jogoC(jogoC *s) {
    printf("------------------------------------\n");
    printf("|          INICIO DO JOGO          |\n");
    printf("------------------------------------\n");

    initRandom();
    s->tabuleiro = intUniformRnd(1, 9);
    printf("\n-> Jogar para o tabuleiro %d\n\n", s->tabuleiro);
}

void jogar_computador(jogoC *s) {
    char **mat = NULL;
    pjogadaC lista = NULL;

    lista = recuperarjogoC(lista);
    inicio_jogoC(s);
    mat = criaMat(N, N);
    inicializarC(s);

    do {
        mostraMat(mat, N, N);
        jogadaC(s, mat, N, s->jogador);
        lista = inserejogadaC(lista, s->jogador, s->aux, s->posicao);

        if (verificaC(mat, s->aux) == 1 || verificaC(mat, s->aux) == -1) {
            s->vencedor = s->jogador;
            mostraMat(mat, N, N);
            escreve_resultadoC(s, s->vencedor);
        }
        else if (verificaC(mat, s->aux) == 0 && s->jogadastab[s->aux-1] == 9) {
            s->vencedor = 0;
            mostraMat(mat, N, N);
            escreve_resultadoC(s, s->vencedor);
        }

        listajogadasC(lista);
        s->interrupcao = interrompejogoC(lista);

        if(s->interrupcao != 1) {
            s->jogador = s->jogador % 2 + 1;
            printf("\n-> Jogar para o tabuleiro %d\n\n", s->posicao);
        }

    } while(s->interrupcao != 1 && s->jogos < N && s->jogadas < N*N);

    libertaMat(mat, N);
    gravalistatxtC(lista, "listajogadasC.txt");
    libertalistaC(lista);
}

void jogadaC(jogoC *s, char **p, int n, int n_jogador) {
    s->aux = 0;

    switch (s->tabuleiro) {
        case 1:
            escolhe_jogadaC(s, p, n, 0, 0, n_jogador);
            s->aux = 1;
            break;
        case 2:
            escolhe_jogadaC(s, p, n, 0, 3, n_jogador);
            s->aux = 2;
            break;
        case 3:
            escolhe_jogadaC(s, p, n, 0, 6, n_jogador);
            s->aux = 3;
            break;
        case 4:
            escolhe_jogadaC(s, p, n, 3, 0, n_jogador);
            s->aux = 4;
            break;
        case 5:
            escolhe_jogadaC(s, p, n, 3, 3, n_jogador);
            s->aux = 5;
            break;
        case 6:
            escolhe_jogadaC(s, p, n, 3, 6, n_jogador);
            s->aux = 6;
            break;
        case 7:
            escolhe_jogadaC(s, p, n, 6, 0, n_jogador);
            s->aux = 7;
            break;
        case 8:
            escolhe_jogadaC(s, p, n, 6, 3, n_jogador);
            s->aux = 8;
            break;
        case 9:
            escolhe_jogadaC(s, p, n, 6, 6, n_jogador);
            s->aux = 9;
        default:
            break;
    }

    s->jogadastab[s->aux-1]++;
}

void escolhe_jogadaC(jogoC *s, char **p, int n, int x, int y, int n_jogador) {
    if(n_jogador == 1) {
        printf("\n-> Vez do jogador\n");
        do{
            printf("Posicao: ");
            scanf("%d", &s->posicao);
            putchar('\n');
        }while(s->posicao < 1 || s->posicao > N || p[(s->posicao-1)/n+x][(s->posicao-1)%n+y] != '_');
    }
    else if(n_jogador == 2) {
        printf("\n-> Vez do computador\n");
        do {
            s->posicao = intUniformRnd(1, 9);
        } while(s->posicao < 1 || s->posicao > N || p[(s->posicao-1)/n+x][(s->posicao-1)%n+y] != '_');
    }

    if(n_jogador == 1)
        setPos(p, (s->posicao-1)/n+x, (s->posicao-1)%n+y, 'X');
    else
        setPos(p, (s->posicao-1)/n+x, (s->posicao-1)%n+y, 'O');

    s->tabuleiro = s->posicao;
    s->jogadas++;
}

int verificaC(char **p, int tabuleiro) {
    switch (tabuleiro) {
        case 1:
            return verifica_tabuleiroC(p, 0, 3, 0, 3);
        case 2:
            return verifica_tabuleiroC(p, 0, 3, 3, 6);
        case 3:
            return verifica_tabuleiroC(p, 0, 3, 6, 9);
        case 4:
            return verifica_tabuleiroC(p, 3, 6, 0, 3);
        case 5:
            return verifica_tabuleiroC(p, 3, 6, 3, 6);
        case 6:
            return verifica_tabuleiroC(p, 3, 6, 6, 9);
        case 7:
            return verifica_tabuleiroC(p, 6, 9, 0, 3);
        case 8:
            return verifica_tabuleiroC(p, 6, 9, 3, 6);
        case 9:
            return verifica_tabuleiroC(p, 6, 9, 6, 9);
        default:
            return 0;
    }
}

int verifica_tabuleiroC(char **p, int nlin, int linMax, int ncol, int colMax) {
    int linha, coluna;
    int contador;   // Se chegar a 3 então há 3 'X' em linha/coluna/diagonal
                    // Se chegar a -3 então há 3 'O' em linha/coluna/diagonal

    for(linha = nlin; linha < linMax; ++linha) {
        contador = 0;
        for (coluna = ncol; coluna < colMax; ++coluna) {
            contador += (p[linha][coluna] == 'X') ? 1 :
                        (p[linha][coluna] == 'O') ? -1 : 0;
        }
        if (contador == 3 || contador == -3)        // Se contador = 3 'X' ou 3 'O'
            return contador / abs(contador);        // Returna 1 ou -1
    }

    for (coluna = ncol; coluna < colMax; ++coluna) {
        contador = 0;
        for (linha = nlin; linha < linMax; ++linha) {
            contador += (p[linha][coluna] == 'X') ? 1 :
                        (p[linha][coluna] == 'O') ? -1 : 0;
        }
        if (contador == 3 || contador == -3)
            return contador / abs(contador);
    }

    for (linha = nlin; linha < linMax; ++linha) {        // vai para a linha pretendida
        contador = 0;
        for (coluna = ncol; coluna < colMax; ++coluna) {   // Verifica a Diagonal de cima para baixo da esquerda para direita
            contador += (p[coluna][coluna] == 'X') ? 1 :
                        (p[coluna][coluna] == 'O') ? -1 : 0;
        }
        if (contador == 3 || contador == -3)
            return contador / abs(contador);
    }

    for (linha = nlin; linha < linMax; ++linha) {        // vai para a linha pretendida
        contador = 0;
        for (coluna = ncol; coluna < colMax; ++coluna) {  // Verifica a Diagonal de baixo para cima da esquerda para direita
            contador += (p[coluna][2 - coluna] == 'X') ? 1 :
                        (p[coluna][2 - coluna] == 'O') ? -1 : 0;
        }
        if (contador == 3 || contador == -3)
            return contador / abs(contador);
    }

    return 0;
}