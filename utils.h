// Rafaela Fonseca Santos nº 2017019717

#ifndef TP2022_UTILS_H
#define TP2022_UTILS_H

// Inicializa o gerador de números aleatorios.
// Esta funcao deve ser chamada apenas uma vez no início da execucao do programa
void initRandom();

//Devolve um valor inteiro aleatorio distribuido uniformemente entre [a, b]
int intUniformRnd(int a, int b);

// Devolve o valor 1 com probabilidade prob. Caso contrario, devolve 0
int probEvento(float prob);

#endif //TP2022_UTILS_H
