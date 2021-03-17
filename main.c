#include "./headers/menu.h"
#include "./headers/grafo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//gcc -o teste main.c ./sources/grafo.c ./sources/menu.c ./headers/grafo.h ./headers/menu.h
//https://www.geeksforgeeks.org/graph-and-its-representations/

int main(int argc, char const *argv[])
{  
    int n,verticeOrigem, verticeDestino;
    Graph grafo;
    float peso;
    char nomeArquivo[50],nomeArquivoSaida[50];
    FILE *arquivo = NULL,*arquivoSaida = NULL;



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

    arquivoSaida = fopen("arquivoSaida.txt","w");

    if (arquivoSaida == NULL){
        printf("Erro na abebertura do arquivo.\n");
    }

    int ordem= n;
    int tamanho = tamanhoGrafo(grafo);
    int vertice = 3;
    int grau = grauVertice(grafo,vertice);
    
    fprintf(arquivoSaida,"Ordem do grafo V(G): %d\n",ordem);
    fprintf(arquivoSaida,"Tamanho do grafo E(G): %d\n",tamanho);
    fprintf(arquivoSaida,"Vizinhos do vertice %d: ",vertice);
    vizinhosVertice(grafo,vertice);
    fprintf(arquivoSaida,"\n");
    fprintf(arquivoSaida,"Grau do vertice d(%d): %d\n",vertice,grau);

    


    return 0;
}
