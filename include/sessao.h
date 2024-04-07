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


void imprimeDatabase(Sessao * sessoes){
    Sessao* contador = sessoes->ant;
    FILE * dataBase = fopen("../data/sessao.txt", "w");
    if (dataBase == NULL){
        printf("### Nao foi possivel abrir o arquivo! ###\n");
        exit(1);
    }
    
    do {
        fprintf(dataBase, "%d\t%s\n", contador->id, contador->categoria);
        contador = contador->ant;
    } while(contador != sessoes->ant);
    fclose(dataBase);
}

Sessao * adicionaSessao(Sessao * sessoes, int * qtdSessoes){
    Sessao * aux = (Sessao*) malloc(sizeof(Sessao));
    printf("Insira o nome da sessão: ");
    scanf( "%[^\n]", aux->categoria);
    aux->id = sessoes->id + 1;
    sessoes = preencheNo(sessoes, aux);
    ++(*qtdSessoes);
    free(aux);
    imprimeDatabase(sessoes);
    return sessoes;
}

Sessao * removeSessao(Sessao * sessoes, int * qtdSessoes){
    int idDesejado = 0;
    printf("digite o id que deseja remover: ");
    scanf("%d", &idDesejado);
    Sessao* contador = sessoes;
    do {
        if(contador->id == idDesejado){
            Sessao* proximo = contador->prox;
            if(contador->ant != NULL) {
                contador->ant->prox = contador->prox;
            }
            if(contador->prox != NULL) {
                contador->prox->ant = contador->ant;
            }
            if(contador == sessoes) {
                sessoes = sessoes->prox;
            }
            Sessao* anterior = contador->ant;
            free(contador);
            --(*qtdSessoes);
            contador = anterior;
            while(contador != sessoes->ant){
                --(contador->id );
                contador = contador->ant;
            }
            imprimeDatabase(sessoes);
            return sessoes;
        }
        contador = contador->prox;
    } while(contador != sessoes);
    imprimeDatabase(sessoes);
    return sessoes;
}