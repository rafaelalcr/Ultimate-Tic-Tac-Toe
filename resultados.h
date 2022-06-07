// Rafaela Fonseca Santos nº 2017019717

#ifndef TP2022_RESULTADOS_H
#define TP2022_RESULTADOS_H

#include "jogo.h"
#include "jogoC.h"

// Jogo Jogador 1 vs Jogador 2
void escreve_resultado(jogo *r, int ganhou);
void resultados_jogos(jogo r);
void tabuleiro_final(jogo *r);
void escreve_resultadoFinal(int ganhou);

// Jogo Jogador vs Computador
void escreve_resultadoC(jogoC *s, int ganhou);
void resultados_jogosC(jogoC s);
void tabuleiro_finalC(jogoC *s);
void escreve_resultadoFinalC(int ganhou);

#endif //TP2022_RESULTADOS_H
