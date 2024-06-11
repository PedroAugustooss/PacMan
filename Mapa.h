#pragma once

#define PAREDE_HORIZONTAL '-'
#define PAREDE_VERTICAL '|'
#define HERO '@'
#define GHOST 'F'
#define VAZIO '.'
#define PILULA 'P'
#define QTD 3

typedef struct{
    
    int linhas, colunas;
    char** matriz;

}Mapa;

typedef struct{

    int x, y;

}Posicao;

int Encontra_Heroi(Mapa* map, Posicao* p);
int Encontra_Mob(Mapa* map, int* op, char mob);
int Parede_Localizada(Mapa* map, int x, int y);
int Encontrou_Pilula(Mapa* map, Posicao* hero_position, int novoX, int novoY);
int Pode_Explodir(Mapa* map, int x, int y);
int Condicoes_Explosao(Mapa* map, int x, int y, int sentido);
int Direcao_Fantasma(int atualX, int atualY, int* destinoX, int* destinoY);
void Pega_Mapa(Mapa* map);
void Nova_Posicao_Ghost(Mapa* map, int x, int y, int destinoX, int destinoY);
void Move_Fantasma();
void Explode(int x, int y,int sentido, int qtd);
void Desenha_Bomba();
void Usa_Pilula();
void Interface_Explode(int x, int y);
void Copia_Mapa(Mapa* destino, Mapa* origem);
void Libera_Mapa(Mapa* map);
void Aloca_Memoria_Mapa(Mapa* map);
void Nova_Posicao_Heroi(Mapa* map, Posicao* h, int novoX, int novoY);