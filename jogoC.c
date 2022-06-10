// Rafaela Fonseca Santos nº 2017019717

#include "jogoC.h"
#include "listaligadaC.h"
#include "resultadosC.h"

void inicializarC(jogoC *s) {
    s->njogos = 0;
    s->njogadas = 0;
    s->posicao = 0;
    s->njogador = 1;
    s->vencedor = 0;
    s->vencedortabfinal = 0;
    s->ntabuleiro = 0;
    s->ntabuleiro_ant = 0;
    s->interrupcao = 0;

    for(int i=0; i<N; i++)
        s->tab_jogadas[i] = EM_JOGO;

    for(int i=0; i<N; i++)
        s->tab_terminados[i] = EM_JOGO;

    for(int i=0; i<N; i++)
        s->tab_vencedores[i] = EM_JOGO;

}

void inicio_jogoC(jogoC *s) {
    printf("------------------------------------\n");
    printf("|          INICIO DO JOGO          |\n");
    printf("------------------------------------\n");

    initRandom();
    s->ntabuleiro = intUniformRnd(1, 9);
    printf("\n-> Jogar para o tabuleiro %d\n\n", s->ntabuleiro);
}

void jogar_computador(jogoC *s) {
    char **mat = NULL;
    pjogadaC lista = NULL;

    inicializarC(s);
    lista = recuperarjogoC(lista);
    inicio_jogoC(s);
    mat = criaMat(N, N);

    do {
        mostraMat(mat, N, N);
        jogadaC(s, mat, N, s->njogador);

        if (verificaC(mat, s->ntabuleiro_ant) == 1 || verificaC(mat, s->ntabuleiro_ant) == -1) {
            s->vencedor = s->njogador;
            mostraMat(mat, N, N);
            escreve_resultadoC(s, s->vencedor);
        }
        else if (verificaC(mat, s->ntabuleiro_ant) == 0 && s->tab_jogadas[s->ntabuleiro_ant-1] == 9) {
            s->vencedor = 0;
            mostraMat(mat, N, N);
            escreve_resultadoC(s, s->vencedor);
        }

        lista = insereinfoC(lista, s->njogador, s->ntabuleiro_ant, s->posicao, s->njogadas, s->njogos,
                           s->tab_vencedores, s->tab_terminados, s->tab_jogadas);

        if (s->njogos < N && s->njogadas < N*N) {
            listajogadasC(lista);
            s->interrupcao = interrompejogoC(lista);
        }

        if(s->interrupcao != 1 && s->njogos < N && s->njogadas < N*N) {
            s->njogador = s->njogador % 2 + 1;
            printf("\n-> Jogar para o tabuleiro %d\n\n", s->posicao);
        }

    } while(s->interrupcao != 1 && s->njogos < N && s->njogadas < N*N);

    //if(r->interrupcao == 0)
        gravalistatxtC(lista);

    libertaMat(mat, N);
    libertalistaC(lista);
}

void jogadaC(jogoC *s, char **p, int dim, int njogador) {
    switch (s->ntabuleiro) {
        case 1:
            escolhe_jogadaC(s, p, dim, 0, 0, njogador);
            s->ntabuleiro_ant = 1;
            break;
        case 2:
            escolhe_jogadaC(s, p, dim, 0, 3, njogador);
            s->ntabuleiro_ant = 2;
            break;
        case 3:
            escolhe_jogadaC(s, p, dim, 0, 6, njogador);
            s->ntabuleiro_ant = 3;
            break;
        case 4:
            escolhe_jogadaC(s, p, dim, 3, 0, njogador);
            s->ntabuleiro_ant = 4;
            break;
        case 5:
            escolhe_jogadaC(s, p, dim, 3, 3, njogador);
            s->ntabuleiro_ant = 5;
            break;
        case 6:
            escolhe_jogadaC(s, p, dim, 3, 6, njogador);
            s->ntabuleiro_ant = 6;
            break;
        case 7:
            escolhe_jogadaC(s, p, dim, 6, 0, njogador);
            s->ntabuleiro_ant = 7;
            break;
        case 8:
            escolhe_jogadaC(s, p, dim, 6, 3, njogador);
            s->ntabuleiro_ant = 8;
            break;
        case 9:
            escolhe_jogadaC(s, p, dim, 6, 6, njogador);
            s->ntabuleiro_ant = 9;
        default:
            break;
    }

    s->tab_jogadas[s->ntabuleiro_ant-1]++;
}

void escolhe_jogadaC(jogoC *s, char **mat, int dim, int x, int y, int njogador) {
    int valor;

    if(njogador == 1) {
        printf("\n-> Vez do jogador\n");
        do{
            printf("Posicao: ");
            valor = scanf("%d", &s->posicao);
            putchar('\n');

            if (valor == 0) {
                fputs ("Opcao invalida.\n\n", stderr);
                empty_stdin();
            }

        }while(s->posicao < 1 || s->posicao > N || mat[(s->posicao-1)/dim + x][(s->posicao-1)%dim + y] != '_');
    }
    else if(njogador == 2) {
        printf("\n-> Vez do computador\n");
        do {
            s->posicao = intUniformRnd(1, 9);
        } while(s->posicao < 1 || s->posicao > N || mat[(s->posicao-1)/dim + x][(s->posicao-1)%dim + y] != '_');
    }

    if(njogador == 1)
        setPos(mat, (s->posicao-1)/dim + x, (s->posicao-1)%dim + y, 'X');
    else
        setPos(mat, (s->posicao-1)/dim + x, (s->posicao-1)%dim + y, 'O');

    s->ntabuleiro = s->posicao;
    s->njogadas++;
}

int verificaC(char **mat, int ntabuleiro) {
    switch (ntabuleiro) {
        case 1:
            return verifica_tabuleiroC(mat, 0, 3, 0, 3);
        case 2:
            return verifica_tabuleiroC(mat, 0, 3, 3, 6);
        case 3:
            return verifica_tabuleiroC(mat, 0, 3, 6, 9);
        case 4:
            return verifica_tabuleiroC(mat, 3, 6, 0, 3);
        case 5:
            return verifica_tabuleiroC(mat, 3, 6, 3, 6);
        case 6:
            return verifica_tabuleiroC(mat, 3, 6, 6, 9);
        case 7:
            return verifica_tabuleiroC(mat, 6, 9, 0, 3);
        case 8:
            return verifica_tabuleiroC(mat, 6, 9, 3, 6);
        case 9:
            return verifica_tabuleiroC(mat, 6, 9, 6, 9);
        default:
            return 0;
    }
}

int verifica_tabuleiroC(char **mat, int linInicial, int linMax, int colInicial, int colMax) {
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