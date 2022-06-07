// Rafaela Fonseca Santos nº 2017019717

#include "listaligada.h"

pjogada recuperarjogo(pjogada p) {
    int resposta, valor;
    FILE *f;

    f = fopen("jogo.bin", "rb");

    if(f != NULL) {
        printf("Deseja recuperar o jogo? (Sim: 1/Nao: 0)\n");
        valor = scanf("%d", &resposta);

        if (valor == 0) {
            fputs ("Opcao invalida.\n\n", stderr);
            empty_stdin();
        }

        if(resposta == 1) {
            p = recuperalista("jogo.bin");
            printf("Jogo recuperado.\n");
        }
        putchar('\n');
    }
    return p;
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
        printf("Erro na alocacao de memoria.\n");
        return p;
    }
    preenchelista(novo, jogador, tabuleiro, posicao, jogadas);
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

void listajogadas(pjogada p) {
    int resposta, numero, diferenca, valor;

    printf("-> Ver lista de jogadas? (Sim: 1/Nao: 0)\n");
    valor = scanf("%d", &resposta);

    if (valor == 0) {
        fputs ("Opcao invalida.\n\n", stderr);
        empty_stdin();
    }

    if (resposta == 1) {
        if (p == NULL)
            printf("Sem jogadas.\n");

        do {
            printf("Numero de jogadas a visualizar?\n");
            scanf("%d", &numero);
        } while (numero < 1 || numero > 10);

        while(p->prox != NULL)              // vai até encontrar a última informação da lista
            p = p->prox;

        if(numero > p->jogadas) {
            diferenca = numero - p->jogadas;
            for(int i = 0; i < numero - diferenca; i++) {   // mostra a lista pela última informação adicionada
                printf("Jogador %d # tabuleiro %d # posicao %d\n", p->jogador, p->tabuleiro, p->posicao);
                p = p->ant;
            }
        }
        else if(numero <= p->jogadas) {
            for(int i = 0; i < numero; i++) {   // mostra a lista pela última informação adicionada
                printf("Jogador %d # tabuleiro %d # posicao %d\n", p->jogador, p->tabuleiro, p->posicao);
                p = p->ant;
            }
        }
    }
}

int interrompejogo(pjogada p) {
    int resposta, valor;

    printf("-> Interromper o jogo? (Sim: 1/Nao: 0)\n");
    valor = scanf("%d", &resposta);

    if (valor == 0) {
        fputs ("Opcao invalida.\n\n", stderr);
        empty_stdin();
    }

    if (resposta == 1) {
        gravalistabin(p, "jogo.bin");
        return 1;
    }
    return 0;
}

void libertalista(pjogada p) {
    pjogada aux;
    while (p != NULL) {
        aux = p;
        p = p->prox;
        free(aux);
    }
}

void gravalistatxt(pjogada p, char* nomeF) {
    FILE *f;
    f = fopen(nomeF, "w");
    if (f == NULL)
        printf("Erro de abertura do ficheiro.\n");

    while (p != NULL) {
        fprintf(f, "Jogador %d # tabuleiro %d # posicao %d\n", p->jogador, p->tabuleiro, p->posicao);
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
        fprintf(f, "Jogador %d # tabuleiro %d # posicao %d\n", p->jogador, p->tabuleiro, p->posicao);
        p = p->prox;
    }

    fclose(f);

    printf("\nJogo guardado em ficheiro binario.\n\n");
}

void lelistabin(pjogada p, char* nomeF) {
    FILE *f;
    f = fopen(nomeF, "wb");
    if (f == NULL)
        printf("Erro de abertura do ficheiro.\n");

    fscanf(f, " Jogador %d # tabuleiro %d # posicao %d\n", &p->jogador, &p->tabuleiro, &p->posicao);

    // verifica se a lista funciona
    while (p != NULL) {
        printf("Jogador %d # tabuleiro %d # posicao %d\n", p->jogador, p->tabuleiro, p->posicao);
        p = p->prox;
    }

    fclose(f);
}

pjogada recuperalista(char *nomeF){
    pjogada novo, aux, listajogadas = NULL;
    FILE *f;
    lista l;
    f = fopen(nomeF, "rb");
    if (f == NULL)
        return NULL;
    while (fscanf(f, " Jogador %d[^#] # Tabuleiro %d[^#] # Posicao %d", &l.jogador, &l.tabuleiro, &l.posicao) != EOF){
        l.prox = NULL;
        novo = malloc(sizeof(lista));
        if (novo == NULL) {
            fclose(f);
            libertalista(listajogadas);
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