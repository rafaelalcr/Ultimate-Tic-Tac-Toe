#ifndef TP2022_JOGO_H
#define TP2022_JOGO_H

#include "matdin.h"
#include "utils.h"
#define N 3

typedef struct jogos jogo, *pjogo;
struct jogos {
    int vencedortab[N*N];        // resultados dos mini tabuleiros
    int vencedortabfinal;        // resultado do tabuleiro final
    int contadorjogos;
    int posicaojogada;
    int jogador;
    int vencedor;
    int jogadas;
    pjogo prox;
};

void jogar(jogo *r);
void jogar_jogador(jogo *r);
void escolhe_jogada(jogo *r, char **p, int n, int n_jogador);
void escolhe_tabuleiro(int posicao);
int verifica(char **p, int n);
void escreve_resultado(int ganhou);
void escreve_resultadoFinal(int ganhou);
void resultados_jogos(jogo r);
void tabuleiro_final(jogo *r);
pjogo adicionatabuleiro(pjogo p);
void criaFicheiroTXT();

#endif //TP2022_JOGO_H
