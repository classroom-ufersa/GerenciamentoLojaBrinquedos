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

Sessao * criaListaSessao(void){
    return NULL;
}

Sessao * preencheNo(Sessao * sessoes, Sessao * aux){
    Sessao *novo = (Sessao*) malloc(sizeof(Sessao));
    novo->id = aux->id;
    strcpy(novo->categoria, aux->categoria);

    if(sessoes == NULL) {
        novo->prox = novo;
        novo->ant = novo;
    } else {
        Sessao *ultimoNo = sessoes->ant;

        novo->prox = sessoes;
        sessoes->ant = novo;

        novo->ant = ultimoNo;
        ultimoNo->prox = novo;
    }
    
    return novo;    
}

void contaSessoes(int * qtdSessoes){
    *qtdSessoes = 0;
    int c;
    FILE * dataBase = fopen("../data/sessao.txt", "r");
    if (dataBase == NULL){
        printf("### Nao foi possivel abrir o arquivo! ###\n");
        exit(1);
    }

    while((c = fgetc(dataBase)) != EOF){
        if (c == '\n'){
            ++(*qtdSessoes);
        }
    }
    fclose(dataBase);
}


Sessao * preencheListaSessoes(Sessao * sessoes, int * qtdSessao){
    (*qtdSessao) = 0;
    contaSessoes(qtdSessao);
    int i = 0;
    FILE * dataBase = fopen("../data/sessao.txt", "r");
    if (dataBase == NULL){
        printf("### Nao foi possivel abrir o arquivo! ###\n");
        exit(1);
    }
    for(i = 0; i < (*qtdSessao); i++){
        Sessao * aux  = (Sessao*) malloc(sizeof(Sessao));
        fscanf(dataBase, " %d\t%[^\n]\n", &aux->id, aux->categoria);
        sessoes = preencheNo(sessoes, aux);
        free(aux);
    }
    fclose(dataBase);

    return sessoes;
}


void imprimeSessao(Sessao * sessoes){
    printf("As seguintes sessoes estao cadastradas:\n");
    if(sessoes == NULL){
        printf("A Sessao esta vazia");
    } else {
        Sessao* contador = sessoes->ant;
        do {
            printf("%d\t%s\n", contador->id, contador->categoria);
            contador = contador->ant;
        } while(contador != sessoes->ant);
    }
}