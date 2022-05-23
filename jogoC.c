// Rafaela Fonseca Santos nº 2017019717

#include "jogoC.h"

void jogar_computador(jogoC *s) {
    char **mat = NULL;

    printf("------------------------------------\n");
    printf("|          INICIO DO JOGO          |\n");
    printf("------------------------------------\n");

    initRandom();
    s->tabuleiro = intUniformRnd(1, 9);
    escolhe_tabuleiroC(s->tabuleiro);

    mat = criaMat(N, N);

    s->contadorjogos = 0;
    s->vencedor = 0;
    s->jogadas = 0;
    s->jogador = 1;

    do {
        mostraMat(mat, N, N);
        jogadaC(s, mat, N, s->jogador);
        if(verificaC(mat, s->aux) == 1 || verificaC(mat, s->aux) == -1) {     // Se returnar 1 ('X') ou -1 ('O')
            s->vencedor = s->jogador;
            s->vencedortab[s->contadorjogos] = s->jogador;    // guarda num array quem ganha cada jogo
            escreve_resultadoC(s, s->vencedor);
        }
        s->jogador = s->jogador % 2 + 1;
        escolhe_tabuleiroC(s->posicaojogada);
    }while(s->contadorjogos < N && s->jogadas < N*N);

    mostraMat(mat, N, N);
    libertaMat(mat, N);
}

void escolhe_tabuleiroC(int posicao) {
    printf("\n-> Jogar para o tabuleiro %d\n\n", posicao);
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

void escreve_resultadoC(jogoC *s, int ganhou) {
    // se o número do tabuleiro não estiver guardado no array, aparece o resultado
    if(s->minitab[0] != s->aux && s->minitab[1] != s->aux && s->minitab[2] != s->aux &&
       s->minitab[3] != s->aux && s->minitab[4] != s->aux && s->minitab[5] != s->aux &&
       s->minitab[6] != s->aux && s->minitab[7] != s->aux && s->minitab[8] != s->aux) {

        s->minitab[s->contadorjogos] = s->aux;
        s->contadorjogos++;

        printf("\n------------------------------------\n");
        printf("|             RESULTADO            |\n");
        printf("------------------------------------\n");

        if (ganhou == 0)
            printf("\nEmpate no jogo %d.\n\n", s->aux);
        else if (ganhou == 1)
            printf("\nO jogador ganhou o jogo %d.\n\n", s->aux);
        else if (ganhou == 2)
            printf("\nO computador ganhou o jogo %d.\n\n", s->aux);

        printf("\n------------------------------------\n");
        printf("|        CONTINUACAO DO JOGO       |\n");
        printf("------------------------------------\n");
    }
}

void resultados_jogosC(jogoC s) {
    printf("------------------------------------\n");
    printf("|        RESULTADO DOS JOGOS       |\n");
    printf("------------------------------------\n\n");

    if(s.contadorjogos == 0) {
        printf("Sem resultados.\n\n");
    }
    else {
        for(int i=0; i < N; i++) {
            if(s.vencedortab[i] == 1)
                printf("Jogador ganhou o jogo %d\n", s.minitab[i]);
            else if(s.vencedortab[i] == 2)
                printf("Computador ganhou o jogo %d\n", s.minitab[i]);
            else if(s.vencedortab[i] == 0)
                printf("Houve um empate no jogo %d\n", s.minitab[i]);
        }
        tabuleiro_finalC(&s);
    }
}

void tabuleiro_finalC(jogoC *s) {
    char **mat = NULL;
    printf("\n------------------------------------\n");
    printf("|          TABULEIRO FINAL         |\n");
    printf("------------------------------------\n\n");

    s->vencedortabfinal = 0;
    mat = criaMat(M, M);

    for(int i = s->minitab[0]; i <= s->minitab[8]; i++) {   // percorre pela ordem dos jogos
        if(s->vencedortab[i] == 1)
            setPos(mat, (s->minitab[i]-1)/M, (s->minitab[i]-1)%M, 'X');
        else if(s->vencedortab[i] == 2)
            setPos(mat, (s->minitab[i]-1)/M, (s->minitab[i]-1)%M, 'O');
        else if(s->vencedortab[i] == 0)
            setPos(mat, (s->minitab[i]-1)/M, (s->minitab[i]-1)%M, '#');
    }

    if(verifica_tabuleiroC(mat, 0, 3, 0, 3) == 1)
        s->vencedortabfinal = 1;
    else if(verifica_tabuleiroC(mat, 0, 3, 0, 3) == -1)
        s->vencedortabfinal = 2;
    else if(verifica_tabuleiroC(mat, 0, 3, 0, 3) == 0)
        s->vencedortabfinal = 0;

    mostraMat(mat, M, M);
    escreve_resultadoFinalC(s->vencedortabfinal);
    libertaMat(mat, M);
    putchar('\n');
}

void escreve_resultadoFinalC(int ganhou) {
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

