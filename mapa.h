#ifndef PACMAN_MAPA_H
#define PACMAN_MAPA_H
#define PACMAN '@'
#define FANTASMA 'F'
#define VAZIO '.'
#define PAREDE_HORIZONTAL '-'
#define PAREDE_VERTICAL '|'

struct mapa {
    char** matriz;
    int linhas;
    int colunas;
};
typedef struct mapa MAPA;

struct posicao {
    int x;
    int y;
};
typedef struct posicao POSICAO;

int posicaoehvalida(MAPA* m, int x, int y);
void liberamapa(MAPA* m);
void lemapa(MAPA* m);
void imprimemapa(MAPA* m);
void alocamapa(MAPA* m);
void andapelomapa(MAPA* m, int origemx, int origemy, int destinox, int destinoy);
void encontramapa(MAPA* m, POSICAO* p, char c);
void mapaauxiliar(MAPA* destino, MAPA* origem);
#endif//PACMAN_MAPA_H