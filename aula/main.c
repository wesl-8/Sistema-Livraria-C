#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_produts 100
typedef struct
{
    int id;
    char nome[30];
    float preco;
    int qtde;
}Produtos;

void imprimirP(Produtos listaP[], int qtd);
void BuscarID(Produtos listaP[], int qtd, int id);
void SalvarDados(Produtos listaP[], int qtd);
int CarregarDados(Produtos listaP[], int qtdMax);





int main()
{
  Produtos P[MAX_produts];
 int N;
 int ID;
 int novos = 0;
 int opcao=0;

 N = CarregarDados(P, MAX_produts);

 if(N > 0){
    printf("Sucesso! %d produtos carregados com exito.\n", N);
 }else{
 printf("Erro! Nenhum arquivo encontrado\n");
 }
 printf("\n");

 printf("----CONTROLE DE PRODUTOS----\n\n");
 do{

    printf("===MENU===\n");
    printf("1-registrar\n");
    printf("2-Buscar por ID\n");
    printf("3-Relatorio geral\n");
    printf("4-Salvar e Sair\n");
    scanf("%d",&opcao);
    printf("\n");
    system("cls");
    switch(opcao)
    {
    case 1:

printf("Quantos produtos novos seram registrados?(0 para pular): ");
scanf("%d",&novos);

if(N + novos > MAX_produts)
        {
            printf("Erro!\n");
            printf("Limite de estoque atingido\n");
            break;
        }

 for(int i=N; i<N + novos; i++)
 {   printf("___Produto %d___\n\n", i+1);
     printf("Digite o id: ");
     scanf("%d",&P[i].id);
     printf("Digite o nome do produto: ");
     scanf(" %[^\n]",P[i].nome);
     printf("Digite o preco: ");
     scanf("%f",&P[i].preco);
     printf("Digite a quantidade disponivel deste produto: ");
     scanf("%d",&P[i].qtde);
     printf("\n\n\n");
 }
 N = N + novos;
break;

    case 2:
        if(N==0)
        {
            printf("Estoque vazio! Cadastre algo primeiro!\n");
        }else{
            printf("Digite o ID do produto desejado: ");
    scanf("%d",&ID);
    BuscarID(P, N, ID);
        }
        system("pause");
        break;

    case 3:
  if(N>0){
printf("|======RELATORIO======|\n");
imprimirP(P, N);
  }else{
      printf("Estoque vazio!\n");
  }
    system("pause");
break;

    case 4:
        printf("Salvando dados.....\n");
        SalvarDados(P, N);
        break;

    default:
        printf("Opcao invalida!\n");
        break;
 }




}while(opcao != 4);

return 0;
}


void imprimirP(Produtos listaP[], int qtd)
{
    float valorT = 0;
    for(int i=0; i<qtd; i++)
    {
     valorT =  listaP[i].preco *listaP[i].qtde;

     printf("ID: %d || NOME: %s || PRECO: %.2f || Total: %.2f\n",listaP[i].id, listaP[i].nome, listaP[i].preco, valorT);
     printf("\n\n");



    }

}

void BuscarID(Produtos listaP[], int qtd, int id)
{
int encontrado = 0;

    for(int i=0; i<qtd; i++)
    {
        if(listaP[i].id == id)
        {
            printf("Produto encontrado: \n\n");
            printf("ID: %d || NOME: %s || PRECO: %.2f\n",listaP[i].id, listaP[i].nome, listaP[i].preco);
            encontrado = 1;
            break;
        }


    }
    if(encontrado==0)
            {
        printf("\nProduto nao encontrado!\n O ID %d não existe no sistema\n", id);
            }
}


void SalvarDados(Produtos listaP[], int qtd)
{
    FILE * fp;

    fp = fopen("arquivo.txt", "w");

    if(fp == NULL){
        printf("Erro!\n");
        return;
    }
    fprintf(fp, "===Lista de produtos===\n");
    fprintf(fp," ID | NOME | PRECO | QUANTIDADE\n");

    for(int i=0; i<qtd; i++)
    {
        fprintf(fp, "%d | %s | %.2f | %d\n", listaP[i].id, listaP[i].nome, listaP[i].preco, listaP[i].qtde);
    }

    fclose(fp);

    printf("Dados arquivados!\n\n");
}

int CarregarDados(Produtos listaP[], int qtdMax)
{
    FILE*fp;
    fp = fopen("arquivo.txt", "r");

    if(fp == NULL){
        return 0;
    }

    int i = 0;
    char buffer[200];

    fgets(buffer, 200, fp);
    fgets(buffer, 200, fp);


    while(i < qtdMax && fscanf(fp, "%d | %[^|] | %f | %d\n",
          &listaP[i].id,
          listaP[i].nome,
          &listaP[i].preco,
          &listaP[i].qtde) == 4)
    {
        i++;
    }

    fclose(fp);
    return i;

}
