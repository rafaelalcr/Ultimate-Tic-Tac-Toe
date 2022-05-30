// Rafaela Fonseca Santos nº 2017019717

#include "listaligada.h"

void listajogadas(pjogada p) {
    char resposta;
    int numero, diferenca;
    printf("-> Ver lista de jogadas?");
    scanf("%s", &resposta);
    if(strcmp(&resposta, "sim") == 0) {
        do {
            printf("Numero de jogadas a visualizar?");
            scanf("%d", &numero);
        } while (numero < 1 || numero > 10);

        if(p == NULL)
            printf("Sem jogadas.\n");
        /*else if(p->jogadas < numero) {
            diferenca = numero - p->jogadas;
            for(int i = 0; i < (numero - diferenca); i++) {
                printf("# Jogador %d -> tabuleiro %d -> posicao %d\n", p->jogador, p->tabuleiro, p->posicao);
                p = p->prox;
            }
        }*/
        else {
            for(int i=0; i<numero; i++) {
                printf("# Jogador %d -> tabuleiro %d -> posicao %d\n", p->jogador, p->tabuleiro, p->posicao);
                p = p->prox;
            }
        }
        /*while(p != NULL) {
            printf("Jogador %d # tabuleiro %d # posicao %d\n", p->jogador, p->tabuleiro, p->posicao);
            p = p->prox;
        }*/
    }
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
