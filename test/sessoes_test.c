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

struct sessao{
    int id;
    char categoria[25];
    Sessao * prox;
    Sessao * ant;
};

int main(void){
    int qtdSessoes= 0;
    Sessao * sessoes = criaListaSessao();
    sessoes = preencheListaSessoes(sessoes, &qtdSessoes);
    printf("Primeiro. Sessoes: %d\n", qtdSessoes);
    imprimeSessao(sessoes);
    sessoes = adicionaSessao(sessoes, &qtdSessoes);
    printf("Segundo. Sessoes: %d\n", qtdSessoes);
    imprimeSessao(sessoes);
    sessoes = removeSessao(sessoes, &qtdSessoes);
    printf("Remove. Sessoes: %d\n", qtdSessoes);
    imprimeSessao(sessoes);
    free(sessoes);

    return 0;
}
