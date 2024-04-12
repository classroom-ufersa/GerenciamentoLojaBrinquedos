#include "sessao.h"

/*Definição de uma estrutura do tipo brinquedo*/
typedef struct brinquedo Brinquedo;

/*Função que realiza a contagem da quantidade de brinquedos cadastrados*/
void contaBrinquedos(int * qtdBrinquedos);

/*Função que cria um array vazio de brinquedos*/
Brinquedo * criaLista(int * qtdBrinquedos);

/*Função que preenche os brinquedos dentro do array*/
Brinquedo *  preencheDadosBrinquedos(Brinquedo * brinquedos, int qtdBrinquedos);

/*Função que imprime os brinquedos cadastrados*/
void imprimeBrinquedos(Brinquedo * brinquedos, int qtdBrinquedos);

/*Função que escreve as informações dos briquedos no arquivo*/
void imprimeBrinquedoDatabase(Brinquedo * brinquedos, int qtdBrinquedos);

/*Função que insere novos brinquedos*/
Brinquedo * addBrinquedo(int * qtdBrinquedos,Brinquedo * brinquedos, int qtdSessao, Sessao * sessoes);

/*Função que realiza a comparação dos nomes*/
int comparaNome(const void * p1, const void * p2);

/*Função que realiza a ordenação dos nomes por ordem alfabética*/
void ordenaNome(Brinquedo * brinquedos, int qtdBrinquedos);

/*Função que realiza a comparação dos id's*/
int comparaId(const void * p1, const void * p2);

/*Função que realiza a ordanação dos id's por ordem crescente*/
void ordenaId(Brinquedo * brinquedos, int qtdBrinquedos);

/*Função que realiza a busca de um brinquedo pelo nome*/
int buscaBrinquedo(Brinquedo * brinquedos, int qtdBrinquedos, char * nome);

/*Função que realiza a remoção dos brinquedos*/
Brinquedo * removeBrinquedo(Brinquedo * brinquedos, int * qtdBrinquedos, int indiceBrinquedo);

/*Função que remove os brinquedos de uma sessão*/
Brinquedo * removeBrinquedoSessao(Brinquedo * brinquedos, int qtdBrinquedos, int idDesejado);

/*Função que realiza alteração no estoque dos brinquedos*/
void alteraEstoque(Brinquedo * brinquedos, int qtdBrinquedos);