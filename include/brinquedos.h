#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct sessao Sessao;

typedef struct brinquedo Brinquedo;

void contaBrinquedos(int * qtdBrinquedos);

Brinquedo * criaLista(int * qtdBrinquedos);

Brinquedo *  preencheDadosBrinquedos(Brinquedo * brinquedos, int qtdBrinquedos);

void imprimeBrinquedos(Brinquedo * brinquedos, int qtdBrinquedos);

void imprimeBrinquedoDatabase(Brinquedo * brinquedos, int qtdBrinquedos);

void addBrinquedo(int * qtdBrinquedos, Sessao * sessoes);

int comparaNome(const void * p1, const void * p2);

void ordenaNome(Brinquedo * brinquedos, int qtdBrinquedos);

int comparaId(const void * p1, const void * p2);

void ordenaId(Brinquedo * brinquedos, int qtdBrinquedos);

int buscaBrinquedo(Brinquedo * brinquedos, int qtdBrinquedos, char * nome);

Brinquedo * removeBrinquedo(Brinquedo * brinquedos, int * qtdBrinquedos, int indiceBrinquedo);

Brinquedo * removeBrinquedoSessao(Brinquedo * brinquedos, int qtdBrinquedos, int idDesejado);

void alteraEstoque(Brinquedo * brinquedos, int qtdBrinquedos);

void isNumInt(int * valor);

void isNumFloat(float * valor);

int verificarDados(const char *str);