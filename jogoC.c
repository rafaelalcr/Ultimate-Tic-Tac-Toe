#include "jogoC.h"

void jogarComputador(jogoC *r) {
    char **mat = NULL;
    int n_jogador, n_jogadas, n_jogos = 0, ganhou;

    r->contadorjogos = 0;

    do {
        ganhou = 0;
        n_jogadas = 0;
        n_jogador = 1;

        printf("------------------------------------\n");
        printf("|         INICIO DO JOGO %d         |\n", n_jogos + 1);
        printf("------------------------------------\n\n");
        mat = criaMat(N, N);
        do {
            mostraMat(mat, N, N);
            escolhe_jogadaComputador(mat, N, n_jogador);
            n_jogadas++;
            if(verificaComputador(mat, N) == 1 || verificaComputador(mat, N) == -1) {     // Se returnar 1 ('X') ou -1 ('O')
                ganhou = n_jogador;
                r->resminitab[n_jogos] = n_jogador;
            }
            else
                n_jogador = n_jogador % 2 + 1;
        }while(ganhou == 0 && n_jogadas < N*N);

        mostraMat(mat, N, N);
        escreve_resultadoComputador(ganhou);
        libertaMat(mat, N);

        n_jogos++;
        r->contadorjogos++;

    } while (n_jogos < N * N);
}

void escolhe_jogadaComputador(char **p, int n, int n_jogador) {
    int pos;

    if(n_jogador == 1) {
        printf("\n-> Vez do jogador \n");
        do{
            printf("Posicao: ");
            scanf("%d", &pos);
            putchar('\n');
        }while(pos<1 || pos>n*n || p[(pos-1)/n][(pos-1)%n] != '_');
    }
    else if(n_jogador == 2) {
        printf("\n-> Vez do computador \n");
        do {
            pos = intUniformRnd(1, 9);
        } while(pos<1 || pos>n*n || p[(pos-1)/n][(pos-1)%n] != '_');
    }

    if(n_jogador == 1)
        setPos(p, (pos-1)/n, (pos-1)%n, 'X');
    else
        setPos(p, (pos-1)/n, (pos-1)%n, 'O');
}

int verificaComputador(char **p, int n) {
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

void escreve_resultadoComputador(int ganhou) {
    printf("\n------------------------------------\n");
    printf("|             RESULTADO            |\n");
    printf("------------------------------------\n");
    if(ganhou == 0)
        printf("\nEmpate.\n\n");
    else if(ganhou == 1)
        printf("\nGanhou o jogador.\n\n");
    else if(ganhou == 2)
        printf("\nGanhou o computador.\n\n");
}

void escreve_resultadoFinalComputador(int ganhou) {
    printf("\n------------------------------------\n");
    printf("|          RESULTADO FINAL         |\n");
    printf("------------------------------------\n\n");
    if(ganhou == 0)
        printf("\nEmpate.\n\n");
    else if(ganhou == 1)
        printf("\nGanhou o jogador.\n\n");
    else if(ganhou == 2)
        printf("\nGanhou o computador.\n\n");
}

void resultadosJogosComputador(jogoC r, int n_jogos) {
    printf("------------------------------------\n");
    printf("|        RESULTADO DOS JOGOS       |\n");
    printf("------------------------------------\n\n");
    if(r.contadorjogos == 0) {
        printf("Sem resultados.\n\n");
    }
    else {
        for(int i=0; i < n_jogos; i++) {
            if(r.resminitab[i] == 1)
                printf("Jogador ganhou o jogo %d\n", i+1);
            else if(r.resminitab[i] == 2)
                printf("Computador ganhou o jogo %d\n", i+1);
            else if(r.resminitab[i] == 0)
                printf("Empate no jogo %d\n", i+1);
        }
        tabuleiroFinalComputador(&r);
    }
}

void tabuleiroFinalComputador(jogoC *r) {
    char **mat = NULL;
    printf("\n------------------------------------\n");
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
/*
    if(linha(mat, N) == 1 || coluna(mat, N) == 1 || diagonal(mat, N) == 1)
        r->restabfinal = 1;
    else if(linha(mat, N) == -1 || coluna(mat, N) == -1 || diagonal(mat, N) == -1)
        r->restabfinal = 2;
    else if(linha(mat, N) == 0 || coluna(mat, N) == 0 || diagonal(mat, N) == 0)
        r->restabfinal = 0;
*/
    mostraMat(mat, N, N);
    escreve_resultadoFinalComputador(r->restabfinal);
    libertaMat(mat, N);
    putchar('\n');
}

