#include <stdio.h>
#include <stdlib.h>

typedef struct brinquedo Brinquedo;

void contaBrinquedos(int * qtdBrinquedos);

Brinquedo * criaLista(int * qtdBrinquedos);

void preencheDados(Brinquedo * brinquedos, int qtdBrinquedos);

void addBrinquedo(int * qtdBrinquedos);