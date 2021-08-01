#include <stdio.h>
#include <stdlib.h>
# include <locale.h>
#include "pacman.h"
#include "mapa.c"

MAPA m;
POSICAO pacman;

int posicaoehvalida(MAPA* m, int x, int y) {
    if(x >= m->linhas) return 0;
    if(y >= m->colunas) return 0;
    if(m->matriz[x][y] != '.') return 0;
    return 1;
}

int acabou() {
    return 0;
}

void move(char direcao) {
    int proximox = pacman.x;
    int proximoy = pacman.y;

    switch (direcao) {
        case 'a':
            proximoy--;
            break;
        case 'w':
            proximox--;
            break;
        case 's':
            proximox++;
            break;
        case 'd':
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
    encontramapa(&m, &pacman, '@');
    do {
        imprimemapa(&m);
        char comando;
        scanf(" %c", &comando);
        move(comando);
    } while (!acabou());
    liberamapa(&m);

    return 0;
}
