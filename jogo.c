// Rafaela Fonseca Santos nº 2017019717

#include "jogo.h"

void jogar_jogador(jogo *r) {
    char **mat = NULL;

    printf("------------------------------------\n");
    printf("|          INICIO DO JOGO          |\n");
    printf("------------------------------------\n");

    initRandom();
    r->tabuleiro = intUniformRnd(1, 9);
    escolhe_tabuleiro(r->tabuleiro);

    mat = criaMat(N, N);

    r->contadorjogos = 0;
    r->vencedor = 0;
    r->jogadas = 0;
    r->jogador = 1;

    r->contadorjogadas[0] = 0;  r->contadorjogadas[1] = 0;  r->contadorjogadas[2] = 0;
    r->contadorjogadas[3] = 0;  r->contadorjogadas[4] = 0;  r->contadorjogadas[5] = 0;
    r->contadorjogadas[6] = 0;  r->contadorjogadas[7] = 0;  r->contadorjogadas[8] = 0;

    do {
        mostraMat(mat, N, N);
        jogada(r, mat, M, r->jogador);
        r->contadorjogadas[r->aux-1]++;
        printf("Numero Jogadas: %d\n", r->contadorjogadas[r->aux-1]);
        if(verifica(mat, r->aux) == 1 || verifica(mat, r->aux) == -1) {
            r->vencedor = r->jogador;
            r->vencedortab[r->contadorjogos] = r->jogador;
            escreve_resultado(r, r->vencedor);
        }
        else if(verifica(mat, r->aux) == 0 && r->contadorjogadas[r->aux-1] == 9) {
            r->vencedor = 0;
            r->vencedortab[r->contadorjogos] = 0;
            escreve_resultado(r, r->vencedor);
        }
        r->jogador = r->jogador % 2 + 1;
        escolhe_tabuleiro(r->posicaojogada);
    }while(r->contadorjogos < N && r->jogadas < N*N);

    mostraMat(mat, N, N);
    libertaMat(mat, N);
}

void escolhe_tabuleiro(int posicao) {
    printf("\n-> Jogar para o tabuleiro %d\n\n", posicao);
}

void jogada(jogo *r, char **p, int n, int n_jogador) {
    r->aux = 0;
    printf("\n-> Vez do jogador %d\n", n_jogador);

    switch (r->tabuleiro) {
        case 1:
            escolhe_jogada(r, p, n, 0, 0, n_jogador);
            r->aux = 1;
            break;
        case 2:
            escolhe_jogada(r, p, n, 0, 3, n_jogador);
            r->aux = 2;
            break;
        case 3:
            escolhe_jogada(r, p, n, 0, 6, n_jogador);
            r->aux = 3;
            break;
        case 4:
            escolhe_jogada(r, p, n, 3, 0, n_jogador);
            r->aux = 4;
            break;
        case 5:
            escolhe_jogada(r, p, n, 3, 3, n_jogador);
            r->aux = 5;
            break;
        case 6:
            escolhe_jogada(r, p, n, 3, 6, n_jogador);
            r->aux = 6;
            break;
        case 7:
            escolhe_jogada(r, p, n, 6, 0, n_jogador);
            r->aux = 7;
            break;
        case 8:
            escolhe_jogada(r, p, n, 6, 3, n_jogador);
            r->aux = 8;
            break;
        case 9:
            escolhe_jogada(r, p, n, 6, 6, n_jogador);
            r->aux = 9;
        default:
            break;
    }
}

void escolhe_jogada(jogo *r, char **p, int n, int x, int y, int n_jogador) {
    do{
        printf("Posicao: ");
        scanf("%d", &r->posicaojogada);
        putchar('\n');
    }while(r->posicaojogada < 1 || r->posicaojogada > N || p[(r->posicaojogada-1)/n+x][(r->posicaojogada-1)%n+y] != '_');

    if(n_jogador == 1)
        setPos(p, (r->posicaojogada-1)/n+x, (r->posicaojogada-1)%n+y, 'X');
    else
        setPos(p, (r->posicaojogada-1)/n+x, (r->posicaojogada-1)%n+y, 'O');

    r->tabuleiro = r->posicaojogada;
    r->jogadas++;
}

int verifica(char **p, int tabuleiro) {
    switch (tabuleiro) {
        case 1:
            return verifica_tabuleiro(p, 0, 3, 0, 3);
        case 2:
            return verifica_tabuleiro(p, 0, 3, 3, 6);
        case 3:
            return verifica_tabuleiro(p, 0, 3, 6, 9);
        case 4:
            return verifica_tabuleiro(p, 3, 6, 0, 3);
        case 5:
            return verifica_tabuleiro(p, 3, 6, 3, 6);
        case 6:
            return verifica_tabuleiro(p, 3, 6, 6, 9);
        case 7:
            return verifica_tabuleiro(p, 6, 9, 0, 3);
        case 8:
            return verifica_tabuleiro(p, 6, 9, 3, 6);
        case 9:
            return verifica_tabuleiro(p, 6, 9, 6, 9);
        default:
            return 0;
    }
}

int verifica_tabuleiro(char **p, int nlin, int linMax, int ncol, int colMax) {
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

    contador = 0;
    for(coluna = ncol; coluna < colMax; ++coluna) {   // Verifica a Diagonal de cima para baixo da esquerda para direita
        contador += (p[coluna][coluna] == 'X')?  1 :
                    (p[coluna][coluna] == 'O')? -1 : 0;
    }
    if (contador == 3 || contador == -3)
        return contador / abs(contador);

    contador = 0;
    for (coluna = ncol; coluna < colMax; ++coluna) {  // Verifica a Diagonal de baixo para cima da esquerda para direita
        contador += (p[coluna][2 - coluna] == 'X') ? 1 :
                    (p[coluna][2 - coluna] == 'O') ? -1 : 0;
    }
    if (contador == 3 || contador == -3)
        return contador / abs(contador);

    return 0;
}

void escreve_resultado(jogo *r, int ganhou) {
    // se o número do tabuleiro não estiver guardado no array, aparece o resultado
    if(r->minitab[0] != r->aux && r->minitab[1] != r->aux && r->minitab[2] != r->aux &&
        r->minitab[3] != r->aux && r->minitab[4] != r->aux && r->minitab[5] != r->aux &&
        r->minitab[6] != r->aux && r->minitab[7] != r->aux && r->minitab[8] != r->aux) {

        r->minitab[r->contadorjogos] = r->aux;
        printf("Numero Tabuleiro Terminado: %d\n", r->minitab[r->contadorjogos]);
        r->contadorjogos++;
        printf("Numero Jogos Terminados: %d\n", r->contadorjogos);

        printf("\n------------------------------------\n");
        printf("|             RESULTADO            |\n");
        printf("------------------------------------\n\n");

        if(ganhou == 0)
            printf("\nEmpate no jogo %d.\n\n", r->aux);
        else
            printf("\nO jogador %d ganhou o jogo %d.\n\n", ganhou, r->aux);

        printf("\n------------------------------------\n");
        printf("|        CONTINUACAO DO JOGO       |\n");
        printf("------------------------------------\n");
    }
}

void resultados_jogos(jogo r) {
    printf("------------------------------------\n");
    printf("|        RESULTADO DOS JOGOS       |\n");
    printf("------------------------------------\n\n");

    /*r->vencedortab[0] = 2;  r->minitab[0] = 5;
    r->vencedortab[1] = 1;  r->minitab[1] = 1;
    r->vencedortab[2] = 1;  r->minitab[2] = 2;
    r->vencedortab[3] = 1;  r->minitab[3] = 3;
    r->vencedortab[4] = 2;  r->minitab[4] = 7;
    r->vencedortab[5] = 2;  r->minitab[5] = 4;
    r->vencedortab[6] = 1;  r->minitab[6] = 8;
    r->vencedortab[7] = 2;  r->minitab[7] = 6;
    r->vencedortab[8] = 0;  r->minitab[8] = 9;*/

    if(r.contadorjogos == 0)
        printf("Sem resultados.\n\n");
    else {
        for(int i=0; i < N; i++) {
            if(r.vencedortab[i] == 0)
                printf("Houve um empate no jogo %d\n", r.minitab[i]);
            else
                printf("Jogador %d ganhou o jogo %d\n", r.vencedortab[i], r.minitab[i]);
        }
        tabuleiro_final(&r);
    }
}

void tabuleiro_final(jogo *r) {
    char **mat = NULL;
    printf("\n------------------------------------\n");
    printf("|          TABULEIRO FINAL         |\n");
    printf("------------------------------------\n\n");

    mat = criaMat(M, M);
    for(int i = 0; i < N; i++) {
        if(r->vencedortab[i] == 1)
            setPos(mat, (r->minitab[i]-1)/M, (r->minitab[i]-1)%M, 'X');
        else if(r->vencedortab[i] == 2)
            setPos(mat, (r->minitab[i]-1)/M, (r->minitab[i]-1)%M, 'O');
        else if(r->vencedortab[i] == 0)
            setPos(mat, (r->minitab[i]-1)/M, (r->minitab[i]-1)%M, '#');
    }

    /*for(int i = r->minitab[0]; i <= r->minitab[8]; i++) {   // percorre pela ordem dos jogos
        if(r->vencedortab[i] == 1)
            setPos(mat, (r->minitab[i]-1)/M, (r->minitab[i]-1)%M, 'X');
        else if(r->vencedortab[i] == 2)
            setPos(mat, (r->minitab[i]-1)/M, (r->minitab[i]-1)%M, 'O');
        else if(r->vencedortab[i] == 0)
            setPos(mat, (r->minitab[i]-1)/M, (r->minitab[i]-1)%M, '#');
    }*/

    if(verifica_tabuleiro(mat, 0, 3, 0, 3) == 1)
        r->vencedortabfinal = 1;
    else if(verifica_tabuleiro(mat, 0, 3, 0, 3) == -1)
        r->vencedortabfinal = 2;
    else if(verifica_tabuleiro(mat, 0, 3, 0, 3) == 0)
        r->vencedortabfinal = 0;

    mostraMatFinal(mat, M, M);
    escreve_resultadoFinal(r->vencedortabfinal);
    libertaMat(mat, M);
    putchar('\n');
}

void escreve_resultadoFinal(int ganhou) {
    printf("\n------------------------------------\n");
    printf("|          RESULTADO FINAL         |\n");
    printf("------------------------------------\n\n");

    if(ganhou == 0)
        printf("\nEmpate.\n\n");
    else
        printf("\nGanhou o jogador %d.\n\n", ganhou);
}
