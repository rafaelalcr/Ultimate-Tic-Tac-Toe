#ifndef TP2022_JOGO_H
#define TP2022_JOGO_H

#include "matdin.h"
#define N 3

typedef struct resultados dados;
struct resultados {
    int ganhou;
    int resminitab[N*N];    // resultados dos mini tabuleiros
    int restabfinal;        // resultado do tabuleiro final
};

void jogar(dados *r);
void escolhe_jogada(char **p, int n, int jogador);
int verifica(char **p, int n);
void escreve_resultado(int ganhou);
void resultadosJogos(dados r, int njogos);
void tabuleiroFinal(dados *r);
void preeche(dados *r);

#endif //TP2022_JOGO_H
