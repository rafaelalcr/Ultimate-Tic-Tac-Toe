// Rafaela Fonseca Santos nº 2017019717

#ifndef TP2022_JOGOC_H
#define TP2022_JOGOC_H

#include <stdlib.h>
#include <stdio.h>
#include "utils.h"
#include "matdin.h"
#define N 9
#define M 3

typedef struct jogosC jogoC;
struct jogosC {
    int vencedortab[N];         // array com os resultados dos mini tabuleiros (1, 2 ou 0)
    int minitab[N];             // array com a ordem dos mini tabuleiros terminados
    int jogadastab[N];          // array que guarda o número de jogadas feitas em cada tabuleiro
    int jogos;                  // número de jogos terminados
    int jogadas;                // número de jogadas feitas pelo utilizador
    int posicao;                // posição jogada escolhida pelo jogador
    int jogador;                // número do jogador (1 -> jogador1, 2 -> jogador2)
    int vencedor;               // qual o número do vencedor (1 -> jogador1, 2 -> jogador2, 0 -> empate)
    int vencedortabfinal;       // resultado do tabuleiro final (1, 2 ou 0)
    int tabuleiro;              // número do tabuleiro inicial e depois utilizado para verificação da escolha da jogada
    int aux;                    // variável auxiliar para guardar o número do tabuleiro anterior
    int interrupcao;            // indica se houve interrupção do jogo (1 se sim, 0 se não)
};

void inicializarC(jogoC *s);
void inicio_jogoC(jogoC *s);
void jogar_computador(jogoC *s);
void jogadaC(jogoC *s, char **p, int n, int n_jogador);
void escolhe_jogadaC(jogoC *s, char **p, int n, int x, int y, int n_jogador);
int verificaC(char **p, int tabuleiro);
int verifica_tabuleiroC(char **p, int nlin, int linMax, int ncol, int colMax);


#endif //TP2022_JOGOC_H