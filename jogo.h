#ifndef TP2022_JOGO_H
#define TP2022_JOGO_H

#include "matdin.h"
#include "utils.h"
#include "resultados.h"
#define N 9
#define M 3

typedef struct jogos jogo;
struct jogos {
    int vencedortab[N*N];       // resultados dos mini tabuleiros
    int vencedortabfinal;       // resultado do tabuleiro final
    int contadorjogos;          // número de jogos
    int posicaojogada;          // posição jogada escolhida pelo jogador
    int jogador;                // número do jogador
    int vencedor;               // qual o número do vencedor
    int jogadas;                // número de jogadas
    int tabuleiro;              // número do tabuleiro
    int aux;
};
/*
typedef struct jogadas jogada, *pjogada;
struct jogadas {
    int jogador;                // número do jogador que fez a jogada
    int tabuleiro;              // número do tabuleiro em que foi feita a jogada
    int posicao;                // posição da jogada
    pjogada prox;
};*/

void jogar2(jogo *r);
void escolhe_jogada(jogo *r, char **p, int n, int n_jogador);
void escolhe_tabuleiro(int posicao);

int verificaLinha(char **p, int n);
int verificaColuna(char **p, int n);
int verificaDiagonal(char **p, int n);
//int verifica(char **p, int n);
//void jogar(jogo *r);
//void jogar_jogador(jogo *r);

#endif //TP2022_JOGO_H
