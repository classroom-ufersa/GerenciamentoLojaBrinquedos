#include <stdio.h>
#include <stdlib.h>

/*Definição de uma estrutura do tipo sessao*/
typedef struct sessao Sessao;

/*Função que inicializa a lista atribuindo NULL
  Retorna: lista inicializada
*/
Sessao * criaListaSessao(void);

/*Função que realiza o preenchimento
dos nós da lista
*/
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

/*Função que realiza a remoção de uma sessão na lista*/
Sessao * removeSessao(Sessao * sessoes, int * qtdSessoes, int idDesejado);
