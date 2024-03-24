#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct brinquedo Brinquedo;

void contaBrinquedos(int * qtdBrinquedos);

Brinquedo * criaLista(int * qtdBrinquedos);

void preencheDados(Brinquedo * brinquedos, int qtdBrinquedos);

void addBrinquedo(int * qtdBrinquedos);

int comparaNome(const void * p1, const void * p2);

void ordenaNome(Brinquedo * brinquedos, int qtdBrinquedos);

void alteraEstoque(Brinquedo * brinquedos, int qtdBrinquedos);
