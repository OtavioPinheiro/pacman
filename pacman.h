#ifndef PACMAN_PACMAN_H
#define PACMAN_PACMAN_H
#define CIMA 'w'
#define BAIXO 's'
#define ESQUERDA 'a'
#define DIREITA 'd'

int acabou();
void move(char);
void fantasmas();
int praondefantasmavai(int xatual, int yatual, int* destinox, int* destinoy);

#endif //PACMAN_PACMAN_H
