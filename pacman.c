#include <stdio.h>
#include <stdlib.h>
#include "pacman.h"
#include "mapa.c"

MAPA m;
POSICAO pacman;

int acabou() {
    return 0;
}

void move(char direcao) {
    int x;
    int y;

    m.matriz[pacman.x][pacman.y] = '.';
    switch (direcao) {
        case 'a':
            m.matriz[pacman.x][pacman.y-1] = '@';
            pacman.y--;
            break;
        case 'w':
            m.matriz[pacman.x-1][pacman.y] = '@';
            pacman.x--;
            break;
        case 's':
            m.matriz[pacman.x+1][pacman.y] = '@';
            pacman.x++;
            break;
        case 'd':
            m.matriz[pacman.x][pacman.y+1] = '@';
            pacman.y++;
            break;
        default:
            printf("Comando inválido\n");
            break;
    }
}

int main() {

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
