// Rafaela Fonseca Santos nº 2017019717

#include "listaligada.h"

void listajogadas(pjogada p) {
    int resposta, numero;
    printf("-> Ver lista de jogadas? (Sim: 1/Nao: 0)\n");
    scanf("%d", &resposta);
    if (resposta == 1) {
        if (p == NULL)
            printf("Sem jogadas.\n");
        else {
            do {
                printf("Numero de jogadas a visualizar?\n");
                scanf("%d", &numero);
            } while (numero < 1 || numero > 10);

            for(int i = 0; i < numero; i++) {
                printf("# Jogador %d -> tabuleiro %d -> posicao %d\n", p->jogador, p->tabuleiro, p->posicao);
                p = p->prox;
            }
        }
    }
    else if (resposta == 0)
        printf("Sem visualizacao.\n");
}

void preenchelista(pjogada p, int jogador, int tabuleiro, int posicao, int jogadas) {
    p->jogador = jogador;
    p->tabuleiro = tabuleiro;
    p->posicao = posicao;
    p->jogadas = jogadas;
    p->prox = NULL;
}

pjogada inserejogada(pjogada p, int jogador, int tabuleiro, int posicao, int jogadas) {
    pjogada novo, aux;
    novo = malloc(sizeof(lista));
    if(novo == NULL) {
        printf("Erro na alocacao de memoria\n");
        return p;
    }
    preenchelista(novo, jogador, tabuleiro, posicao, jogadas);
    if(p == NULL)
        p = novo;
    else {
        aux = p;
        while(aux->prox != NULL)
            aux = aux->prox;
        aux->prox = novo;
    }
    return p;
}

void libertalista(pjogada p) {
    pjogada aux;
    while (p != NULL) {
        aux = p;
        p = p->prox;
        free(aux);
    }
}
