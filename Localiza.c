#pragma once

#include <stdio.h>
#include "Assinaturas.h"
#include "Mapa.h"

extern Mapa map;
extern Posicao hero;

int Encontra_Mob(Mapa* map, int* op, char mob){

    for(int i = 0; i < (map -> linhas); i++){
        for(int j = 0; j < (map -> colunas); j++){

            if((map -> matriz[i][j]) == mob){

                (*op) = 1;

                return 1;
            }
        }
    }

    (*op) = 0;

    return 0;
}

int Heroi_Vivo(int* op){

    Posicao pos;

    if(!Encontra_Heroi(&map, &pos)){

        Imprime_Mapa_Final(&map, &hero);

        (*op) = 1;

        return 0;
    }

    return 1;
}

int Encontra_Heroi(Mapa* map, Posicao* hero_position){

    for(int i = 0; i < map -> linhas; i++){
        for(int j = 0; j < map -> colunas; j++){

            if(map -> matriz[i][j] == HERO){

                hero_position -> x = i;
                hero_position -> y = j;

                return 1;
            }
        }
    }

    return 0;
}

int Encontrou_Pilula(Mapa* map, Posicao* hero_position, int novoX, int novoY){

    if(map -> matriz[novoX][novoY] == PILULA){

        Nova_Posicao_Heroi(map, hero_position, novoX, novoY);

        return 1;
    }
    
    return 0;
}

int Parede_Localizada(Mapa* map, int x, int y){

    return (map -> matriz[x][y] == PAREDE_HORIZONTAL) || (map -> matriz[x][y] == PAREDE_VERTICAL);
}