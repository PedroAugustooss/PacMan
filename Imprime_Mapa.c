#pragma once

#include <stdio.h>
#include "Assinaturas.h"
#include "Mapa.h"

extern char desenho_parede[4][7], desenho_ghost[4][7], desenho_hero[4][7], desenho_pilula[4][7], desenho_vazio[4][7];

void Imprime_Parte(char desenho[4][7], int parte){

    printf("%s", desenho[parte]);
}

void Imprime_Mapa(Mapa* map){

    for(int i = 0; i < map -> linhas; i++){

        for(int parte = 0; parte < 4; parte++){

            for(int j = 0; j < map -> colunas; j++){

                switch(map -> matriz[i][j]){

                    case GHOST:
                        Imprime_Parte(desenho_ghost, parte);
                    break;

                    case HERO:
                        Imprime_Parte(desenho_hero, parte);
                    break;

                    case VAZIO:
                        Imprime_Parte(desenho_vazio, parte);
                    break;

                    case PILULA:
                        Imprime_Parte(desenho_pilula, parte);
                    break;

                    case PAREDE_HORIZONTAL:
                    case PAREDE_VERTICAL:
                        Imprime_Parte(desenho_parede, parte);
                    break;                    
                }
            }

            printf("\n");
        }
    }
}

void Imprime_Mapa_Final(Mapa* map, Posicao* hero_position){

    system("cls");

    map -> matriz[hero_position -> x][hero_position -> y] = GHOST;
    Imprime_Mapa(map);
}