#include <stdio.h>

struct
{
    char nome[50];
    int codigo;
    float preco;

}Produtos[100];

int code = 0;

void funcaoBusca()
{
    int codigoBusca;

    printf("\nInforme o codigo do produto que voce deseja encontrar: ");
    scanf("%d", &codigoBusca);

    for (int i = 0; i < code; i++)
    {
        if (Produtos[i].codigo == codigoBusca)
        {
            printf("\n >>>>> Produto encontrado <<<<< \n\n");
            printf("Nome: %s\n", Produtos[i].nome);
            printf("Codigo: %d\n", Produtos[i].codigo);
            printf("Preco: %.2f\n", Produtos[i].preco);
            printf("\n__________________________________________________\n\n");
        }
        else
        {
            printf("\n\n !!!!! Codigo nao encontrado no sistema !!!!!.\n\n");
        }
    }
}

void funcaoCadastro()
{
    if (code == 100)
    {
        printf("\n\n Estoque completo. Nao e possivel cadastrar esse produto.\n\n");
    }
    else
    {
        printf("\n >>>>> Ambiente de Cadastramento <<<<< \n");
        printf("\nInforme o nome do produto: ");
        scanf(" %49[^\n]", Produtos[code].nome);
        printf("\n");
        printf("Informe o codigo a ser cadastrado: ");
        scanf("%d", &Produtos[code].codigo);
        printf("\n");
        printf("Informe o preco a ser cadastrado: ");
        scanf("%f", &Produtos[code].preco);
        code++;

        printf("\n____________________________________________________\n\n");
    }
    
}

void funcaoIntermediaria(int opcao)
{
    switch (opcao)
    {
    case 1:
        funcaoCadastro();
        break;

    case 2:
        funcaoBusca();
        break;    
    
    default:
        printf("\n\nOpcao invalida. Escolha entre 1 e 3, por favor.\n\n");
        break;
    }
}

int main()
{
    int opcao;

    while (1)
    {
        printf("         | >>>>> MENU <<<<< | \n\n");
        printf("Digite 1 para cadastrar um produto.\n");
        printf("Digite 2 para buscar um produto cadastrado.\n");
        printf("Digite 3 para sair do programa.\n\n");
        printf(" >>>>> Informe a opcao desejada: ");
        scanf("%d", &opcao);
        printf("\n");

        if (opcao == 3)
        {
            printf("Saindo do sistema...\n");
            break;
        }

        funcaoIntermediaria(opcao);

    } 
    return 0;
}