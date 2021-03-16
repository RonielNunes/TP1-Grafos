#include "./headers/menu.h"
#include "./headers/grafo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//gcc -o teste main.c ./sources/grafo.c ./sources/menu.c ./headers/grafo.h ./headers/menu.h
//https://www.geeksforgeeks.org/graph-and-its-representations/
int main(int argc, char const *argv[])
{  
    int n;
    Graph grafo;
    int verticeOrigem;
    int verticeDestino;
    float peso;
    char nomeArquivo[50];
    FILE *arquivo;



    printf("Digite o nome do arquivo: ");
    scanf("%s",nomeArquivo);

    strcat(nomeArquivo,".txt");

    arquivo = fopen(nomeArquivo,"r");

    if(arquivo == NULL){
        printf("Erro na abertura do arquivo\n");
    }else{
        fscanf(arquivo,"%d",&n);

        printf("grafo inicial: \n");
        grafo = graphInit(n);
        graphShow(grafo);
        printf("\n");


        printf("%d\n",n);
        while (!feof(arquivo)){   
            fscanf(arquivo,"%d",&verticeOrigem);
            fscanf(arquivo,"%d",&verticeDestino);
            fscanf(arquivo,"%f",&peso);
            graphInsert(grafo,verticeOrigem,verticeDestino,peso);
            printf("%d %d %.1f\n",verticeOrigem,verticeDestino,peso);
        }
        fclose(arquivo);
    }
    printf("\nGrafo final: \n");
    graphShow(grafo);

    return 0;
}
