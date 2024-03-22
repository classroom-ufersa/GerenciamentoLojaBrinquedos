#include <stdio.h>
#include <stdlib.h>

typedef struct brinquedo Brinquedo;

Brinquedo * contaBrinquedos(int * qtdBrinquedos);

void preencheDados(Brinquedo * brinquedos, int qtdBrinquedos);

void addBrinquedo(int * qtdBrinquedos);