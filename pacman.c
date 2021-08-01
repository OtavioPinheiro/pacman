#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "pacman.h"
#include "mapa.c"

MAPA m;
POSICAO pacman;

int praondefantasmavai(int xatual, int yatual, int* destinox, int* destinoy) {
    int opcoes[4][2] = {
            { xatual, yatual+1 },
            { xatual+1, yatual },
            { xatual, yatual-1 },
            { xatual-1, yatual }
    };

    srand(time(0));
    for (int i = 0; i < 10; ++i) {
        int posicao = rand() % 4;

        if(posicaoehvalida(&m, opcoes[posicao][0], opcoes[posicao][1])) {
            *destinox = opcoes[posicao][0];
            *destinoy = opcoes[posicao][1];

            return 1;
        }
    }

    return 0;
}

void fantasmas() {
    MAPA auxiliar;
    mapaauxiliar(&auxiliar, &m);
    for (int i = 0; i < m.linhas; ++i) {
        for (int j = 0; j < m.colunas; ++j) {
            if(auxiliar.matriz[i][j] == FANTASMA) {

                int destinox;
                int destinoy;
                int encontrou = praondefantasmavai(i, j, &destinox, &destinoy);

                if(encontrou) {
                    andapelomapa(&m, i, j, destinox, destinoy);
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
