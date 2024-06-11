#pragma once

#include <stdio.h>
#include <stdlib.h>
#include "Assinaturas.h"

extern Mapa map;
extern Posicao hero;

void Desenha_Bomba(){

    printf("                           $#     #     #¢ \n");
    printf("           #######       #¢   #   ø#   \n");
    printf("          ##    ø###      oø  ø  øo    \n");
    printf("          #7       ###      1   1    1o\n");
    printf("       #######       ###7        1o###ø\n");
    printf("       #######         ########  1     \n");
    printf("     o#########ø                  o$¢  \n");
    printf("   ###############          ¢  1ø   1##\n");
    printf("  #################o       1$   #      \n");
    printf(" ###################       #    o#     \n");
    printf(" ####################     ##           \n");
    printf("  ##################                   \n");
    printf("   ################                    \n");
    printf("     ############                      \n");
    printf("       ########                        \n\n\n");
}

void Desenha_Simbolo(int op){

    system("cls");

    Imprime_Mapa(&map);

    if(op == 0){

        printf("\nPARABÉNS, VOCÊ DERROTOU TODOS OS FANTASMAS E SOBREVIVEU!\n\n");

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");
    }
    else if((op == 1) || (op == 2)){

        printf("\nINFELIZMENTE O HERÓI %s...\n\n", (op == 1) ? ("FOI PEGO PELOS FANTASMAS E MORREU") : ("GASTOU TODAS AS PILULAS E NAO CONSEGUIU FUGIR DOS FANTASMAS"));

        printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
    }
}