#ifndef PACMAN_PACMAN_H
#define PACMAN_PACMAN_H
#define CIMA 'w'
#define BAIXO 's'
#define ESQUERDA 'a'
#define DIREITA 'd'
#define BOMBA 'b'

int acabou();
void move(char);
void fantasmas();
int praondefantasmavai(int xatual, int yatual, int* destinox, int* destinoy);
void explodepilula();
void explodepilula2(int x, int y, int somax, int somay, int qtde);

#endif //PACMAN_PACMAN_H
