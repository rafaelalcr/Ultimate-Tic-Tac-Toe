// Rafaela Fonseca Santos nº 2017019717

#ifndef TP2022_LISTALIGADA_H
#define TP2022_LISTALIGADA_H

#include "jogo.h"

typedef struct listajogadas lista, *pjogada;
struct listajogadas {
    int jogador;                // número do jogador que fez a jogada
    int tabuleiro;              // número do tabuleiro em que foi feita a jogada
    int posicao;                // posição da jogada
    int jogadas;                // número de jogadas feitas pelo utilizador
    int jogos;                  // número de jogos terminados
    int vencedortab[N];         // array com os resultados dos mini tabuleiros (1, 2 ou 0)
    int minitab[N];             // array com a ordem dos mini tabuleiros terminados
    int jogadastab[N];          // array que guarda o número de jogadas feitas em cada tabuleiro
    pjogada ant;
    pjogada prox;
};

pjogada recuperarjogo(pjogada p);           // permitir a continuação de um jogo anterior caso o ficheiro exista
void preenchelista(pjogada p, int jogador, int tabuleiro, int posicao, int jogadas, int jogos,
                   const int *vencedortab, const int *minitab, const int *jogadastab);
pjogada insereinfo(pjogada p, int jogador, int tabuleiro, int posicao, int jogadas, int jogos,
                     const int *vencedortab, const int *minitab, const int *jogadastab);
void listajogadas(pjogada p);
int interrompejogo(pjogada p);              // perguntar ao utilizador se quer interromper o jogo
void libertalista(pjogada p);
void gravalistatxt(pjogada p, char* nomeF);
void gravalistabin(pjogada p, char* nomeF);
void lelistabin(pjogada p, char* nomeF);
pjogada recuperalista(char *nomeF);


#endif //TP2022_LISTALIGADA_H
