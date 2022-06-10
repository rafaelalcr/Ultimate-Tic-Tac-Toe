// Rafaela Fonseca Santos nº 2017019717

#ifndef TP2022_LISTALIGADA_H
#define TP2022_LISTALIGADA_H

#include "jogo.h"

typedef struct listajogadas lista, *pjogada;
struct listajogadas {
    int njogador;               // número do jogador que fez a jogada
    int ntabuleiro;              // número do tabuleiro em que foi feita a jogada
    int posicao;                // posição da jogada
    int njogadas;               // número de jogadas feitas pelo utilizador
    int njogos;                 // número de jogos terminados
    int tab_vencedores[N];      // array com os resultados dos mini tabuleiros (1, 2 ou 3)
    int tab_terminados[N];      // array com a ordem dos mini tabuleiros terminados
    int tab_jogadas[N];         // array que guarda o número de jogadas feitas em cada tabuleiro
    pjogada ant;
    pjogada prox;
};

pjogada recuperarjogo(pjogada p);
void preenchelista(pjogada p, int njogador, int ntabuleiro, int posicao, int njogadas, int njogos,
                   int *tab_vencedores, int *tab_terminados, int *tab_jogadas);
pjogada insereinfo(pjogada p, int njogador, int ntabuleiro, int posicao, int njogadas, int njogos,
                   int *tab_vencedores, int *tab_terminados, int *tab_jogadas);
void listajogadas(pjogada p);
int interrompejogo(pjogada p);
void libertalista(pjogada p);
void escreveinfo(pjogada p, FILE *f);
void gravalistatxt(pjogada p);
void gravalistabin(pjogada p, char* nomeF);
void leinfo(pjogada p, FILE *f);
void lelistabin(pjogada p, char* nomeF);
pjogada recuperalista(char *nomeF);


#endif //TP2022_LISTALIGADA_H
