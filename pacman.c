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

    if(proximox >= m.linhas) return;
    if(proximoy >= m.colunas) return;
    if(m.matriz[proximox][proximoy] != '.') return;

    m.matriz[proximox][proximoy] = '@';
    m.matriz[pacman.x][pacman.y] = '.';
    pacman.x = proximox;
    pacman.y = proximoy;
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
