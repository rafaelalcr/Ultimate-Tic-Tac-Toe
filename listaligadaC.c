// Rafaela Fonseca Santos nº 2017019717

#include "listaligadaC.h"

void listajogadasC(pjogadaC p) {
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
}

int interrompejogoC(pjogadaC p) {
    // perguntar ao utilizador se quer interromper o jogo
    int resposta;
    printf("-> Interromper o jogo? (Sim: 1/Nao: 0)\n");
    scanf("%d", &resposta);
    if (resposta == 1) {
        gravalistabinC(p, "jogoC.bin");
        return 1;
    }
    return 0;
}

void preenchelistaC(pjogadaC p, int jogador, int tabuleiro, int posicao) {
    p->jogador = jogador;
    p->tabuleiro = tabuleiro;
    p->posicao = posicao;
    p->prox = NULL;
}

pjogadaC inserejogadaC(pjogadaC p, int jogador, int tabuleiro, int posicao) {
    pjogadaC novo, aux;
    novo = malloc(sizeof(listaC));
    if(novo == NULL) {
        printf("Erro na alocacao de memoria.\n");
        return p;
    }
    preenchelistaC(novo, jogador, tabuleiro, posicao);
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

void libertalistaC(pjogadaC p) {
    pjogadaC aux;
    while (p != NULL) {
        aux = p;
        p = p->prox;
        free(aux);
    }
}

void gravalistatxtC(pjogadaC lista, char* nomeF) {
    FILE *f;
    f = fopen(nomeF, "w");
    if (f == NULL)
        printf("Erro de abertura do ficheiro.\n");

    while (lista != NULL) {
        fprintf(f, " Jogador %d # tabuleiro %d # posicao %d\n", lista->jogador, lista->tabuleiro, lista->posicao);
        lista = lista->prox;
    }

    fclose(f);

    printf("\nJogo guardado em ficheiro de texto.\n");
}

void gravalistabinC(pjogadaC lista, char* nomeF) {
    FILE *f;
    f = fopen(nomeF, "wb");
    if (f == NULL)
        printf("Erro de abertura do ficheiro.\n");

    while (lista != NULL) {
        fprintf(f, " Jogador %d # tabuleiro %d # posicao %d\n", lista->jogador, lista->tabuleiro, lista->posicao);
        lista = lista->prox;
    }

    fclose(f);

    printf("\nJogo guardado em ficheiro binario.\n\n");
}

void lelistabinC(pjogadaC lista, char* nomeF) {
    FILE *f;
    f = fopen(nomeF, "wb");
    if (f == NULL)
        printf("Erro de abertura do ficheiro.\n");

    fscanf(f, " Jogador %d # tabuleiro %d # posicao %d\n", &lista->jogador, &lista->tabuleiro, &lista->posicao);

    // verifica se a lista funciona
    while (lista != NULL) {
        printf("Jogador %d # tabuleiro %d # posicao %d\n", lista->jogador, lista->tabuleiro, lista->posicao);
        lista = lista->prox;
    }

    fclose(f);
}

pjogadaC recuperalistaC(char *nomeF){
    pjogadaC novo, aux, listajogadas = NULL;
    FILE *f;
    listaC l;
    f = fopen(nomeF, "rb");
    if (f == NULL)
        return NULL;
    while (fscanf(f, " Jogador %d[^#] # Tabuleiro %d[^#] # Posicao %d", &l.jogador, &l.tabuleiro, &l.posicao) != EOF){
        l.prox = NULL;
        novo = malloc(sizeof(listaC));
        if (novo == NULL) {
            fclose(f);
            libertalistaC(listajogadas);
            return NULL;
        }
        *novo = l;
        if (listajogadas == NULL)
            listajogadas = novo;
        else {
            aux = listajogadas;
            while(aux->prox != NULL)
                aux = aux->prox;
            aux->prox = novo;
        }
    }
    fclose(f);
    return listajogadas;
}
