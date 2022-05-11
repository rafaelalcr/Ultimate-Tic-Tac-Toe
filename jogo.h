#ifndef TP2022_JOGO_H
#define TP2022_JOGO_H

#include "matdin.h"
#include "utils.h"
#define N 3

typedef struct jogos jogo, *pjogo;
struct jogos {
    int resminitab[N*N];    // resultados dos mini tabuleiros
    int restabfinal;        // resultado do tabuleiro final
    int contadorjogos;
    //int njogador;
    //int contadorjogadas;
    //int vencedor;
    int posicaojogada;
    pjogo prox;
};

void jogar_jogador(jogo *r);
void tabuleiro_inicial(int posicao);
void escolhe_jogada(jogo *r, char **p, int n, int n_jogador);
void escolhe_tabuleiro(int posicao);
int verifica(char **p, int n);
void escreve_resultado(int ganhou);
void escreve_resultadoFinal(int ganhou);
void resultados_jogos(jogo r, int n_jogos);
void tabuleiro_final(jogo *r);
void criaFicheiroTXT();

#endif //TP2022_JOGO_H
