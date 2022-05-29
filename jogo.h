// Rafaela Fonseca Santos nº 2017019717

#ifndef TP2022_JOGO_H
#define TP2022_JOGO_H

#include <stdlib.h>
#include <stdio.h>
#include "matdin.h"
#include "utils.h"
#define N 9
#define M 3

typedef struct jogos jogo;
struct jogos {
    int vencedortab[N];         // array com os resultados dos mini tabuleiros (1, 2 ou 0)
    int minitab[N];             // array com a ordem dos mini tabuleiros terminados
    int vencedortabfinal;       // resultado do tabuleiro final (1, 2 ou 0)
    int contadorjogos;          // número de jogos terminados
    int posicaojogada;          // posição jogada escolhida pelo jogador
    int jogador;                // número do jogador (1 -> jogador1, 2 -> jogador2)
    int vencedor;               // qual o número do vencedor (1 -> jogador1, 2 -> jogador2, 0 -> empate)
    int jogadas;                // número de jogadas feitas pelo utilizador
    int tabuleiro;              // número do tabuleiro inicial e depois utilizado para verificação da escolha da jogada
    int aux;                    // variável auxiliar para guardar o número do tabuleiro anterior
    int contadorjogadas[N];     // array que guarda o número de jogadas feitas em cada tabuleiro
};

/*
typedef struct jogadas jogada, *pjogada;
struct jogadas {
    int jogador;                // número do jogador que fez a jogada
    int tabuleiro;              // número do tabuleiro em que foi feita a jogada
    int posicao;                // posição da jogada
    pjogada prox;
};*/

void jogar_jogador(jogo *r);
void jogada(jogo *r, char **p, int n, int n_jogador);
void escolhe_jogada(jogo *r, char **p, int n, int x, int y, int n_jogador);
void escolhe_tabuleiro(int posicao);

int verifica(char **p, int tabuleiro);
int verifica_tabuleiro(char **p, int nlin, int linMax, int ncol, int colMax);

void escreve_resultado(jogo *r, int ganhou);
void resultados_jogos(jogo r);
void tabuleiro_final(jogo *r);
void escreve_resultadoFinal(int ganhou);

#endif //TP2022_JOGO_H
