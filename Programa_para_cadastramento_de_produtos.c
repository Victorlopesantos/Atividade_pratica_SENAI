#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int code;
    char name[50];
    float price;
} Product;

Product productArray[9];

int intermediateFunction(int option, Product productArray[]);
int registrationFunction(Product productArray[]);
int searchFunction(Product productArray[]);

int code = 0;

int main() 
{
    int option;
    
    while (1) 
    {
        printf("\n      >>>>> Menu <<<<<\n\n");
        printf("1. Cadastrar novo produto.\n");
        printf("2. Buscar produtos.\n");
        printf("0. Sair.\n");
        printf("\nEscolha uma opcao: ");
        scanf("%d", &option);

        if (option == 0)
        {
            printf("\nSaindo...\n");
            break;
        }

        intermediateFunction(option, productArray);
    }

    return 0;
}

int intermediateFunction(int option, Product productArray[])
{
    switch (option) 
    {
        case 1:
            printf("\n>>> Bem-vindo ao ambiente de cadastro de produtos <<<\n");
            registrationFunction(productArray);
            break;
        case 2:
            printf("\n>>> Bem-vindo ao ambiente de busca de produtos <<<\n");
            searchFunction(productArray);
            break;
        default:
            printf("\n>>> Opcao invalida. Por favor, escolha novamente <<<\n");
    }

    return 0;
}

int registrationFunction(Product productArray[])
{
    if (code >= 10) 
    {
        printf("\n>>> Limite de produtos atingido <<<\n");
        
        return 0;
    }

    Product newProduct;

    printf("\nDigite o codigo do produto: ");
    scanf("%d", &newProduct.code);

    for (int i = 0; i < code; i++) 
    {
        if (productArray[i].code == newProduct.code) 
        {
            printf("\n\n >>>>> Esse codigo ja foi cadastrado no sistema. Tente outro <<<<< \n\n");

            return 0;
        }
    }

    printf("\nDigite o nome do produto: ");
    scanf("%s", newProduct.name);

    printf("\nDigite o preco do produto: ");
    scanf("%f", &newProduct.price);

    productArray[code] = newProduct;
    code++;

    printf("\n>>> Produto cadastrado com sucesso! <<<\n");

    return 0;
}

int searchFunction(Product productArray[])
{
    int searchCode;

    printf("\nDigite o codigo do produto que deseja buscar: ");
    scanf("%d", &searchCode);

    int i;
    for (i = 0; i < code; i++) 
    {
        if (productArray[i].code == searchCode) 
        {
            printf("\nProduto encontrado:\n\n");
            printf("Codigo: %d\n", productArray[i].code);
            printf("Nome: %s\n", productArray[i].name);
            printf("Preco: %.2f\n", productArray[i].price);

            return 0;
        }
    }

    printf("\nProduto nao encontrado.\n");

    return 0;
}