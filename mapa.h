#ifndef PACMAN_MAPA_H
#define PACMAN_MAPA_H
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
void encontramapa(MAPA* m, POSICAO* p, char c);
#endif//PACMAN_MAPA_H