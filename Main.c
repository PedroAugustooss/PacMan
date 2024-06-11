#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "Mapa.h"
#include "Assinaturas.h"
#include "UI.h"
#include "Menu.c"
#include "Loop_Game.c"
#include "Mapa.c"
#include "Imprime_Mapa.c"
#include "Desenhos.c"
#include "Localiza.c"
#include "Movimentos.c"
#include "Comandos.c"
#include "Explocoes.c"

Mapa map;
Posicao hero;

int pilula = 0;

char desenho_parede[4][7] = {
	{"......" },
	{"......" },
	{"......" },
	{"......" }
};

char desenho_ghost[4][7] = {
	{" .-.  " },
	{"| OO| " },
	{"|   | " },
	{"'^^^' " }
};

char desenho_hero[4][7] = {
	{" .--. "  },
	{"/ _.-'"  },
	{"\\  '-." },
	{" '--' "  }
};

char desenho_pilula[4][7] = {
	{"      "},
	{" .-.  "},
	{" '-'  "},
	{"      "}
};

char desenho_vazio[4][7] = {
	{"      "},
	{"      "},
	{"      "},
	{"      "}
};

int main(){

    system("chcp 65001");
  
    int op = 0, cont = 0;

	if(Menu()){

		Pega_Mapa(&map);
		Encontra_Heroi(&map, &hero);

		Loop_Jogo(&map, &op, &cont);

		Desenha_Simbolo(op);

		Libera_Mapa(&map);
	}
	
	printf("\nObrigado por jogar!\n");

    return 0;
}