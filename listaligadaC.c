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

void preenchelistaC(pjogadaC p, int njogador, int ntabuleiro, int posicao, int njogadas, int njogos,
                    int *tab_vencedores, int *tab_terminados, int *tab_jogadas) {
    p->njogador = njogador;
    p->ntabuleiro = ntabuleiro;
    p->posicao = posicao;
    p->njogadas = njogadas;
    p->njogos = njogos;
    for(int i=0; i<N;i++) {
        p->tab_vencedores[i] = tab_vencedores[i];
        p->tab_terminados[i] = tab_terminados[i];
        p->tab_jogadas[i] = tab_jogadas[i];
    }
    p->prox = NULL;
}

pjogadaC insereinfoC(pjogadaC p, int njogador, int ntabuleiro, int posicao, int njogadas, int njogos,
                       int *tab_vencedores, int *tab_terminados, int *tab_jogadas) {
    pjogadaC novo, aux;
    novo = malloc(sizeof(listaC));

    if(novo == NULL) {
        printf("Erro na alocacao de memoria.\n");
        return p;
    }

    preenchelistaC(novo, njogador, ntabuleiro, posicao, njogadas, njogos, tab_vencedores, tab_terminados, tab_jogadas);

    if(p == NULL)                   // caso a lista esteja vazia
        p = novo;
    else {
        aux = p;
        while(aux->prox != NULL)    // enquanto a lista não chegar ao fim
            aux = aux->prox;        // avança
        novo->prox = aux->prox;     // a próxima estrutura que "novo" aponta é igual à próxima estrutura que "aux" aponta
        if(aux->prox != NULL)
            aux->prox->ant = novo;  // onde está a estrutura "aux" situada na lista fica a estrutura "novo"
        novo->ant = aux;            // o anterior da estrutura "novo" é a estrutura "aux"
        aux->prox = novo;           // a próxima estrutura do "aux" é a estrutura "novo"
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

        if(numero > p->njogadas) {
            diferenca = numero - p->njogadas;
            for(int i = 0; i < numero - diferenca; i++) {
                printf("Jogador %d # tabuleiro %d # posicao %d\n", p->njogador, p->ntabuleiro, p->posicao);
                p = p->ant;
            }
        }
        else if(numero <= p->njogadas) {
            for(int i = 0; i < numero; i++) {
                printf("Jogador %d # tabuleiro %d # posicao %d\n", p->njogador, p->ntabuleiro, p->posicao);
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

void escreveinfoC(pjogadaC p, FILE *f) {
    while(p->prox != NULL)
        p = p->prox;

    fprintf(f, "Total de jogos terminados: %d\n", p->njogos);
    fprintf(f, "Total de jogadas realizadas: %d\n", p->njogadas);

    fprintf(f, "Ordem dos vencedores dos tabuleiros:");
    for(int i = 0; i < N; i++)
        fprintf(f, " %d", p->tab_vencedores[i]);
    fprintf(f, "\n");

    fprintf(f, "Ordem dos tabuleiros terminados:");
    for(int i = 0; i < N; i++)
        fprintf(f, " %d", p->tab_terminados[i]);
    fprintf(f, "\n");

    fprintf(f, "Numero de jogadas realizadas:");
    for(int i = 0; i < N; i++)
        fprintf(f, " %d", p->tab_jogadas[i]);
    fprintf(f, "\n");
}

void gravalistatxtC(pjogadaC p, char* nomeF) {
    FILE *f;
    f = fopen(nomeF, "w");
    if (f == NULL)
        printf("Erro de abertura do ficheiro.\n");

    escreveinfoC(p, f);

    fprintf(f, "Lista de jogadas: \n");
    while (p != NULL) {
        fprintf(f, "Jogador %d # Tabuleiro %d # Posicao %d\n", p->njogador, p->ntabuleiro, p->posicao);
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

    escreveinfoC(p, f);

    fprintf(f, "Lista de jogadas: \n");
    while (p != NULL) {
        fprintf(f, "Jogador %d # Tabuleiro %d # Posicao %d\n", p->njogador, p->ntabuleiro, p->posicao);
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

    fscanf(f, " Jogador %d # Tabuleiro %d # Posicao %d\n", &p->njogador, &p->ntabuleiro, &p->posicao);

    // verifica se a lista funciona
    while (p != NULL) {
        printf("Jogador %d # Tabuleiro %d # Posicao %d\n", p->njogador, p->ntabuleiro, p->posicao);
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
    while (fscanf(f, " Jogador %d[^#] # Tabuleiro %d[^#] # Posicao %d", &l.njogador, &l.ntabuleiro, &l.posicao) != EOF){
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
