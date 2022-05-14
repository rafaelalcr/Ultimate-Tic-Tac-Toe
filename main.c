#include "menu.h"

int main() {
    menu();

    return 0;
}

// TODO
//  -> guardar o jogo num ficheiro binário quando há interrupção
//  -> guardar o jogo num ficheiro de texto quando o jogo acabar
//  -> antes de cada jogada, perguntar ao utilizador se quer ver as jogadas anteriores
//  -> a sucessão de jogadas realizadas devem ser mantidas numa lista ligada simples
//  -> encontrar forma de conseguir passar para o tabuleiro seguinte consoante a posição jogada, nada haver com listas ligadas
//  -> lista ligada é só para as jogadas, ou seja, utilizar o p->prox e p->ant para as visualização das jogadas