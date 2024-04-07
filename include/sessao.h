#include <stdio.h>
#include <stdlib.h>
#include "../include/brinquedos.h"

typedef struct sessao Sessao;

typedef struct lista Lista;

Sessao * criaListaSessao(void);

Sessao * preencheNo(Sessao * sessoes, Sessao * aux);

void contaSessoes(int * qtdSessoes);

Sessao * preencheListaSessoes(Sessao * sessoes, int * qtdSessao);

void imprimeSessao(Sessao * sessoes);