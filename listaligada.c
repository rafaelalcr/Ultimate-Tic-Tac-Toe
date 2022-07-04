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
            printf("Funcionalidade nao implementada.\n");
        }
        putchar('\n');
    }

    fclose(f);

    return p;
}

void preenchelista(pjogada p, int njogador, int ntabuleiro, int posicao) {
    p->njogador = njogador;
    p->ntabuleiro = ntabuleiro;
    p->posicao = posicao;
    p->prox = NULL;
}

pjogada insereinfo(pjogada p, int njogador, int ntabuleiro, int posicao) {
    pjogada novo, aux;
    novo = malloc(sizeof(lista));

    if(novo == NULL) {
        printf("Erro na alocacao de memoria.\n");
        return p;
    }

    preenchelista(novo, njogador, ntabuleiro, posicao);

    if(p == NULL)                   // caso a lista esteja vazia
        p = novo;
    else {
        aux = p;
        while(aux->prox != NULL)    // enquanto a lista não chegar ao fim
            aux = aux->prox;        // avança
        novo->ant = aux;
        aux->prox = novo;
    }
    return p;
}

void listajogadas(pjogada p) {
    int resposta, numero;

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

        while(p->prox != NULL)      // vai até ao final das jogadas
            p = p->prox;

        for(int i=1; i<numero; i++) // recua o número de jogadas
            p = p->ant;

        while(p != NULL) {          // mostra a partir do número de jogdas que se quer ver
            printf("Jogador %d # tabuleiro %d # posicao %d\n", p->njogador, p->ntabuleiro, p->posicao);
            p = p->prox;
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

void gravalistatxt(pjogada p) {
    FILE *f;
    char nomeF[15];

    printf("Nome do ficheiro?");
    scanf("%s", nomeF);

    f = fopen(nomeF, "w");
    if (f == NULL)
        printf("Erro de abertura do ficheiro.\n");

    fprintf(f, "Lista de jogadas\n");
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
        fprintf(f, "Jogador %d # Tabuleiro %d # Posicao %d\n", p->njogador, p->ntabuleiro, p->posicao);
        p = p->prox;
    }

    fclose(f);

    printf("\nJogo guardado em ficheiro binario.\n\n");
}
