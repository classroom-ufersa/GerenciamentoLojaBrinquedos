#include <stdio.h>
#include <stdlib.h>

typedef struct sessao Sessao;

Sessao * criaListaSessao(void);

Sessao * preencheNo(Sessao * sessoes, Sessao * aux);

void contaSessoes(int * qtdSessoes);

Sessao * preencheListaSessoes(Sessao * sessoes, int * qtdSessao);

void imprimeSessao(Sessao * sessoes);

void imprimeDatabase(Sessao * sessoes);

Sessao * adicionaSessao(Sessao * sessoes, int * qtdSessoes);

Sessao * removeSessao(Sessao * sessoes, int * qtdSessoes, int idDesejado);
