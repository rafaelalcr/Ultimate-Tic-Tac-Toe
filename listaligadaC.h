// Rafaela Fonseca Santos nº 2017019717

#ifndef TP2022_LISTALIGADAC_H
#define TP2022_LISTALIGADAC_H

#include "jogoC.h"

typedef struct listajogadasC listaC, *pjogadaC;
struct listajogadasC {
    int njogador;               // número do jogador que fez a jogada
    int ntabuleiro;              // número do tabuleiro em que foi feita a jogada
    int posicao;                // posição da jogada
    int njogadas;               // número de jogadas feitas pelo utilizador
    int njogos;                 // número de jogos terminados
    int tab_vencedores[N];      // array com os resultados dos mini tabuleiros (1, 2 ou 3)
    int tab_terminados[N];      // array com a ordem dos mini tabuleiros terminados
    int tab_jogadas[N];         // array que guarda o número de jogadas feitas em cada tabuleiro
    pjogadaC ant;
    pjogadaC prox;
};

pjogadaC recuperarjogoC(pjogadaC p);
void preenchelistaC(pjogadaC p, int njogador, int ntabuleiro, int posicao, int njogadas, int njogos,
                    int *tab_vencedores, int *tab_terminados, int *tab_jogadas);
pjogadaC insereinfoC(pjogadaC p, int njogador, int ntabuleiro, int posicao, int njogadas, int njogos,
                     int *tab_vencedores, int *tab_terminados, int *tab_jogadas);
void listajogadasC(pjogadaC p);
int interrompejogoC(pjogadaC p);
void libertalistaC(pjogadaC p);
void escreveinfoC(pjogadaC p, FILE *f);
void gravalistatxtC(pjogadaC p);
void gravalistabinC(pjogadaC p, char* nomeF);
void lelistabinC(pjogadaC p, char* nomeF);
pjogadaC recuperalistaC(char *nomeF);

#endif //TP2022_LISTALIGADAC_H
