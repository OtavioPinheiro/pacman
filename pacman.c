#include <stdio.h>
#include <stdlib.h>
# include <locale.h>
#include "pacman.h"
#include "mapa.c"

MAPA m;
POSICAO pacman;

void fantasmas() {
    MAPA auxiliar;
    mapaauxiliar(&auxiliar, &m);
    for (int i = 0; i < m.linhas; ++i) {
        for (int j = 0; j < m.colunas; ++j) {
            if(auxiliar.matriz[i][j] == FANTASMA) {
                if(posicaoehvalida(&m, i, j+1)) {
                    andapelomapa(&m, i, j, i, j+1);
                }
            }
        }
    }
    liberamapa(&auxiliar);
}

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
        andapelomapa(&m, pacman.x, pacman.y, proximox, proximoy);
        pacman.x = proximox;
        pacman.y = proximoy;
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
        fantasmas();
    } while (!acabou());
    liberamapa(&m);

    return 0;
}
