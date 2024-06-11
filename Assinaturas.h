#pragma once

#define CIMA 'w'
#define BAIXO 's'
#define ESQUERDA 'a'
#define DIREITA 'd'
#define BOMBA 'b'

int Heroi_Vivo(int* op);
int Letra_Direcao(char direcao);
int Direcao_Valida(Mapa* map, int novoX, int novoY);

int Menu();
void Menu_Movimento();
void Move(char direcao, Posicao* p, Mapa* map);
void Define_Nova_Posicao(int* x, int* y, char direcao);
void Pega_Comando();
void Desenha_Simbolo(int op);
void Loop_Jogo(Mapa* map, int* op, int* cont);