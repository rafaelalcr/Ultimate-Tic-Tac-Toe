// Rafaela Fonseca Santos nº 2017019717

#ifndef TP2022_LISTALIGADAC_H
#define TP2022_LISTALIGADAC_H

#include "jogoC.h"

typedef struct listajogadasC listaC, *pjogadaC;
struct listajogadasC {
    int jogador;                // número do jogador que fez a jogada
    int tabuleiro;              // número do tabuleiro em que foi feita a jogada
    int posicao;                // posição da jogada
    int jogadas;                // número de jogadas feitas pelo utilizador/computador
    int vencedores[N];          // array com os resultados dos mini tabuleiros (1, 2 ou 0)
    int terminados[N];          // array com a ordem dos mini tabuleiros terminados
    pjogadaC ant;
    pjogadaC prox;
};

pjogadaC recuperarjogoC(pjogadaC p);
void preenchelistaC(pjogadaC p, int jogador, int tabuleiro, int posicao);
pjogadaC inserejogadaC(pjogadaC p, int jogador, int tabuleiro, int posicao);
void listajogadasC(pjogadaC p);
int interrompejogoC(pjogadaC p);
void libertalistaC(pjogadaC p);
void gravalistatxtC(pjogadaC p, char* nomeF);
void gravalistabinC(pjogadaC p, char* nomeF);
void lelistabinC(pjogadaC p, char* nomeF);
pjogadaC recuperalistaC(char *nomeF);

#endif //TP2022_LISTALIGADAC_H
