#include "jogoC.h"

void jogar_computador(jogo *r) {
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
        jogadaC(r, mat, M, r->njogador);

        if (verifica(mat, r->ntabuleiro_ant) == 1 || verifica(mat, r->ntabuleiro_ant) == -1) {
            r->vencedor = r->njogador;
            mostraMat(mat, N, N);
            escreve_resultadoC(r, tab, r->vencedor);
        }
        else if (verifica(mat, r->ntabuleiro_ant) == 0 && r->tab_jogadas[r->ntabuleiro_ant - 1] == 9) {
            r->vencedor = EMPATE;
            mostraMat(mat, N, N);
            escreve_resultadoC(r, tab, r->vencedor);
        }

        lista = insereinfo(lista, r->njogador, r->ntabuleiro_ant, r->posicao);

        // verifica o tabuleiro final 3x3
        if(verifica_tabuleiro(tab, 0, 3, 0, 3) == 1) {
            r->vencedortabfinal = VITORIA_JOGADOR1;
            mostraMatFinal(tab, M, M);
            escreve_resultadoFinalC(r->vencedortabfinal);
            r->estadojogo = JOGO_TERMINADO;
        }
        else if(verifica_tabuleiro(tab, 0, 3, 0, 3) == -1) {
            r->vencedortabfinal = VITORIA_JOGADOR2;
            mostraMatFinal(tab, M, M);
            escreve_resultadoFinalC(r->vencedortabfinal);
            r->estadojogo = JOGO_TERMINADO;
        }
        else if(verifica_tabuleiro(tab, 0, 3, 0, 3) == 0 && r->njogos == 9) {
            r->vencedortabfinal = EMPATE;
            mostraMatFinal(tab, M, M);
            escreve_resultadoFinalC(r->vencedortabfinal);
            r->estadojogo = JOGO_TERMINADO;
        }

        if(r->njogador != 2 && r->estadojogo != JOGO_TERMINADO) {
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

void jogadaC(jogo *r, char **mat, int dim, int njogador) {
    switch (r->ntabuleiro) {
        case 1:
            escolhe_jogadaC(r, mat, dim, 0, 0, njogador);
            r->ntabuleiro_ant = 1;
            break;
        case 2:
            escolhe_jogadaC(r, mat, dim, 0, 3, njogador);
            r->ntabuleiro_ant = 2;
            break;
        case 3:
            escolhe_jogadaC(r, mat, dim, 0, 6, njogador);
            r->ntabuleiro_ant = 3;
            break;
        case 4:
            escolhe_jogadaC(r, mat, dim, 3, 0, njogador);
            r->ntabuleiro_ant = 4;
            break;
        case 5:
            escolhe_jogadaC(r, mat, dim, 3, 3, njogador);
            r->ntabuleiro_ant = 5;
            break;
        case 6:
            escolhe_jogadaC(r, mat, dim, 3, 6, njogador);
            r->ntabuleiro_ant = 6;
            break;
        case 7:
            escolhe_jogadaC(r, mat, dim, 6, 0, njogador);
            r->ntabuleiro_ant = 7;
            break;
        case 8:
            escolhe_jogadaC(r, mat, dim, 6, 3, njogador);
            r->ntabuleiro_ant = 8;
            break;
        case 9:
            escolhe_jogadaC(r, mat, dim, 6, 6, njogador);
            r->ntabuleiro_ant = 9;
            break;
        default:
            break;
    }

    r->tab_jogadas[r->ntabuleiro_ant - 1]++;
}

void escolhe_jogadaC(jogo *r, char **mat, int dim, int x, int y, int njogador) {

    if(njogador == 1) {
        printf("\n-> Vez do jogador\n");
        do{
            printf("Posicao: ");
            scanf("%d", &r->posicao);

        }while(r->posicao < 1 || r->posicao > N || mat[(r->posicao-1)/dim + x][(r->posicao-1)%dim + y] != '_');
    }
    else if(njogador == 2) {
        printf("\n-> Vez do computador\n");
        do {
            r->posicao = intUniformRnd(1, 9);
        } while(r->posicao < 1 || r->posicao > N || mat[(r->posicao-1)/dim + x][(r->posicao-1)%dim + y] != '_');
        printf("Posicao: %d\n", r->posicao);
    }

    if(njogador == 1)
        setPos(mat, (r->posicao-1)/dim + x, (r->posicao-1)%dim + y, 'X');
    else
        setPos(mat, (r->posicao-1)/dim + x, (r->posicao-1)%dim + y, 'O');

    r->ntabuleiro = r->posicao;
    r->njogadas++;
    putchar('\n');
}
