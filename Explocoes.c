#pragma once

#include <stdio.h>
#include "Assinaturas.h"
#include "Mapa.h"

extern Mapa map;

int Pode_Explodir(Mapa* map, int x, int y){

    return (map -> matriz[x][y] != PILULA);
}

int Condicoes_Explosao(Mapa* map, int x, int y, int sentido){

    return (Parede_Localizada(map, x, (y + sentido))) || (!Pode_Explodir(map, x, (y + sentido)));
}

void Interface_Explode(int x, int y){

    Explode(x, y, 1, QTD);
    Explode(x, y, -1, QTD);
}

void Explode(int x, int y, int sentido, int qtd){

    if(qtd == 0){

        return;
    }
    
    if(Condicoes_Explosao(&map, x, y, sentido)){

        return;
    }

    map.matriz[x][(y + sentido)] = VAZIO;

    Explode(x, (y + sentido), sentido, (qtd - 1));
}