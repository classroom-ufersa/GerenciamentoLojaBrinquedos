#include "../include/brinquedos.h"
#include "../include/sessao.h"

int main(void){
    int op = 0;
    int qtdBrinquedos = 0;
    int qtdSessoes = 0;
    Brinquedo * brinquedos = criaLista(&qtdBrinquedos);
    Sessao * sessoes = criaListaSessao();
    sessoes = preencheListaSessoes(sessoes, &qtdSessoes);
    brinquedos = preencheDadosBrinquedos(brinquedos, qtdBrinquedos);
    
    printf("---- BEM VINDO(A) AO SISTEMA DE GERENCIAMENTO DE BRINQUEDO ---\n");

    do{
        printf("\n______ M E N U ______\n");
        printf("1 - Listar brinquedos\n");
        printf("2 - Adicionar Brinquedo\n");
        printf("3 - Remover brinquedo por nome\n");
        printf("4 - Editar estoque de brinquedo\n");
        printf("5 - Listar sessoes\n");
        printf("6 - Adicionar sessao\n");
        printf("7 - Remover sessao\n");
        printf("8 - sair\n");
        printf("> ");
        isNumInt(&op);

        switch(op){
        case 1:
            limpaTela();
            imprimeBrinquedos(brinquedos, qtdBrinquedos);
            break;
        case 2:
            limpaTela();
            imprimeSessao(sessoes);
            brinquedos = addBrinquedo(&qtdBrinquedos, brinquedos, qtdSessoes);
            preencheDadosBrinquedos(brinquedos, qtdBrinquedos);
            ordenaNome(brinquedos, qtdBrinquedos);
            break;
        case 3:
            limpaTela();
            char opcao[50];
            int indice = 0;
            ordenaNome(brinquedos, qtdBrinquedos);
            printf("\n--- REMOCAO DE BRINQUEDO --- \n");
            imprimeBrinquedos(brinquedos, qtdBrinquedos);
            printf("Digite o nome do brinquedo: ");
            do{
                scanf(" %[^\n]", opcao);
                stringMinuscula(opcao);
                indice = buscaBrinquedo(brinquedos, qtdBrinquedos, opcao);
            }while (indice >= qtdBrinquedos);

            brinquedos = removeBrinquedo(brinquedos, &qtdBrinquedos, indice); 
            printf("brinquedo removido\n");
            break;
        case 4:
            limpaTela();
            alteraEstoque(brinquedos, qtdBrinquedos);
            break;
        case 5:
            limpaTela();
            imprimeSessao(sessoes);
            break;
        case 6:
            limpaTela();
            sessoes = adicionaSessao(sessoes, &qtdSessoes);
            break;
        case 7:
            limpaTela();
            int idDesejado=0;
            imprimeSessao(sessoes);
            printf("Digite o id que deseja remover: ");
            do{
             isNumInt(&idDesejado);
            if(idDesejado > qtdSessoes || idDesejado <= 0){
            printf("Selecione uma sessao existente:\n");
        }
         }while(idDesejado > qtdSessoes || idDesejado <= 0 );
            sessoes = removeSessao(sessoes, &qtdSessoes, idDesejado);
            brinquedos = removeBrinquedoSessao(brinquedos, qtdBrinquedos, idDesejado);
            break;
        case 8: 
            limpaTela();
            printf("saindo...");
            exit(1);
        default:
            printf("esta nao e uma opcao valida. Digite uma opcao: ");
            isNumInt(&op);
            break;
        }
    } while(op != 8);

    return 0;
}