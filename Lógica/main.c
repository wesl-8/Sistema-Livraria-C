#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "interface.h"

#define max_livro 100

typedef struct
{
    int id;
    char nome[50];
    char editora[50];
    int edicao;
    float valor;
} livraria;

void salvarLivros(livraria L[], int qtde);
void BuscarLivros(livraria L[], char nomes[30], int qtde);
void RelatorioLivros(livraria L[], int qtde);
int CarregarDados(livraria L[], int qtdeM);
void TelaMenu() {
    system("cls");


    textcolor(LIGHT_BLUE);
    Borda(1, 1, 78, 24, 0, 0);


    textcolor(WHITE);
    Borda(20, 3, 40, 2, 1, 0);
    gotoxy(32, 4);
    printf("SISTEMA LIVRARIA");

    Borda(25, 8, 30, 10, 0, 1);

    textcolor(YELLOW);
    gotoxy(28, 10);
     printf("1 - Registrar Livro");
    gotoxy(28, 12);
    printf("2 - Buscar Livro");
    gotoxy(28, 14);
    printf("3 - Relatorio Geral");
    gotoxy(28, 16);
    printf("4 - Salvar e Sair");

    textcolor(LIGHT_GRAY);
    gotoxy(5, 23);
    printf("Status: Sistema Online...");
}

int main()

{
    system("title Sistema de Livraria");
    livraria V[max_livro];
    int L = CarregarDados(V, max_livro);
    int novos=0;
    char nome[50];
    int opcao;


    do
    {
       TelaMenu();

        gotoxy(29, 19);
        textcolor(WHITE);
        printf("Opcao: ");
        scanf("%d", &opcao);

        textcolor(WHITE);
        textbackground(BLACK);


        switch(opcao)
        {
        case 1:
            system("cls");
                Borda(10, 5, 60, 18, 0, 1);
                gotoxy(30, 7); printf("=== NOVO REGISTRO ===");

                gotoxy(15, 10); printf("Quantos livros? ");
                scanf("%d", &novos);

                for(int i = L; i < L + novos; i++)
                    {
                    system("cls");
                    Borda(10, 5, 60, 18, 0, 1);

                    gotoxy(30, 6);
                    printf("LIVRO %d / %d", i+1, L+novos);

                    V[i].id = i + 1;
                    gotoxy(15, 9);
                    printf("ID Gerado: %d", V[i].id);

                    gotoxy(15, 11);
                    printf("Nome.....: ");
                    scanf(" %[^\n]", V[i].nome);

                    gotoxy(15, 13);
                    printf("Editora..: ");
                    scanf(" %[^\n]", V[i].editora);

                    gotoxy(15, 15);
                    printf("Edicao...: ");
                    scanf("%d", &V[i].edicao);

                    gotoxy(15, 17);
                    printf("Valor R$.: ");
                    scanf("%f", &V[i].valor);

                    gotoxy(15, 20);
                    textcolor(GREEN);
                     printf("Sucesso! Pressione ENTER.");
                    getch(); textcolor(WHITE);
                }
                L = L + novos;
                break;

        case 2:
           system("cls");
                Borda(5, 5, 70, 15, 0, 1);
                gotoxy(30, 7);
                printf("=== BUSCA ===");

                if(L == 0) {
                    gotoxy(20, 10);
                    printf("Estoque vazio!");
                } else {
                    gotoxy(10, 10);
                    printf("Nome do livro: ");
                    scanf(" %[^\n]", nome);
             gotoxy(10, 12);
                    BuscarLivros(V, nome, L);
                }
                gotoxy(10, 18); system("pause");
                break;

        case 3:
             system("cls");
             printf("\n");
                textcolor(YELLOW);
                printf("  RELATORIO GERAL DO ESTOQUE\n");
                printf("  --------------------------------------------------\n");
                textcolor(WHITE);

                if(L == 0) printf("  Estoque vazio.\n");
                else RelatorioLivros(V, L);

                printf("\n  "); system("pause");
                break;

        case 4:
           system("cls");
                Borda(20, 10, 40, 5, 0, 1);
                gotoxy(25, 12); printf("Salvando dados...");
                salvarLivros(V, L);
                Sleep(1000);
                break;

        default:
                gotoxy(25, 20);
                textcolor(RED); printf("Opcao Invalida!");
                Sleep(1000); textcolor(WHITE);
                break;
        }


    }while(opcao!= 4);

return 0;
}

void BuscarLivros(livraria L[], char nomes[30], int qtde)
{
  int encontrado=0;

    for(int i=0; i<qtde; i++)
            {
                if(strcmp(L[i].nome, nomes)==0)
                {
                    printf("Livro disponivel no estoque!\n");
                    printf("%d || %s || %s || %d || %.2f\n", L[i].id,
                           L[i].nome,
                           L[i].editora,
                           L[i].edicao,
                           L[i].valor);
                    encontrado=1;
              }
            }

             if(encontrado==0){
                    printf("Livro nao disponivel ou nao existe!\n");

                }

}

void RelatorioLivros(livraria L[], int qtde)
{
    printf("====RELATORIO GERAL DOS LIVROS====\n\n");

    printf("ID  ||  NOME  ||  EDITORA  ||  EDICAO  ||  PRECO \n\n");

    printf("------------------------------------------------------\n");
    for(int i=0; i<qtde; i++)
    {   printf("LIVRO %d", i+1);
        printf("%d || %s || %s || %d || %.2f\n",L[i].id, L[i].nome, L[i].editora, L[i].edicao, L[i].valor);
        printf("\n\n");
    }
    printf("------------------------------------------------------\n");

}

void salvarLivros(livraria L[], int qtde)
{
    FILE*fp;

    fp = fopen("arquivo.txt", "w");

    if(fp==NULL)
    {
        printf("Erro!\n");

    }

    fprintf(fp, "ID  ||  NOME  ||  EDITORA  ||  EDICAO  ||  PRECO \n");

    for(int i=0; i<qtde; i++)
    {

        fprintf(fp,"%d || %s || %s || %d || %.2f\n",L[i].id, L[i].nome, L[i].editora, L[i].edicao, L[i].valor);
        fprintf(fp, "\n");
    }

    fclose(fp);
}

int CarregarDados(livraria L[], int qtdeM)
{
    FILE*fp;
    int i=0;
    char buffer[200];

    fp = fopen("arquivo.txt", "r");

    if(fp==NULL){
        printf("Erro ao abrir arquivo\n");
        return 1;
    }

    fgets(buffer, 200, fp);

    while(i< qtdeM && fscanf(fp, "%d | %[^|] | %[^|] | %f", L[i].id,
           L[i].nome,
            L[i].editora,
             L[i].edicao,
              L[i].valor)==5)
    {
        i++;
    }

    fclose(fp);
     return i;
}
