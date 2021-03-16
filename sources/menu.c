#include "../headers/grafo.h"
#include "../headers/menu.h"
#include <stdio.h>
#include <stdlib.h>


//Main Menu
// void menuPrincipal(){
//     printf("\n");
//     pritnf("**************************************\n");
//     printf("*           MENU PRINCIPAL           *\n");
//     pritnf("**************************************\n");
//     printf("*  1: Ordem do grafo                *\n");
//     printf("*  2: Tamanho do grafo              *\n");
//     printf("*  3: Vizinhos                      *\n");
//     printf("*  4: Tamanho do grafo              *\n");
//     printf("*  5: Tamanho do grafo              *\n");
//     printf("*  6: Tamanho do grafo              *\n");
//     printf("*  7: Tamanho do grafo              *\n");
//     printf("*  8: Tamanho do grafo              *\n");

// }
/*
    int n = 5;
    Graph grafo;
    int verticeOrigem = 1;
    int verticeDestino = 2;
    float peso = 1.2;
*/
// void readFile(int *n, int *verticeOrigem, int *verticeDestino, float *peso){
    // char nomeArquivo[50];
    // FILE *arquivo;

    // printf("Digite o nome do arquivo: ");
    // scanf("%s",nomeArquivo);

    // strcat(nomeArquivo,".txt");

    // arquivo = fopen(nomeArquivo,"r");

    // if(arquivo == NULL){
    //     printf("Erro na abertura do arquivo\n");
    // }else{
    //     fscanf(arquivo,"%d",n);
    //     printf("%d\n",*(n));
    //     while (!feof(arquivo)){   
    //         fscanf(arquivo,"%d",verticeOrigem);
    //         fscanf(arquivo,"%d",verticeDestino);
    //         fscanf(arquivo,"%f",peso);
    //         printf("%d %d %f\n",*(verticeOrigem),*(verticeDestino),*(peso));
    //     }
    //     fclose(arquivo);
    // }

// }