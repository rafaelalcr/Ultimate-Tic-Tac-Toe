// Rafaela Fonseca Santos nº 2017019717

#include "jogoC.h"
#include "listaligadaC.h"
#include "resultados.h"

void jogar_computador(jogoC *s) {
    char **mat = NULL;
    pjogadaC lista = NULL;

    // permitir a continuação de um jogo anterior caso o ficheiro exista
    int resposta;
    FILE *f;
    f = fopen("jogoC.bin", "rb");
    if(f != NULL) {
        printf("Deseja recuperar o jogo? (Sim: 1)\n");
        scanf("%d", &resposta);
        if(resposta == 1) {
            lista = recuperalistaC("jogoC.bin");
            printf("Jogo recuperado.\n");
        }
        putchar('\n');
    }

    printf("------------------------------------\n");
    printf("|          INICIO DO JOGO          |\n");
    printf("------------------------------------\n");

    initRandom();
    s->tabuleiro = intUniformRnd(1, 9);
    printf("\n-> Jogar para o tabuleiro %d\n\n", s->tabuleiro);

    mat = criaMat(N, N);

    s->contadorjogos = 0;
    s->vencedor = 0;
    s->jogadas = 0;
    s->jogador = 1;

    s->contadorjogadas[0] = 0;  s->contadorjogadas[1] = 0;  s->contadorjogadas[2] = 0;
    s->contadorjogadas[3] = 0;  s->contadorjogadas[4] = 0;  s->contadorjogadas[5] = 0;
    s->contadorjogadas[6] = 0;  s->contadorjogadas[7] = 0;  s->contadorjogadas[8] = 0;

    do {
        mostraMat(mat, N, N);
        listajogadasC(lista);
        jogadaC(s, mat, N, s->jogador);
        lista = inserejogadaC(lista, s->jogador, s->aux, s->posicaojogada);
        s->contadorjogadas[s->aux-1]++;

        if(verificaC(mat, s->aux) == 1 || verificaC(mat, s->aux) == -1) {     // Se returnar 1 ('X') ou -1 ('O')
            s->vencedor = s->jogador;
            s->vencedortab[s->contadorjogos] = s->jogador;    // guarda num array quem ganha cada jogo
            escreve_resultadoC(s, s->vencedor);
        }
        else if(verificaC(mat, s->aux) == 0 && s->contadorjogadas[s->aux-1] == 9) {
            s->vencedor = 0;
            s->vencedortab[s->contadorjogos] = 0;
            escreve_resultadoC(s, s->vencedor);
        }

        s->jogador = s->jogador % 2 + 1;
        printf("\n-> Jogar para o tabuleiro %d\n\n", s->posicaojogada);
    }while(s->contadorjogos < N && s->jogadas < N*N);

    mostraMat(mat, N, N);
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
}

void escolhe_jogadaC(jogoC *s, char **p, int n, int x, int y, int n_jogador) {
    if(n_jogador == 1) {
        printf("\n-> Vez do jogador\n");
        do{
            printf("Posicao: ");
            scanf("%d", &s->posicaojogada);
            putchar('\n');
        }while(s->posicaojogada < 1 || s->posicaojogada > N || p[(s->posicaojogada-1)/n+x][(s->posicaojogada-1)%n+y] != '_');
    }
    else if(n_jogador == 2) {
        printf("\n-> Vez do computador\n");
        do {
            s->posicaojogada = intUniformRnd(1, 9);
        } while(s->posicaojogada < 1 || s->posicaojogada > N || p[(s->posicaojogada-1)/n+x][(s->posicaojogada-1)%n+y] != '_');
    }

    if(n_jogador == 1)
        setPos(p, (s->posicaojogada-1)/n+x, (s->posicaojogada-1)%n+y, 'X');
    else
        setPos(p, (s->posicaojogada-1)/n+x, (s->posicaojogada-1)%n+y, 'O');

    s->tabuleiro = s->posicaojogada;
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