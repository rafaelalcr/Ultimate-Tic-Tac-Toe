#ifndef TP2022_JOGOC_H
#define TP2022_JOGOC_H

#include "jogo.h"
#include "utils.h"
#include "matdin.h"
#define N 3

typedef struct jogo dadosC;
struct jogoC {
    int resminitab[N*N];    // resultados dos mini tabuleiros
    int restabfinal;        // resultado do tabuleiro final
    int contador_jogos;
};

void jogarComputador(dadosC *r);
void escolhe_jogadaComputador(char **p, int n, int jogador);
void escreve_resultadoComputador(int ganhou);
void escreve_resultadoFinalComputador(int ganhou);
void resultadosJogosComputador(dadosC r, int njogos);
void tabuleiroFinalComputador(dadosC *r);

// a função verifica só se encontra no ficheiro jogo.h

#endif //TP2022_JOGOC_H