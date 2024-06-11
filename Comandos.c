#pragma once

#include <stdio.h>
#include "Assinaturas.h"
#include "Mapa.h"

extern Mapa map;
extern Posicao hero;
extern int pilula;

void Pega_Comando(){

    char comando;

    printf("\nAÇÂO: ");

    fflush(stdin);

    scanf(" %c", &comando);

    printf("\n");

    Move(tolower(comando), &hero, &map);

    if((tolower(comando) == BOMBA) && (pilula > 0)){

        Usa_Pilula();

        pilula--;
    }

    if(Letra_Direcao(tolower(comando))){

        Move_Fantasma();
    }
}

void Usa_Pilula(){

    Desenha_Bomba();

    Interface_Explode(hero.x, hero.y);
}

int Letra_Direcao(char direcao){

    return (direcao == ESQUERDA) || (direcao == BAIXO) || (direcao == CIMA) || (direcao == DIREITA);
}

void Define_Nova_Posicao(int* x, int* y, char direcao){

    switch(direcao){

        case CIMA:
            (*x)--;
            break;
        case BAIXO:
            (*x)++;
            break;
        case ESQUERDA:
            (*y)--;
            break;
        case DIREITA:
            (*y)++;
            break;

        default:
        break;                
    }
}