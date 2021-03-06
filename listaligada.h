#ifndef TP2022_LISTALIGADA_H
#define TP2022_LISTALIGADA_H

#include "jogo.h"

typedef struct listajogadas lista, *pjogada;
struct listajogadas {
    int njogador;               // número do jogador que fez a jogada
    int ntabuleiro;             // número do tabuleiro em que foi feita a jogada
    int posicao;                // posição da jogada
    pjogada prox;
    pjogada ant;
};

pjogada recuperarjogo(pjogada p);
pjogada recuperalista(char *nomeF);
void libertalista(pjogada p);
void preenchelista(pjogada p, int njogador, int ntabuleiro, int posicao);
pjogada insereinfo(pjogada p, int njogador, int ntabuleiro, int posicao);
void listajogadas(pjogada p);
int interrompejogo(pjogada p);
void gravalistatxt(pjogada p);
void gravalistabin(pjogada p, char* nomeF);

#endif //TP2022_LISTALIGADA_H
