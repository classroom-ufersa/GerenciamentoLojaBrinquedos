#include "../include/sessao.h"
#include "../include/brinquedos.h"

struct sessao{
    int id; //info
    char categoria[25]; //info
    Sessao * prox;
    Sessao * ant;
};
struct brinquedo{
    char nome[50];
    int idadeMax;
    int idadeMin;
    float preco;
    int qtdEstoque;
    int idSessao;
    char categoriaSessao[25];
};

void criaLista(void){
    return NULL;
}

Sessao * preencheNo(Sessao * l, Brinquedo * brinquedo){
    Sessao *novo = (Sessao*) malloc(sizeof(Sessao));
    novo->prox = l;
    novo->ant = NULL;
    l->ant = novo;
    novo->id = brinquedo->idSessao;
    strcpy(novo->categoria, brinquedo->categoriaSessao);
    
    return novo;
}

void escolheSessao(Sessao * l){
    printf("As seguintes sessões estão cadastradas:");
    Sessao* p;
    for(p = l; p!= NULL; p = p->prox){
        printf("Dados: %d%s\n", p->id, p->categoria);
    }
}

void imprimeSessao(Brinquedo * brinquedos, int sessaoDesejada, int qtdBrinquedos){
    int i;
    for(i=0; i<sessaoDesejada; i++){
        if(sessaoDesejada == brinquedos[i].idSessao){
            printf("%s\t%d-%d\t%.2f\t%d\t%d\n", brinquedos[i].nome, brinquedos[i].idadeMin, brinquedos[i].idadeMax, brinquedos[i].preco, brinquedos[i].qtdEstoque, brinquedos[i].idSessao);
        }
    }

}

