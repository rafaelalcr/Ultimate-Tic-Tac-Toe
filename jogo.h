#ifndef TP2022_JOGO_H
#define TP2022_JOGO_H

#include "matdin.h"
#define N 3

typedef struct jogo dados;
struct jogo {
    int resminitab[N*N];    // resultados dos mini tabuleiros
    int restabfinal;        // resultado do tabuleiro final
    int contador_jogos;
};

void jogarJogador(dados *r);
void escolhe_jogada(char **p, int n, int jogador);
int verifica(char **p, int n);
void escreve_resultado(int ganhou);
void escreve_resultadoFinal(int ganhou);
void resultadosJogos(dados r, int n_jogos);
void tabuleiroFinal(dados *r);

#endif //TP2022_JOGO_H
