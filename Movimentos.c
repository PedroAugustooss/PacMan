#pragma once

#include <stdio.h>
#include "Assinaturas.h"
#include "Mapa.h"

extern Mapa map;
extern int pilula;

void Move(char direcao, Posicao* hero_position, Mapa* map){

    if(!Letra_Direcao(direcao)){

        return;
    }

    int novoX = hero_position -> x, novoY = hero_position -> y;

    Define_Nova_Posicao(&novoX, &novoY, direcao);

    if(Encontrou_Pilula(map, hero_position, novoX, novoY)){

        pilula++;

        return;
    }

    if(!Direcao_Valida(map, novoX, novoY)){

        return;
    }

    Nova_Posicao_Heroi(map, hero_position, novoX, novoY);
}

void Move_Fantasma(){

    Mapa copia;

    Copia_Mapa(&copia, &map);

    for(int i = 0; i < map.linhas; i++){
        for(int j = 0; j < map.colunas; j++){

            if(copia.matriz[i][j] == GHOST){

                int destinoX, destinoY;

                if(Direcao_Fantasma(i, j, &destinoX, &destinoY)){

                    Nova_Posicao_Ghost(&map, i, j, destinoX, destinoY);
                }
            }
        }
    }

    Libera_Mapa(&copia);
}

int Direcao_Fantasma(int atualX, int atualY, int* destinoX, int* destinoY){

    int opcoes[4][2] = {{atualX, atualY - 1}, {atualX - 1, atualY}, {atualX, atualY + 1}, {atualX + 1, atualY}};

    srand(time(0));

    for(int i = 0; i < 10; i++){

        int posicao = rand() % 4;

        if(Direcao_Valida(&map, opcoes[posicao][0], opcoes[posicao][1])){

            (*destinoX) = opcoes[posicao][0];
            (*destinoY) = opcoes[posicao][1];

            return 1;
        }
    }

    return 0;
}

int Direcao_Valida(Mapa* map, int novoX, int novoY){

    return ((map -> matriz[novoX][novoY] == VAZIO) || (map -> matriz[novoX][novoY] == HERO)) && ((novoX + 1) < map -> linhas) && ((novoY + 1) < map -> colunas);
}

void Nova_Posicao_Ghost(Mapa* map, int x, int y, int novoX, int novoY){

    map -> matriz[novoX][novoY] = GHOST;
    map -> matriz[x][y] = VAZIO;
}

void Nova_Posicao_Heroi(Mapa* map, Posicao* hero_position, int novoX, int novoY){

    map -> matriz[novoX][novoY] = HERO;
    map -> matriz[hero_position -> x][hero_position -> y] = VAZIO;

    hero_position -> x = novoX;
    hero_position -> y = novoY;
}