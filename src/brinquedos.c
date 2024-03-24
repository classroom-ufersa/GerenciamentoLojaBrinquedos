#include "../include/brinquedos.h"

struct brinquedo{
    char nome[50];
    int idadeMax;
    int idadeMin;
    float preco;
    int qtdEstoque;
    int idSessao;
};

void contaBrinquedos(int * qtdBrinquedos){
    *qtdBrinquedos = 0;
    int c;
    FILE * dataBase = fopen("../data/database.txt", "r");
    if (dataBase == NULL){
        printf("Nao foi possivel abrir o arquivo\n");
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
        printf("Falha na alocação de memória.\n");
        return NULL;
    }

    return brinquedos; 
}

void preencheDados(Brinquedo * brinquedos, int qtdBrinquedos){
    FILE * dataBase = fopen("../data/database.txt", "r");
    if (dataBase == NULL){
        printf("Nao foi possivel abrir o arquivo\n");
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
        printf("Nao foi possivel abrir o arquivo\n");
        exit(1);
    }
    fprintf(dataBase, "%s\t%d-%d\t%.2f\t%d\t%d\n", aux.nome, aux.idadeMin, aux.idadeMax, aux.preco, aux.qtdEstoque,aux.idSessao);
    fclose(dataBase);
}

int comparaNome(const void * p1, const void * p2){
   const Brinquedo * pa = p1;
   const Brinquedo * pb = p2;
   return strcmp(pa->nome, pb->nome);
}
void ordenaNome(Brinquedo * brinquedos, int qtdBrinquedos){
    qsort(brinquedos, qtdBrinquedos, sizeof(Brinquedo), comparaNome);

    FILE * dataBase = fopen("../data/database.txt", "w");
    if (dataBase == NULL){
        printf("Nao foi possivel abrir o arquivo\n");
        exit(1);
    }
    int count = 0;
    while (count != qtdBrinquedos){
        fprintf(dataBase, "%s\t%d-%d\t%.2f\t%d\t%d\n", brinquedos[count].nome, brinquedos[count].idadeMin, brinquedos[count].idadeMax, brinquedos[count].preco, brinquedos[count].qtdEstoque,brinquedos[count].idSessao);
        count++;
    }
    
    fclose(dataBase);
}

int buscaBrinquedo(Brinquedo * brinquedos, int qtdBrinquedos, char * nome) {
    ordenaNome(brinquedos, qtdBrinquedos);
    int max = qtdBrinquedos - 1;
    int min = 0;
    int meio = 0;
    int verificador = 0;
    while (min <= max && strcmp(brinquedos[meio].nome, nome) != 0 ){
        meio = (min + max)/2;
        int comparacao = strcmp(brinquedos[meio].nome, nome);

        if(comparacao == 0){
            verificador = 1;
            return meio;
        }else if(comparacao > 0){
            max = meio - 1;
        }else{
            min = meio + 1;
        }

        if(!verificador){
            printf("nao encontrado\n");
            return -1;
        }
    }
}

void alteraEstoque(Brinquedo * brinquedos, int qtdBrinquedos){
    char opcao[50];
    printf("ALTERACAO DE ESTOQUE\n");
    printf("digite o nome do brinquedo: ");
    scanf(" %[^\n]", opcao);
    int indice = buscaBrinquedo(brinquedos, qtdBrinquedos, opcao);
    printf("insira a nova quantidade de %s no estoque: ", brinquedos[indice].nome);
    scanf(" %d", &brinquedos[indice].qtdEstoque);

    FILE * dataBase = fopen("../data/database.txt", "w");
    if (dataBase == NULL){
        printf("Nao foi possivel abrir o arquivo\n");
        exit(1);
    }
    int count = 0;
    while (count != qtdBrinquedos){
        fprintf(dataBase, "%s\t%d-%d\t%.2f\t%d\t%d\n", brinquedos[count].nome, brinquedos[count].idadeMin, brinquedos[count].idadeMax, brinquedos[count].preco, brinquedos[count].qtdEstoque,brinquedos[count].idSessao);
        count++;
    }
    fclose(dataBase);
    printf("Estoque alterado!\n");
}