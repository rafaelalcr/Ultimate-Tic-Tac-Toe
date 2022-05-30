// Rafaela Fonseca Santos nº 2017019717

#ifndef TP2022_LISTALIGADA_H
#define TP2022_LISTALIGADA_H

#include "jogo.h"

typedef struct listajogadas lista, *pjogada;
struct listajogadas {
    int jogador;                // número do jogador que fez a jogada
    int tabuleiro;              // número do tabuleiro em que foi feita a jogada
    int posicao;                // posição da jogada
    int jogadas;                // número de jogadas feitas
    pjogada prox;
};

void listajogadas(pjogada p);
void preenchelista(pjogada p, int jogador, int tabuleiro, int posicao, int jogadas);
pjogada inserejogada(pjogada p, int jogador, int tabuleiro, int posicao, int jogadas);
void libertalista(pjogada p);

#endif //TP2022_LISTALIGADA_H
