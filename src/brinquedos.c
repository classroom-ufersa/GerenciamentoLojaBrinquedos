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

void contaBrinquedos(int * qtdBrinquedos){
    *qtdBrinquedos = 0;
    int c;
    FILE * dataBase = fopen("../data/database.txt", "r");
    if (dataBase == NULL){
        printf("### Nao foi possivel abrir o arquivo! ###\n");
        exit(1);
    }

    while((c = fgetc(dataBase)) != EOF){
        if (c == '\n'){
            ++(*qtdBrinquedos);
        }
    }
    fclose(dataBase);
}

Brinquedo * criaLista(int * qtdBrinquedos){
    contaBrinquedos(qtdBrinquedos);
    Brinquedo * brinquedos = (Brinquedo*) malloc((*qtdBrinquedos) * sizeof(Brinquedo));  
    if(brinquedos == NULL){
        printf("### Falha na alocacao de memoria! ###\n");
        return NULL;
    }
    
    return brinquedos; 
}

Brinquedo * preencheDadosBrinquedos(Brinquedo * brinquedos, int qtdBrinquedos){
    FILE * dataBase = fopen("../data/database.txt", "r");
    if (dataBase == NULL){
        printf("### Nao foi possivel abrir o arquivo! ###\n");
        exit(1);
    }
    int i = 0;
     while(i < qtdBrinquedos){
        fscanf(dataBase, " %[^\t]\t%d-%d anos\t%f\t%d\t%d\n", brinquedos[i].nome, &brinquedos[i].idadeMin, &brinquedos[i].idadeMax, &brinquedos[i].preco, &brinquedos[i].qtdEstoque, &brinquedos[i].idSessao);
        i++;
    }
    fclose(dataBase);
    return brinquedos;
}

void imprimeBrinquedos(Brinquedo * brinquedos, int qtdBrinquedos){
    if(qtdBrinquedos == 0){
        printf("Nao ha brinquedos cadastrados!\n");
    }else{
        printf("NOME    FAIXA           PRECO  ESTOQUE SESSAO\n");
        for (int i = 0; i < qtdBrinquedos; i++){
            printf("%s\t%d-%d anos\t%.2f\t%d\t%d\n", brinquedos[i].nome, brinquedos[i].idadeMin, brinquedos[i].idadeMax, brinquedos[i].preco, brinquedos[i].qtdEstoque, brinquedos[i].idSessao);
        }
    }
}

void imprimeBrinquedoDatabase(Brinquedo * brinquedos, int qtdBrinquedos){
    FILE * dataBase = fopen("../data/database.txt", "w");
    if (dataBase == NULL){
        printf("### Nao foi possivel abrir o arquivo! ###\n");
        exit(1);
    }
    int count = 0;
    while (count != qtdBrinquedos){
        fprintf(dataBase, "%s\t%d-%d anos\t%.2f\t%d\t%d\n", brinquedos[count].nome, brinquedos[count].idadeMin, brinquedos[count].idadeMax, brinquedos[count].preco, brinquedos[count].qtdEstoque,brinquedos[count].idSessao);
        count++;
    }
    
    fclose(dataBase);
}

void addBrinquedo(int * qtdBrinquedos, Sessao * sessoes){//falta checar se a sessao existe, e listar as qie existe
    Brinquedo aux;
    printf("--- CADATRO DE BRINQUEDO ---\n");
    printf("Digite o nome: ");
    scanf(" %[^\n]", aux.nome);
    printf("Digite a faixa etaria: \n");
    printf("idade minima: ");
    isNumInt(&aux.idadeMin);
    printf("idade maxima: ");
    isNumInt(&aux.idadeMax);
    printf("Digite o valor: ");
    isNumFloat(&aux.preco);
    printf("Digite a quantidade em estoque: ");
    isNumInt(&aux.qtdEstoque);
    printf("Digite a qual sessao ele pertence: ");
    isNumInt(&aux.idSessao);
    ++(*qtdBrinquedos);
    FILE * dataBase = fopen("../data/database.txt", "a");
    if (dataBase == NULL){
        printf("### Nao foi possivel abrir o arquivo! ###\n");
        exit(1);
    }
    fprintf(dataBase, "%s\t%d-%d anos\t%.2f\t%d\t%d\n", aux.nome, aux.idadeMin, aux.idadeMax, aux.preco, aux.qtdEstoque,aux.idSessao);
    fclose(dataBase);
}

int comparaNome(const void * p1, const void * p2){
   const Brinquedo * pa = p1;
   const Brinquedo * pb = p2;
   return strcmp(pa->nome, pb->nome);
}
void ordenaNome(Brinquedo * brinquedos, int qtdBrinquedos){
    qsort(brinquedos, qtdBrinquedos, sizeof(Brinquedo), comparaNome);

    imprimeBrinquedoDatabase(brinquedos, qtdBrinquedos);
}

int comparaId(const void * p1, const void * p2){
   const Brinquedo * pa = p1;
   const Brinquedo * pb = p2;
   return pa->idSessao - pb->idSessao;
}
void ordenaId(Brinquedo * brinquedos, int qtdBrinquedos){
    qsort(brinquedos, qtdBrinquedos, sizeof(Brinquedo), comparaId);

    imprimeBrinquedoDatabase(brinquedos, qtdBrinquedos);
}

int buscaBrinquedo(Brinquedo * brinquedos, int qtdBrinquedos, char * nome) {
    ordenaNome(brinquedos, qtdBrinquedos);
    int max = qtdBrinquedos - 1;
    int min = 0;
    int meio;
    while (min <= max){
        meio = (min + max)/2;
        int comparacao = strcmp(brinquedos[meio].nome, nome);

        if(comparacao == 0){
            return meio;
        }else if(comparacao > 0){
            max = meio - 1;
        }else{
            min = meio + 1;
        }
    }
    printf("### Brinquedo nao encontrado ###\nDigite um brinquedo valido: ");
    return qtdBrinquedos;
}

Brinquedo * removeBrinquedo(Brinquedo * brinquedos, int * qtdBrinquedos, int indiceBrinquedo){
    int i;
    for(i = indiceBrinquedo; i < (*qtdBrinquedos) - 1; i++){
        brinquedos[i] = brinquedos[i+1];
    }
    --(*qtdBrinquedos);
    
    brinquedos = realloc(brinquedos, (*qtdBrinquedos) * sizeof(Brinquedo));
    imprimeBrinquedoDatabase(brinquedos, (*qtdBrinquedos));
    return brinquedos;
}

Brinquedo * removeBrinquedoSessao(Brinquedo * brinquedos, int qtdBrinquedos, int idDesejado){
    ordenaId(brinquedos, qtdBrinquedos);
    int i =0;
    int inicio= 0;
    
    for(i = 0; i < qtdBrinquedos; i++){
        if (brinquedos[i].idSessao == idDesejado){
            inicio = i;
            break;
        }
    }

    while (brinquedos[inicio].idSessao == idDesejado){
        brinquedos = removeBrinquedo(brinquedos, &qtdBrinquedos, inicio);
    }

    for (i = 0; i < qtdBrinquedos; i++){
        if (brinquedos[i].idSessao >= idDesejado){
            --(brinquedos[i].idSessao);
        }
    }
    imprimeBrinquedoDatabase(brinquedos, qtdBrinquedos);

}

void alteraEstoque(Brinquedo * brinquedos, int qtdBrinquedos){
    char opcao[50];
    int indice;
    printf("\n--- ALTERACAO DE ESTOQUE--- \n");
    printf("Brinquedos disponiveis: \n");
    imprimeBrinquedos(brinquedos, qtdBrinquedos);
    printf("Digite o nome do brinquedo: ");
    do{
        scanf(" %[^\n]", opcao);
        indice = buscaBrinquedo(brinquedos, qtdBrinquedos, opcao);
    }while (indice >= qtdBrinquedos);

    printf("Insira a nova quantidade de %s no estoque: ", brinquedos[indice].nome);
    isNumInt(&brinquedos[indice].qtdEstoque);

    imprimeBrinquedoDatabase(brinquedos, qtdBrinquedos);
    printf("Estoque alterado!\n");
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

