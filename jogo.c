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

    mat = criaMat(N, N);

    do {
        r->vencedor = 0;
        r->jogadas = 0;
        r->jogador = 1;

        do {
            mostraMat(mat, N, N);
            escolhe_jogada(r, mat, M, r->jogador);
            r->jogadas++;
            if(verifica(mat, r->aux) == 1 || verifica(mat, r->aux) == -1) {
                r->vencedor = r->jogador;
                r->vencedortab[r->aux] = r->jogador;    // guarda num array quem ganha cada jogo
                r->minitab[r->contadorjogos] = r->aux;  // guarda a ordem dos tabuleiros terminados
                escreve_resultado(r, r->vencedor);
            }
            r->jogador = r->jogador % 2 + 1;
            escolhe_tabuleiro(r->posicaojogada);
        }while(r->vencedor == 0 || r->jogadas < N*N);

        mostraMat(mat, N, N);

    } while (r->contadorjogos < N);

    libertaMat(mat, N);
}

void escolhe_tabuleiro(int posicao) {
    printf("\n-> Jogar para o tabuleiro %d\n\n", posicao);
}

void escolhe_jogada(jogo *r, char **p, int n, int n_jogador) {
    r->aux = 0;
    printf("\n-> Vez do jogador %d\n", n_jogador);

    if(r->tabuleiro == 1) {
        do{
            printf("Posicao: ");
            scanf("%d", &r->posicaojogada);
            putchar('\n');
        }while(r->posicaojogada < 1 || r->posicaojogada > N || p[(r->posicaojogada-1)/n][(r->posicaojogada-1)%n] != '_');

        if(n_jogador == 1)
            setPos(p, (r->posicaojogada-1)/n+0, (r->posicaojogada-1)%n+0, 'X');
        else
            setPos(p, (r->posicaojogada-1)/n+0, (r->posicaojogada-1)%n+0, 'O');

        r->aux = 1;
    }
    else if(r->tabuleiro == 2) {
        do{
            printf("Posicao: ");
            scanf("%d", &r->posicaojogada);
            putchar('\n');
        }while(r->posicaojogada < 1 || r->posicaojogada > N || p[(r->posicaojogada-1)/n][(r->posicaojogada-1)%n+3] != '_');

        if(n_jogador == 1)
            setPos(p, (r->posicaojogada-1)/n+0, (r->posicaojogada-1)%n+3, 'X');
        else
            setPos(p, (r->posicaojogada-1)/n+0, (r->posicaojogada-1)%n+3, 'O');

        r->aux = 2;
    }
    else if(r->tabuleiro == 3) {
        do{
            printf("Posicao: ");
            scanf("%d", &r->posicaojogada);
            putchar('\n');
        }while(r->posicaojogada < 1 || r->posicaojogada > N || p[(r->posicaojogada-1)/n][(r->posicaojogada-1)%n+6] != '_');

        if(n_jogador == 1)
            setPos(p, (r->posicaojogada-1)/n+0, (r->posicaojogada-1)%n+6, 'X');
        else
            setPos(p, (r->posicaojogada-1)/n+0, (r->posicaojogada-1)%n+6, 'O');

        r->aux = 3;
    }
    else if(r->tabuleiro == 4) {
        do{
            printf("Posicao: ");
            scanf("%d", &r->posicaojogada);
            putchar('\n');
        }while(r->posicaojogada < 1 || r->posicaojogada > N || p[(r->posicaojogada-1)/n+3][(r->posicaojogada-1)%n] != '_');

        if(n_jogador == 1)
            setPos(p, (r->posicaojogada-1)/n+3, (r->posicaojogada-1)%n+0, 'X');
        else
            setPos(p, (r->posicaojogada-1)/n+3, (r->posicaojogada-1)%n+0, 'O');

        r->aux = 4;
    }
    else if(r->tabuleiro == 5) {
        do{
            printf("Posicao: ");
            scanf("%d", &r->posicaojogada);
            putchar('\n');
        }while(r->posicaojogada < 1 || r->posicaojogada > N || p[(r->posicaojogada-1)/n+3][(r->posicaojogada-1)%n+3] != '_');

        if(n_jogador == 1)
            setPos(p, (r->posicaojogada-1)/n+3, (r->posicaojogada-1)%n+3, 'X');
        else
            setPos(p, (r->posicaojogada-1)/n+3, (r->posicaojogada-1)%n+3, 'O');

        r->aux = 5;
    }
    else if(r->tabuleiro == 6) {
        do{
            printf("Posicao: ");
            scanf("%d", &r->posicaojogada);
            putchar('\n');
        }while(r->posicaojogada < 1 || r->posicaojogada > N || p[(r->posicaojogada-1)/n+3][(r->posicaojogada-1)%n+6] != '_');

        if(n_jogador == 1)
            setPos(p, (r->posicaojogada-1)/n+3, (r->posicaojogada-1)%n+6, 'X');
        else
            setPos(p, (r->posicaojogada-1)/n+3, (r->posicaojogada-1)%n+6, 'O');

        r->aux = 6;
    }
    else if(r->tabuleiro == 7) {
        do{
            printf("Posicao: ");
            scanf("%d", &r->posicaojogada);
            putchar('\n');
        }while(r->posicaojogada < 1 || r->posicaojogada > N || p[(r->posicaojogada-1)/n+6][(r->posicaojogada-1)%n] != '_');

        if(n_jogador == 1)
            setPos(p, (r->posicaojogada-1)/n+6, (r->posicaojogada-1)%n+0, 'X');
        else
            setPos(p, (r->posicaojogada-1)/n+6, (r->posicaojogada-1)%n+0, 'O');

        r->aux = 7;
    }
    else if(r->tabuleiro == 8) {
        do{
            printf("Posicao: ");
            scanf("%d", &r->posicaojogada);
            putchar('\n');
        }while(r->posicaojogada < 1 || r->posicaojogada > N || p[(r->posicaojogada-1)/n+6][(r->posicaojogada-1)%n+3] != '_');

        if(n_jogador == 1)
            setPos(p, (r->posicaojogada-1)/n+6, (r->posicaojogada-1)%n+3, 'X');
        else
            setPos(p, (r->posicaojogada-1)/n+6, (r->posicaojogada-1)%n+3, 'O');

        r->aux = 8;
    }
    else if(r->tabuleiro == 9) {
        do{
            printf("Posicao: ");
            scanf("%d", &r->posicaojogada);
            putchar('\n');
        }while(r->posicaojogada < 1 || r->posicaojogada > N || p[(r->posicaojogada-1)/n+6][(r->posicaojogada-1)%n+6] != '_');

        if(n_jogador == 1)
            setPos(p, (r->posicaojogada-1)/n+6, (r->posicaojogada-1)%n+6, 'X');
        else
            setPos(p, (r->posicaojogada-1)/n+6, (r->posicaojogada-1)%n+6, 'O');

        r->aux = 9;
    }

    r->tabuleiro = r->posicaojogada;
}

int verifica(char **p, int tabuleiro) {
    if(tabuleiro == 1)
        return verifica_tabuleiro(p, 0, 3, 0, 3);
    else if(tabuleiro == 2)
        return verifica_tabuleiro(p, 0, 3, 3, 6);
    else if(tabuleiro == 3)
        return verifica_tabuleiro(p, 0, 3, 6, 9);
    else if(tabuleiro == 4)
        return verifica_tabuleiro(p, 3, 6, 0, 3);
    else if(tabuleiro == 5)
        return verifica_tabuleiro(p, 3, 6, 3, 6);
    else if(tabuleiro == 6)
        return verifica_tabuleiro(p, 3, 6, 6, 9);
    else if(tabuleiro == 7)
        return verifica_tabuleiro(p, 6, 9, 0, 3);
    else if(tabuleiro == 8)
        return verifica_tabuleiro(p, 6, 9, 3, 6);
    else if(tabuleiro == 9)
        return verifica_tabuleiro(p, 6, 9, 6, 9);

    return 0;
}

int verifica_tabuleiro(char **p, int nlin, int linMax, int ncol, int colMax) {
    int linha, coluna;
    int contador;

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
    if(r->minitab[0] != r->aux || r->minitab[1] != r->aux || r->minitab[2] != r->aux ||
        r->minitab[3] != r->aux || r->minitab[4] != r->aux || r->minitab[5] != r->aux ||
        r->minitab[6] != r->aux || r->minitab[7] != r->aux || r->minitab[8] != r->aux) {

        printf("\n------------------------------------\n");
        printf("|             RESULTADO            |\n");
        printf("------------------------------------\n\n");

        if(ganhou == 0)
            printf("\nEmpate no jogo %d.\n\n", r->aux);
        else
            printf("\nO jogador %d ganhou o jogo %d.\n\n", ganhou, r->aux);

        r->contadorjogos++;                     // número de jogos já terminados
        printf("Numero de jogos terminados: %d\n", r->contadorjogos);

        printf("\n------------------------------------\n");
        printf("|        CONTINUACAO DO JOGO       |\n");
        printf("------------------------------------\n");
    }
}

void resultados_jogos(jogo r) {
    printf("------------------------------------\n");
    printf("|        RESULTADO DOS JOGOS       |\n");
    printf("------------------------------------\n\n");

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

    r->vencedortabfinal = 0;
    mat = criaMat(M, M);

    for(int i=0; i < M*M; i++) {
        if(r->vencedortab[i] == 1)                  // Se o jogador 1 ganhou
            setPos(mat, i/M, i%M, 'X');
        else if(r->vencedortab[i] == 2)             // Se o jogador 2 ganhou
            setPos(mat, i/M, i%M, 'O');
        else if(r->vencedortab[i] == 0)             // Se empatou
            setPos(mat, i/M, i%M, '#');
    }

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
