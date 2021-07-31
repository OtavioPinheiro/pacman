#ifndef PACMAN_MAPA_H
#define PACMAN_MAPA_H
struct mapa {
    char** matriz;
    int linhas;
    int colunas;
};
typedef struct mapa MAPA;

void liberamapa(MAPA* m);
void lemapa(MAPA* m);
void imprimemapa(MAPA* m);
void alocamapa(MAPA* m);
#endif//PACMAN_MAPA_H