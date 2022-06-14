// Rafaela Fonseca Santos nº 2017019717

#include <unistd.h>
#include "listaligada.h"

pjogada recuperarjogo(pjogada p) {
    int resposta;
    FILE *f;

    if ((f = fopen("jogo.bin", "rb"))) {    // verificar se o ficheiro existe
        do {
            printf("Deseja recuperar o jogo? (Sim: 1/Nao: 0)\n");
            scanf("%d", &resposta);
        } while (resposta < 0 || resposta > 1);

        if (resposta == 1) {
            p = recuperalista("jogo.bin");
            printf("Jogo recuperado.\n");
        }
        putchar('\n');
    }

    fclose(f);

    return p;
}

pjogada recuperalista(char *nomeF){
    pjogada novo, aux, listainfo = NULL;
    FILE *f;
    lista l;

    f = fopen(nomeF, "rb");
    if (f == NULL)
        printf("Erro de abertura do ficheiro.\n");

    while (fread(&l, sizeof(int), 3, f) != EOF){
        l.prox = NULL;
        novo = malloc(sizeof(lista));
        if (novo == NULL) {
            fclose(f);
            libertalista(listainfo);
            return NULL;
        }
        *novo = l;
        if (listainfo == NULL)
            listainfo = novo;
        else {
            aux = listainfo;
            while(aux->prox != NULL)
                aux = aux->prox;
            aux->prox = novo;
        }
    }

    fclose(f);

    return listainfo;
}

void preenchelista(pjogada p, int njogador, int ntabuleiro, int posicao, int njogadas) {
    p->njogador = njogador;
    p->ntabuleiro = ntabuleiro;
    p->posicao = posicao;
    p->njogadas = njogadas;
    p->prox = NULL;
}

pjogada insereinfo(pjogada p, int njogador, int ntabuleiro, int posicao, int njogadas) {
    pjogada novo, aux;
    novo = malloc(sizeof(lista));

    if(novo == NULL) {
        printf("Erro na alocacao de memoria.\n");
        return p;
    }

    preenchelista(novo, njogador, ntabuleiro, posicao, njogadas);

    if(p == NULL)                   // caso a lista esteja vazia
        p = novo;
    else {
        aux = p;
        while(aux->prox != NULL)    // enquanto a lista não chegar ao fim
            aux = aux->prox;        // avança
        novo->ant = aux;            // o anterior elemento do "novo" é o elemento "aux"
        aux->prox = novo;           // o próximo elemento do "aux" é o elemento "novo"
    }
    return p;
}

void listajogadas(pjogada p) {
    int resposta, numero, diferenca;

    do {
        printf("-> Ver lista de jogadas? (Sim: 1/Nao: 0)\n");
        scanf("%d", &resposta);
    } while(resposta < 0 || resposta > 1);

    if (resposta == 1) {
        if (p == NULL)
            printf("Sem jogadas.\n");

        do {
            printf("Numero de jogadas a visualizar?\n");
            scanf("%d", &numero);
        } while (numero < 1 || numero > 10);

        while(p->prox != NULL)              // vai até encontrar a última informação da lista
            p = p->prox;

        if(numero > p->njogadas) {
            diferenca = numero - p->njogadas;
            for(int i = 0; i < numero - diferenca; i++) {   // mostra a lista pela última informação adicionada
                printf("Jogador %d # tabuleiro %d # posicao %d\n", p->njogador, p->ntabuleiro, p->posicao);
                p = p->ant;
            }
        }
        else if(numero <= p->njogadas) {
            for(int i = 0; i < numero; i++) {   // mostra a lista pela última informação adicionada
                printf("Jogador %d # tabuleiro %d # posicao %d\n", p->njogador, p->ntabuleiro, p->posicao);
                p = p->ant;
            }
        }
    }
}

void libertalista(pjogada p) {
    pjogada aux;
    while (p != NULL) {
        aux = p;
        p = p->prox;
        free(aux);
    }
}

int interrompejogo(pjogada p) {
    int resposta;

    do {
        printf("-> Interromper o jogo? (Sim: 1/Nao: 0)\n");
        scanf("%d", &resposta);
    } while(resposta < 0 || resposta > 1);

    if (resposta == 1) {
        gravalistabin(p, "jogo.bin");
        return 1;
    }
    return 0;
}

void escreveinfo(pjogada p, FILE *f) {
    while(p->prox != NULL)
        p = p->prox;

    fprintf(f, "%d", p->njogadas);
}

void gravalistatxt(pjogada p) {
    FILE *f;
    char nomeF[15];

    printf("Nome do ficheiro?");
    scanf("%s", nomeF);

    f = fopen(nomeF, "w");
    if (f == NULL)
        printf("Erro de abertura do ficheiro.\n");

    escreveinfo(p, f);

    while (p != NULL) {
        fprintf(f, "Jogador %d # Tabuleiro %d # Posicao %d\n", p->njogador, p->ntabuleiro, p->posicao);
        p = p->prox;
    }

    fclose(f);

    printf("\nJogo guardado em ficheiro de texto.\n\n");
}

void gravalistabin(pjogada p, char* nomeF) {
    FILE *f;
    f = fopen(nomeF, "wb");
    if (f == NULL)
        printf("Erro de abertura do ficheiro.\n");

    while (p != NULL) {
        fprintf(f, "%d # %d # %d", p->njogador, p->ntabuleiro, p->posicao);
        p = p->prox;
    }

    fclose(f);

    printf("\nJogo guardado em ficheiro binario.\n\n");
}