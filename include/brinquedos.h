#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
Brinquedo * addBrinquedo(int * qtdBrinquedos, Brinquedo * brinquedos, int qtdSessao);

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

/*Função que analisa se a informação inserida é um número inteiro*/
void isNumInt(int * valor);

/*Função que analisa se a informação inserida é um float */
void isNumFloat(float * valor);

/*Função que verifica se há letras na informação inserida*/
int verificarDados(const char *str);

/*Função que limpa a tela*/
void limpaTela(void);

/*Função que realiza a tratativa de forma que todos os dados inseridos
estejam formatados com letra minúscula
*/
void stringMinuscula(char *Nome);