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

            while(p->prox != NULL)          // vai até encontrar a última informação adicionada
                p = p->prox;

            for(int i = 0; i < numero; i++) {   // mostra a lista pela última informação adicionada
                printf("Jogador %d # tabuleiro %d # posicao %d\n", p->jogador, p->tabuleiro, p->posicao);
                p = p->ant;
            }
        }
    }
    else if (resposta == 0)
        printf("Sem visualizacao.\n");
}

void preenchelista(pjogada p, int jogador, int tabuleiro, int posicao) {
    p->jogador = jogador;
    p->tabuleiro = tabuleiro;
    p->posicao = posicao;
    p->prox = NULL;
}

pjogada inserejogada(pjogada p, int jogador, int tabuleiro, int posicao) {
    pjogada novo, aux;
    novo = malloc(sizeof(lista));
    if(novo == NULL) {
        printf("Erro na alocacao de memoria\n");
        return p;
    }
    preenchelista(novo, jogador, tabuleiro, posicao);
    if(p == NULL)
        p = novo;
    else {
        aux = p;
        while(aux->prox != NULL)
            aux = aux->prox;
        novo->prox = aux->prox;
        if(aux->prox != NULL)
            aux->prox->ant = novo;
        novo->ant = aux;
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

void gravalista(pjogada lista, char* nomeF) {
    FILE *f;
    f = fopen(nomeF, "w");
    if(f == NULL)
        printf("Erro de abertura\n");
    else {
        while (lista != NULL) {
            fprintf(f, " Jogador %d # tabuleiro %d # posicao %d", lista->jogador, lista->tabuleiro, lista->posicao);
            lista = lista->prox;
        }
        fclose(f);
    }
    printf("\nJogo guardado em ficheiro.\n");
}

pjogada recuperalista(char *nomeF){
    pjogada novo, aux, listajogadas = NULL;
    FILE *f;
    lista l;
    f = fopen(nomeF, "r");
    if(f == NULL)
        return NULL;
    while(fscanf(f, " Jogador %d[^#] # Tabuleiro %d[^#] # Posicao %d",
                 &l.jogador, &l.tabuleiro, &l.posicao) != EOF){
        l.prox = NULL;
        novo = malloc(sizeof(lista));
        if(novo == NULL){
            fclose(f);
            libertalista(listajogadas);
            return NULL;
        }
        *novo = l;
        if(listajogadas == NULL)
            listajogadas = novo;
        else{
            aux = listajogadas;
            while(aux->prox != NULL)
                aux = aux->prox;
            aux->prox = novo;
        }
    }
    fclose(f);
    return listajogadas;
}
