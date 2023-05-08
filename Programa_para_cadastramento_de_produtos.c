//Testando atualização de repositório
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int codigo;
    char nome[50];
    float preco;

} Produto;

Produto vetorDeProdutos[9];

int funcaoIntermediaria(int opcao, Produto vetorDeProdutos[]);
int funcaoDeCadastro(Produto vetorDeProdutos[]);
int funcaoDeBusca(Produto vetorDeProdutos[]);

int code = 0;

int main() 
{
    int opcao;
    
    while (1) 
    {
        printf("\n      >>>>> Menu <<<<<\n\n");
        printf("1. Cadastrar novo produto.\n");
        printf("2. Buscar produtos.\n");
        printf("0. Sair\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 0)
        {
            printf("\nSaindo...\n");
            break;
        }

        funcaoIntermediaria(opcao, vetorDeProdutos);
    }

    return 0;
}

int funcaoIntermediaria(int opcao, Produto vetorDeProdutos[])
{
    switch (opcao) 
    {
        case 1:
            printf("\n>>> Bem-vindo ao ambiente de cadastro de produtos <<<\n");
            funcaoDeCadastro(vetorDeProdutos);
            break;
        case 2:
            printf("\n>>> Bem-vindo ao ambiente de busca de produtos <<<\n");
            funcaoDeBusca(vetorDeProdutos);
            break;
        default:
            printf("\n>>> Opcao invalida. Por favor, escolha novamente <<<\n");
    }

    return 0;
}

int funcaoDeCadastro(Produto vetorDeProdutos[])
{
    if (code >= 10) 
    {
        printf("\n>>> Limite de produtos atingido <<<\n");
        
        return 0;
    }

    Produto novoProduto;

    printf("\nDigite o codigo do produto: ");
    scanf("%d", &novoProduto.codigo);

    for (int i = 0; i < code; i++) 
    {
        if (vetorDeProdutos[i].codigo == novoProduto.codigo) 
        {
            printf("\n\n >>>>> Esse codigo ja foi cadastrado no sistema. Tente outro <<<<< \n\n");

            return 0;
        }
    }

    printf("\nDigite o nome do produto: ");
    scanf("%s", novoProduto.nome);

    printf("\nDigite o preco do produto: ");
    scanf("%f", &novoProduto.preco);

    vetorDeProdutos[code] = novoProduto;
    code++;

    printf("\n>>> Produto cadastrado com sucesso <<<\n");

    return 0;
}

int funcaoDeBusca(Produto vetorDeProdutos[])
{
    int codigoBusca;

    printf("\nDigite o codigo do produto que deseja buscar: ");
    scanf("%d", &codigoBusca);

    int i;
    for (i = 0; i < code; i++) 
    {
        if (vetorDeProdutos[i].codigo == codigoBusca) 
        {
            printf("\nProduto encontrado:\n\n");
            printf("Codigo: %d\n", vetorDeProdutos[i].codigo);
            printf("Nome: %s\n", vetorDeProdutos[i].nome);
            printf("Preco: %.2f\n", vetorDeProdutos[i].preco);

            return 0;
        }
    }

    printf("\nProduto nao encontrado.\n");

    return 0;
}