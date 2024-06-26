#include "../include/sessao.h"

struct sessao{
    int id;
    char categoria[25];
    Sessao * prox;
    Sessao * ant;
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
    printf("--- CADASTRO DE SESSAO ---\n");
    Sessao * aux = (Sessao*) malloc(sizeof(Sessao));
    printf("Insira o nome da sessao: ");
    scanf(" %[^\n]", aux->categoria);
    stringMinuscula(aux->categoria);
    aux->id = sessoes->id + 1;
    sessoes = preencheNo(sessoes, aux);
    ++(*qtdSessoes);
    free(aux);
    imprimeDatabase(sessoes);
    printf("Sessão cadastrada com sucesso!\n");
    return sessoes;
}


Sessao * procuraSessao(int idSessao,Sessao * sessoes){
    Sessao* contador = sessoes;
    do {
        if(contador->id == idSessao){
            return contador;
        }
        contador = contador->prox;
    } while(contador != sessoes);

    return 0;
}

Sessao * removeSessao(Sessao * sessoes, int * qtdSessoes, int sessaoDesejada){
    Sessao* contador = procuraSessao(sessaoDesejada, sessoes);
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
            Sessao * contadorNovo = anterior;
            if (contadorNovo == NULL) {
                contadorNovo = sessoes->ant;
            }

            while(contadorNovo != sessoes->ant){
                --(contadorNovo->id );
                contadorNovo = contadorNovo->ant;
            }
            imprimeDatabase(sessoes);
            return sessoes; 
}

void isNumInt(int * valor){
    char str[20];
    int validador;

    do {
        scanf(" %[^\n]", str);
        validador = verificarDados(str);
        while (getchar() != '\n');
        if(validador){
            printf("Entrada invalida. Por favor, insira um numero inteiro: ");
        }
    } while(validador);

    *valor = atoi(str);
}

void isNumFloat(float * valor){
    char str[20];
    int validador;
    char *endptr;

    do {
        scanf(" %[^\n]", str);
        validador = verificarDados(str);
        while (getchar() != '\n');
        if(validador){
            printf("Entrada invalida. Por favor, insira um numero flutuante: ");
        }
    } while(validador);

    *valor = strtof(str, &endptr);
}

int verificarDados(const char *str){
    for(int i = 0; str[i] != '\0'; i++){
        if(!isdigit(str[i]) && str[i] != '\n' && str[i] != '.'){
            return 1;
        }
    }
}

void limpaTela(void){
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void stringMinuscula(char *Nome){ 
  int Contador; 
  for (Contador = 0; Nome[Contador] != '\0'; Contador++)  { 
    Nome[Contador] = tolower(Nome[Contador]); 
  }
}
