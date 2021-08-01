#include <stdio.h>
#include <stdlib.h>
# include <locale.h>
#include "pacman.h"
#include "mapa.c"

MAPA m;
POSICAO pacman;

int acabou() {
    return 0;
}

void move(char direcao) {
    int proximox = pacman.x;
    int proximoy = pacman.y;

    switch (direcao) {
        case ESQUERDA:
            proximoy--;
            break;
        case CIMA:
            proximox--;
            break;
        case BAIXO:
            proximox++;
            break;
        case DIREITA:
            proximoy++;
            break;
        default:
            wprintf(L"Comando inválido\n");
            break;
    }
    if(posicaoehvalida(&m, proximox, proximoy)) {
        andapelomapa(&m, &pacman.x, &pacman.y, proximox, proximoy);
    } else {
        wprintf(L"Posição inválida!\n");
        return;
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    lemapa(&m);
    encontramapa(&m, &pacman, PACMAN);
    do {
        imprimemapa(&m);
        char comando;
        scanf(" %c", &comando);
        move(comando);
    } while (!acabou());
    liberamapa(&m);

    return 0;
}
