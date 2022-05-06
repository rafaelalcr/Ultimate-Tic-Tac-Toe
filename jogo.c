#include "jogo.h"

void jogar(dados *r) {
    char **mat = NULL;
    int njogador = 1, n_jogadas = 0, n_jogos = 0, ganhou = 0;

    do {
        ganhou = 0;
        n_jogadas = 0;
        njogador = 1;

        printf("--------- INICIO DO JOGO %d --------\n\n", n_jogos + 1);
        mat = criaMat(N, N);
        do {
            mostraMat(mat, N, N);
            escolhe_jogada(mat, N, njogador);
            n_jogadas++;
            if(verifica(mat, N) == 1 || verifica(mat, N) == -1) {     // Se returnar 1 ('X') ou -1 ('O')
                ganhou = njogador;
                r->resminitab[n_jogos] = njogador;
            }
            else
                njogador = njogador % 2 + 1;
        }while(ganhou == 0 && n_jogadas < N*N);

        mostraMat(mat, N, N);
        escreve_resultado(ganhou);
        libertaMat(mat, N);

        n_jogos++;

    } while (n_jogos < N * N);
}

void escolhe_jogada(char **p, int n, int jogador) {
    int pos;
    printf("\nVez do jogador %d\n", jogador);
    do{
        printf("Posicao: ");
        scanf("%d", &pos);
        putchar('\n');
    }while(pos<1 || pos>n*n || p[(pos-1)/n][(pos-1)%n] != '_');

    if(jogador == 1)
        setPos(p, (pos-1)/n, (pos-1)%n, 'X');
    else
        setPos(p, (pos-1)/n, (pos-1)%n, 'O');
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
    printf("\n------------- RESULTADO ------------\n");
    if(ganhou == 0)
        printf("\nEmpate.\n\n");
    else
        printf("\nGanhou o jogador %d.\n\n", ganhou);
}

void escreve_resultadoFinal(int ganhou) {
    printf("\n---------- RESULTADO FINAL ---------\n");
    if(ganhou == 0)
        printf("\nEmpate.\n\n");
    else
        printf("\nGanhou o jogador %d.\n\n", ganhou);
}

void resultadosJogos(dados r, int njogos) {
    printf("------- RESULTADO DOS JOGOS --------\n\n");
    for(int i=0; i < njogos; i++) {
        printf("Jogador %d ganhou o jogo %d\n", r.resminitab[i], i+1);
    }
    tabuleiroFinal(&r);
}

void tabuleiroFinal(dados *r) {
    char **mat = NULL;
    printf("\n--------- TABULEIRO FINAL ----------\n\n");
    r->restabfinal = 0;
    mat = criaMat(N, N);
    for(int i=0; i < N*N; i++) {
        if(r->resminitab[i] == 1) {                 // Se o jogador 1 ganhou
            setPos(mat, (i-1)/N, (i-1)%N, 'X');
        }
        else if(r->resminitab[i] == 2) {            // Se o jogador 2 ganhou
            setPos(mat, (i-1)/N, (i-1)%N, 'O');
        }
        else if(r->resminitab[i] == 0) {            // Se empatou
            setPos(mat, (i-1)/N, (i-1)%N, '#');
        }
    }

    if(verifica(mat, N) == 1)
        r->restabfinal = 1;
    else if(verifica(mat, N) == -1)
        r->restabfinal = 2;
    else
        r->restabfinal = 0;

    mostraMat(mat, N, N);
    escreve_resultadoFinal(r->restabfinal);
    libertaMat(mat, N);
    putchar('\n');
}

