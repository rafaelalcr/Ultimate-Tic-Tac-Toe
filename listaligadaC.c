// Rafaela Fonseca Santos nº 2017019717

#include "listaligadaC.h"

pjogadaC recuperarjogoC(pjogadaC p) {
    int resposta, valor;
    FILE *f;

    f = fopen("jogoC.bin", "rb");

    if(f != NULL) {
        printf("Deseja recuperar o jogo? (Sim: 1/Nao: 0)\n");
        valor = scanf("%d", &resposta);

        if (valor == 0) {
            fputs ("Opcao invalida.\n\n", stderr);
            empty_stdin();
        }

        if(resposta == 1) {
            p = recuperalistaC("jogo.bin");
            printf("Jogo recuperado.\n");
        }
        putchar('\n');
    }
    return p;
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

void listajogadasC(pjogadaC p) {
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

        while(p->prox != NULL)
            p = p->prox;

        if(numero > p->jogadas) {
            diferenca = numero - p->jogadas;
            for(int i = 0; i < numero - diferenca; i++) {
                printf("Jogador %d # tabuleiro %d # posicao %d\n", p->jogador, p->tabuleiro, p->posicao);
                p = p->ant;
            }
        }
        else if(numero <= p->jogadas) {
            for(int i = 0; i < numero; i++) {
                printf("Jogador %d # tabuleiro %d # posicao %d\n", p->jogador, p->tabuleiro, p->posicao);
                p = p->ant;
            }
        }
    }
}

int interrompejogoC(pjogadaC p) {
    int resposta, valor;

    printf("-> Interromper o jogo? (Sim: 1/Nao: 0)\n");
    valor = scanf("%d", &resposta);

    if (valor == 0) {
        fputs ("Opcao invalida.\n\n", stderr);
        empty_stdin();
    }

    if (resposta == 1) {
        gravalistabinC(p, "jogoC.bin");
        return 1;
    }
    return 0;
}


void libertalistaC(pjogadaC p) {
    pjogadaC aux;
    while (p != NULL) {
        aux = p;
        p = p->prox;
        free(aux);
    }
}

void gravalistatxtC(pjogadaC p, char* nomeF) {
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

void gravalistabinC(pjogadaC p, char* nomeF) {
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

void lelistabinC(pjogadaC p, char* nomeF) {
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
