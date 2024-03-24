#include "../include/brinquedos.h"
#include "../include/sessao.h"

struct brinquedo{
    char nome[50];
    int idadeMax;
    int idadeMin;
    float preco;
    int qtdEstoque;
    int idSessao;
};

int main(void){
    int qtdBrinquedos = 0;

    Brinquedo * brinquedos = criaLista(&qtdBrinquedos);
    if (brinquedos == NULL){
        printf("### Falha na alocacao de memoria. ### \n");
        exit(1);
    }
    preencheDados(brinquedos, qtdBrinquedos);
    printf("\n-- Primeiro: %d brinquedos\n", qtdBrinquedos);
    for (int i = 0; i < qtdBrinquedos; i++){
        printf("%s\t%d-%d\t%.2f\t%d\t%d\n", brinquedos[i].nome, brinquedos[i].idadeMin, brinquedos[i].idadeMax, brinquedos[i].preco, brinquedos[i].qtdEstoque, brinquedos[i].idSessao);
    }
    
    addBrinquedo(&qtdBrinquedos);
    contaBrinquedos(&qtdBrinquedos);

    brinquedos = realloc(brinquedos, qtdBrinquedos * sizeof(Brinquedo));
    if (brinquedos == NULL){
        printf("### Falha na alocacao de memoria. ###\n");
        exit(1);
    }
    preencheDados(brinquedos, qtdBrinquedos);
    printf("\n-- Segundo: %d brinquedos\n", qtdBrinquedos);
    for (int i = 0; i < qtdBrinquedos; i++){
        printf("%s\t%d-%d\t%.2f\t%d\t%d\n", brinquedos[i].nome, brinquedos[i].idadeMin, brinquedos[i].idadeMax, brinquedos[i].preco, brinquedos[i].qtdEstoque, brinquedos[i].idSessao);
    }
    
   ordenaNome(brinquedos, qtdBrinquedos);
    printf("\n-- Ordenados: %d brinquedos\n", qtdBrinquedos);
    for (int i = 0; i < qtdBrinquedos; i++){
        printf("%s\t%d-%d\t%.2f\t%d\t%d\n", brinquedos[i].nome, brinquedos[i].idadeMin, brinquedos[i].idadeMax, brinquedos[i].preco, brinquedos[i].qtdEstoque, brinquedos[i].idSessao);
    }

    alteraEstoque(brinquedos, qtdBrinquedos);
    
    printf("\n-- Estoque alterado: %d brinquedos\n", qtdBrinquedos);
    for (int i = 0; i < qtdBrinquedos; i++){
        printf("%s\t%d-%d\t%.2f\t%d\t%d\n", brinquedos[i].nome, brinquedos[i].idadeMin, brinquedos[i].idadeMax, brinquedos[i].preco, brinquedos[i].qtdEstoque, brinquedos[i].idSessao);
    }
    free(brinquedos);
    return 0;
}