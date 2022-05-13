#ifndef TP2022_JOGOC_H
#define TP2022_JOGOC_H

#include "jogo.h"
#include "utils.h"
#include "matdin.h"
#define N 3

typedef struct jogosC jogoC, *pjogoC;
struct jogosC {
    int resminitab[N*N];    // resultados dos mini tabuleiros
    int restabfinal;        // resultado do tabuleiro final
    int contadorjogos;
    int njogador;
    int contadorjogadas;
    int vencedor;
    int posicao;
    pjogoC prox;
};

void jogarComputador(jogoC *r);
void escolhe_jogadaComputador(char **p, int n, int n_jogador);
void escreve_resultadoComputador(int ganhou);
void escreve_resultadoFinalComputador(int ganhou);
void resultadosJogosComputador(jogoC r, int n_jogos);
void tabuleiroFinalComputador(jogoC *r);

// a função verifica só se encontra no ficheiro jogo.h

#endif //TP2022_JOGOC_H