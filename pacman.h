//
// Created by Otavio on 30/07/2021.
//

#ifndef PACMAN_PACMAN_H
#define PACMAN_PACMAN_H
void liberamapa();
void lemapa();
void imprimemapa();
void alocamapa();
int acabou();
void move(char);

struct mapa {
    char** matriz;
    int linhas;
    int colunas;
};
#endif //PACMAN_PACMAN_H
