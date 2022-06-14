// Rafaela Fonseca Santos nº 2017019717

#ifndef TP2022_MATDIN_H
#define TP2022_MATDIN_H

#include <stdlib.h>
#include <stdio.h>

// Liberta uma matriz dinâmica de caracteres com nLin linhas
void libertaMat(char** p, int nLin);

// Cria uma matriz dinâmica de caracteres com nLin linhas e nCol colunas
// Devolve endereço inicial da matriz
char** criaMat(int nLin, int nCol);

// Imprime o conteúdo de uma matriz dinâmica de caracteres
void mostraMat(char **p, int nLin, int nCol);

// Coloca o caracter c na posição (x, y) de uma matriz dinâmica de caracteres
void setPos(char **p, int x, int y, char c);

// Imprime o conteúdo da matriz final
void mostraMatFinal(char **p, int nLin, int nCol);


#endif //TP2022_MATDIN_H
