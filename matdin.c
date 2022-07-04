#include "matdin.h"

void libertaMat(char** p, int nLin){
    for(int i=0; i<nLin; i++)
        free(p[i]);     // liberta a memória reservada para o tamanho das linhas
    free(p);            // liberta o resta da memória que ficou reservada para o tamanho das colunas
}

char** criaMat(int nLin, int nCol){
    char **p = NULL;
    int i, j;

    p = malloc(sizeof(char*) * nLin);   // reserva espaço na memória com o tamanho do número de linhas

    if(p == NULL)                       // verifica-se se a matriz está vazia
        return NULL;

    for(i=0; i<nLin; i++){
        p[i] = malloc(sizeof(char) * nCol); // reserva espaço na memória com o tamanho do número de colunas
        if(p[i] == NULL){                   // verifica-se se a matriz está vazia
            libertaMat(p, i-1);             // se estiver vazia, é libertada a memória
            return NULL;
        }
        for(j=0; j<nCol; j++)               // imprime o desenho da matriz
            p[i][j] = '_';
        }

    return p;
}

void setPos(char **p, int x, int y, char c){
    p[x][y] = c;
}

void mostraMat(char **p, int nLin, int nCol){
    printf("  ______________    ______________    ______________\n");
    for(int i=0; i<nLin; i++){
        printf(" | ");
        for(int j=0; j<nCol; j++) {
            printf("%c ", p[i][j]);
            if(j == 2 || j == 5)
                printf(" | ");
            printf(" | ");
        }
        putchar('\n');
        if(i == 2 || i == 5)
            printf("  ______________    ______________    ______________\n");
    }
    printf("  ______________    ______________    ______________\n\n");
}

void mostraMatFinal(char **p, int nLin, int nCol){
    printf("------------------------------------\n");
    printf("|          TABULEIRO FINAL         |\n");
    printf("------------------------------------\n\n");

    printf("  ______________\n");
    for(int i=0; i<nLin; i++){
        printf(" | ");
        for(int j=0; j<nCol; j++) {
            printf("%c ", p[i][j]);
            printf(" | ");
        }
        putchar('\n');
    }
    printf("  ______________\n\n");
}

