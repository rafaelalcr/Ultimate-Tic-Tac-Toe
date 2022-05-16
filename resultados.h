#ifndef TP2022_RESULTADOS_H
#define TP2022_RESULTADOS_H

#include <stdlib.h>
#include <stdio.h>
#include "jogo.h"

void escreve_resultado(jogo *r, int ganhou);
void escreve_resultadoFinal(int ganhou);
void resultados_jogos(jogo r);
int verifica_final(char **p, int n);
void tabuleiro_final(jogo *r);

#endif //TP2022_RESULTADOS_H
