#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*Definição de uma estrutura do tipo sessao*/
typedef struct sessao Sessao;

/*Função que inicializa a lista atribuindo NULL
  Retorna: lista inicializada
*/
Sessao * criaListaSessao(void);

/*Função que realiza o preenchimento dos nós da lista */
Sessao * preencheNo(Sessao * sessoes, Sessao * aux);

/*Função que realiza a contagem da quantidade de sessões cadastradas*/
void contaSessoes(int * qtdSessoes);

/*Função que escreve as informações das sessões dentro do arquivo */
Sessao * preencheListaSessoes(Sessao * sessoes, int * qtdSessao);

/*Função que imprime as sessões disponíveis*/
void imprimeSessao(Sessao * sessoes);

/*Função que escreve as informações das sessões no arquivo*/
void imprimeDatabase(Sessao * sessoes);

/*Função que adiciona uma nova sessão na lista*/
Sessao * adicionaSessao(Sessao * sessoes, int * qtdSessoes);

/*funcção que procura uma sessao na lista*/
Sessao * procuraSessao(int idSessao, Sessao * sessoes);

/*Função que realiza a remoção de uma sessão na lista*/
Sessao * removeSessao(Sessao * sessoes, int * qtdSessoes, int idDesejado);

/*Função que analisa se a informação inserida é um número inteiro*/
void isNumInt(int * valor);

/*Função que analisa se a informação inserida é um float */
void isNumFloat(float * valor);

/*Função que verifica se há letras na informação inserida*/
int verificarDados(const char *str);

/*Função que limpa a tela*/
void limpaTela(void);

/*Função que realiza a tratativa de forma que todos os dados inseridos estejam formatados com letra minúscula*/
void stringMinuscula(char *Nome);
