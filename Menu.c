#pragma once

#include <stdio.h>
#include "Assinaturas.h"

int Menu(){

    printf("\n================================= Bem-vindo ao jogo (FOGE - FOGE) =================================\n\n");

    Menu_Movimento();

    int op = 0;

    do{

        printf("%s", ((op != 0) && (op != 1) ? "\nOpção indisponível, tente novamente...\n" : ""));

        printf("Digite '1' para começar e '0' para sair: ");
        scanf("%d", &op);

    }while((op != 0) && (op != 1));

    printf("\n");

    return op;
}

void Menu_Movimento(){

    printf("\nMENU DE AÇÕES\n");
    printf("\nW - CIMA.\nA - ESQUERDA.\nD - DIREITA.\nS - BAIXO.\nB - BOMBA (ELA EXPLODE PARA ESQUERDA E DIREIRA NUMA DISTÂNCIA DE 3 POSIÇÕES).\n\n\n");
}