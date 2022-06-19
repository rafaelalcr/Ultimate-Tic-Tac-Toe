// Rafaela Fonseca Santos nº 2017019717

#ifndef TP2022_JOGO_H
#define TP2022_JOGO_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "matdin.h"
#include "utils.h"

#define N 9
#define M 3
#define EM_JOGO 0
#define VITORIA_JOGADOR1 1
#define VITORIA_JOGADOR2 2
#define EMPATE 3
#define JOGO_TERMINADO 4

typedef struct jogos jogo;
struct jogos {
    int tab_terminados[N];      // array com a ordem dos mini tabuleiros terminados
    int tab_jogadas[N];         // array que guarda o número de jogadas feitas em cada tabuleiro
    int njogos;                 // número de jogos terminados
    int njogadas;               // número de jogadas feitas pelos jogadores
    int posicao;                // posição jogada escolhida pelo jogador
    int njogador;               // número do jogador (1 -> jogador1, 2 -> jogador2)
    int vencedor;               // qual o número do vencedor (1 -> jogador1, 2 -> jogador2, 3 -> empate)
    int vencedortabfinal;       // resultado do tabuleiro final (1, 2 ou 3)
    int ntabuleiro;             // número do tabuleiro inicial e depois utilizado para verificação da escolha da jogada
    int ntabuleiro_ant;         // variável auxiliar para guardar o número do tabuleiro anterior
    int interrupcao;            // indica se houve interrupção do jogo (1 se sim, 0 se não)
    int estadojogo;             // indica se o jogo tiver terminado ou não
};

void jogar_jogador(jogo *r);
void jogada(jogo *r, char **mat, int dim, int njogador);
void escolhe_jogada(jogo *r, char **mat, int dim, int x, int y, int njogador);
int verifica(char **mat, int ntabuleiro);
int verifica_tabuleiro(char **mat, int linInicial, int linMax, int colInicial, int colMax);

#endif //TP2022_JOGO_H
