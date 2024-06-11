#pragma once

#include <stdio.h>
#include "Assinaturas.h"
#include "Mapa.h"

extern Mapa map;
extern int pilula;

int Sem_Saida(Mapa* map, int* op, int tem_ghost){

    if(tem_ghost == 0){

        return 0;
    }

    if((pilula == 0) && (Encontra_Mob(map, op, PILULA) == 0) && (0 < tem_ghost)){

        return 1;
    }

    return 0;
}

void Loop_Jogo(Mapa* map, int* op, int* cont){

    int tem_ghost;

    do{

        if((*cont)){

            system("cls");
        }

        (*cont) = 1;

        printf("TEM PÍLULAS: %s.\nQUANTIDADE: %d.\n\n", (pilula > 0) ? "SIM" : "NÃO", pilula);

        Imprime_Mapa(map);

        Pega_Comando(map);

        tem_ghost = Encontra_Mob(map, op, GHOST);

        if(Sem_Saida(map, op, tem_ghost)){

            (*op) = 2;

            return;
        }

    }while((tem_ghost && Heroi_Vivo(op)));

    system("cls");

    Imprime_Mapa(map);
}