#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include "pacman.h"
#include "mapa.c"

MAPA m;
POSICAO pacman;
int tempilula = 0;

int praondefantasmavai(int xatual, int yatual, int* destinox, int* destinoy) {
    int opcoes[4][2] = {
            { xatual, yatual+1 },
            { xatual+1, yatual },
            { xatual, yatual-1 },
            { xatual-1, yatual }
    };

    srand(time(0));
    for (int i = 0; i < 10; i++) {
        int posicao = rand() % 4;

        if(posicaoehvalida(&m, FANTASMA,opcoes[posicao][0], opcoes[posicao][1])) {
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
    for (int i = 0; i < m.linhas; i++) {
        for (int j = 0; j < m.colunas; j++) {
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
    POSICAO posicao;
    int pacmannomapa = encontramapa(&m, &posicao, PACMAN);
    return !pacmannomapa;
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
        case BOMBA:
            explodepilula();
            break;
        default:
            wprintf(L"Comando inválido\n");
            break;
    }
    if(ehpersonagem(&m, PILULA, proximox, proximoy)) {
        tempilula = 1;
        andapelomapa(&m, pacman.x, pacman.y, proximox, proximoy);
        pacman.x = proximox;
        pacman.y = proximoy;
    }
    else if(posicaoehvalida(&m, PACMAN, proximox, proximoy)) {
        andapelomapa(&m, pacman.x, pacman.y, proximox, proximoy);
        pacman.x = proximox;
        pacman.y = proximoy;
    } else {
        wprintf(L"Posição inválida!\n");
        return;
    }
}

void explodepilula() {
    explodepilula2(pacman.x, pacman.y, 0, 1, 3);
    explodepilula2(pacman.x, pacman.y, 0, -1, 3);
    explodepilula2(pacman.x, pacman.y, 1, 0, 3);
    explodepilula2(pacman.x, pacman.y, -1, 0, 3);
}

void explodepilula2(int x, int y, int somax, int somay, int qtde) {
    if(qtde == 0) return;
    int novox = x + somax;
    int novoy = y + somay;
    if(eholimitedomapa(&m, novox, novoy)) return;
    if(ehparede(&m, novox, novoy)) return;

    m.matriz[novox][novoy] = VAZIO;
    explodepilula2(novox, novoy, somax, somay, qtde - 1);
}

int main() {
    setlocale(LC_ALL, "Portuguese");
    lemapa(&m);
    encontramapa(&m, &pacman, PACMAN);
    do {
        wprintf(L"Tem pilula: %s\n", (tempilula ? L"SIM" : L"NÃO"));
        imprimemapa(&m);
        char comando;
        scanf(" %c", &comando);
        move(comando);
        fantasmas();
    } while (!acabou());
    liberamapa(&m);

    return 0;
}
