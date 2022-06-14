// Rafaela Fonseca Santos nº 2017019717

#include "matdin.h"

void libertaMat(char** p, int nLin){
    for(int i=0; i<nLin; i++)
        free(p[i]);
    free(p);
}

char** criaMat(int nLin, int nCol){
    char **p = NULL;
    int i, j;

    p = malloc(sizeof(char*) * nLin);
    if(p == NULL)
        return NULL;

    for(i=0; i<nLin; i++){
        p[i] = malloc(sizeof(char) * nCol);
        if(p[i] == NULL){
            libertaMat(p, i-1);
            return NULL;
        }
        for(j=0; j<nCol; j++)
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

