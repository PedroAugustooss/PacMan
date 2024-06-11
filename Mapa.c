#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "Assinaturas.h"
#include "Mapa.h"

void Pega_Mapa(Mapa* map){

    FILE* f;

    f = fopen("Mapa.txt", "r");

    if(f == 0){
        
        printf("\nErro ao ler o arquivo!\n");
        exit(1);
    }

    fscanf(f, "%d %d", &(map -> linhas), &(map -> colunas));

    //printf("\nLinhas: %d e Colunas: %d.\n\n", map -> linhas, map -> colunas);

    Aloca_Memoria_Mapa(map);

    for(int i = 0; i < (map -> linhas); i++){
        
        fscanf(f, "%s", map -> matriz[i]);
    }

    fclose(f);
}

void Copia_Mapa(Mapa* destino, Mapa* origem){

    destino -> linhas = origem -> linhas;
    destino -> colunas = origem -> colunas;

    Aloca_Memoria_Mapa(destino);

    for(int i = 0; i < (origem -> linhas); i++){

        strcpy(destino -> matriz[i], origem -> matriz[i]);
    }
}

void Aloca_Memoria_Mapa(Mapa* map){

    map -> matriz = malloc(sizeof(char*) * (map -> linhas));

    for(int i = 0; i < map -> linhas; i++){

        map -> matriz[i] = malloc(sizeof(char) * (map -> colunas + 1));
    }
}

void Libera_Mapa(Mapa* map){

    for(int i = 0; i < (map -> linhas); i++){

        free(map -> matriz[i]);
    }

    free(map -> matriz);
}