#include "../include/brinquedos.h"

struct brinquedo{
    char nome[25];
    int idadeMax;
    int idadeMin;
    float preco;
    int qtdEstoque;
    int idSessao;
};

Brinquedo * contaBrinquedos(int * qtdBrinquedos){
    int c;
    FILE * dataBase = fopen("../data/database.txt", "r");
    if (dataBase == NULL){
        printf("nao foi possivel abrir o arquivo\n");
        exit(1);
    }

    while((c = fgetc(dataBase)) != EOF){
        if (c == '\n'){
            ++(*qtdBrinquedos);
        }
    }
    fclose(dataBase);

    Brinquedo * brinquedos = (Brinquedo*) malloc((*qtdBrinquedos) * sizeof(Brinquedo));  
    if(brinquedos == NULL){
        printf("Falha na alocação de memória.\n");
        return NULL;
    }

    return brinquedos; 
}

void preencheDados(Brinquedo * brinquedos, int qtdBrinquedos){
    FILE * dataBase = fopen("../data/database.txt", "r");
    if (dataBase == NULL){
        printf("nao foi possivel abrir o arquivo\n");
        exit(1);
    }
    int i = 0;
     while(i < qtdBrinquedos){
        fscanf(dataBase, " %[^\t]\t%d-%d\t%f\t%d\t%d\n", brinquedos[i].nome, &brinquedos[i].idadeMin, &brinquedos[i].idadeMax, &brinquedos[i].preco, &brinquedos[i].qtdEstoque, &brinquedos[i].idSessao);
        i++;
    }
    fclose(dataBase);
}

void addBrinquedo(int * qtdBrinquedos){
    Brinquedo aux;
    printf("CADATRO DE BRINQUEDO\n");
    printf("Digite o nome: ");
    scanf(" %[^\n]", aux.nome);
    printf("Digite a faixa etaria (idade minima - idade max): ");
    scanf("%d %d", &aux.idadeMin, &aux.idadeMax);
    printf("Digite o valor: ");
    scanf("%f", &aux.preco);
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &aux.qtdEstoque);
    printf("Digite a qual sessao ele pertence: ");
    scanf("%d", &aux.idSessao);
    ++(*qtdBrinquedos);
    FILE * dataBase = fopen("../data/database.txt", "a");
    if (dataBase == NULL){
        printf("nao foi possivel abrir o arquivo\n");
        exit(1);
    }
    fprintf(dataBase, "%s\t%d-%d\t%.2f\t%d\t%d\n", aux.nome, aux.idadeMin, aux.idadeMax, aux.preco, aux.qtdEstoque,aux.idSessao);
    fclose(dataBase);
}