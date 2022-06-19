// Rafaela Fonseca Santos nº 2017019717

#ifndef TP2022_JOGOC_H
#define TP2022_JOGOC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils.h"
#include "matdin.h"

#include "jogo.h"
#include "listaligada.h"
#include "resultados.h"

void jogar_computador(jogo *r);
void jogadaC(jogo *r, char **mat, int dim, int njogador);
void escolhe_jogadaC(jogo *r, char **mat, int dim, int x, int y, int njogador);

#endif //TP2022_JOGOC_H