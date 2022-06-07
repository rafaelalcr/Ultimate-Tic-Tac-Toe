// Rafaela Fonseca Santos nº 2017019717

#ifndef TP2022_LISTALIGADA_H
#define TP2022_LISTALIGADA_H

#include "jogo.h"

typedef struct listajogadas lista, *pjogada;
struct listajogadas {
    int jogador;                // número do jogador que fez a jogada
    int tabuleiro;              // número do tabuleiro em que foi feita a jogada
    int posicao;                // posição da jogada
    int vencedores[N];          // array com os resultados dos mini tabuleiros (1, 2 ou 0)
    int terminados[N];          // array com a ordem dos mini tabuleiros terminados
    pjogada ant;
    pjogada prox;
};

pjogada recuperarjogo(pjogada p);           // permitir a continuação de um jogo anterior caso o ficheiro exista
void listajogadas(pjogada p);
int interrompejogo(pjogada p);              // perguntar ao utilizador se quer interromper o jogo
void preenchelista(pjogada p, int jogador, int tabuleiro, int posicao);
pjogada inserejogada(pjogada p, int jogador, int tabuleiro, int posicao);
void libertalista(pjogada p);
void gravalistatxt(pjogada p, char* nomeF);
void gravalistabin(pjogada p, char* nomeF);
void lelistabin(pjogada p, char* nomeF);
pjogada recuperalista(char *nomeF);


#endif //TP2022_LISTALIGADA_H
