#include "./headers/menu.h"
#include "./headers/grafo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//gcc -o teste main.c ./sources/grafo.c ./sources/menu.c ./headers/grafo.h ./headers/menu.h
//makefile windows simples
// cmd: mingw32-make
// cmd: exec
int main(int argc, char const *argv[])
{  
    char nomeArquivo[50],nomeArquivoEntrada[50], nomeArquivoSaida[50];
    int n, verticeOrigem, verticeDestino, opcao;
    float peso;
    int ordem,tamanho,verticeV,i,verticeGrau,grau;

    Graph grafo;
    FILE *arquivo = NULL;


    /*
    LEITURA DO ARQUIVO E INICIALIZAÇÃO DO GRAFO E SEU PREENCHIMENTO
    */
    msgEntradaArquivo();
    scanf("%s",nomeArquivo); 
    strcpy(nomeArquivoEntrada,nomeArquivo);
    strcat(nomeArquivoEntrada,".txt");

    arquivo = fopen(nomeArquivoEntrada,"r");

    if(arquivo == NULL){
        printf("ERRO NA ABERTURA DO ARQUIVO! TENDE NOVAMENTE.\n");
    }else{
        fscanf(arquivo,"%d",&n);
        grafo = graphInit(n);
        while (!feof(arquivo))
        {
            fscanf(arquivo,"%d",&verticeOrigem);
            fscanf(arquivo,"%d",&verticeDestino);
            fscanf(arquivo,"%f",&peso);
            graphInsert(grafo,verticeOrigem,verticeDestino,peso);
        }
        fclose(arquivo);
        arquivo = NULL;
    }
    /*
    INTERACAO COM O USUARIO
    */

    printf("Digite o vertice que deseja-se saber seu(s) vizinho(s):");
    scanf("%d",&verticeV);
    int vertovizinhos[n], qtdv = 0;

    printf("Digite o vertice que deseja-se saber o grau(ou valencia):");
    scanf("%d",&verticeGrau);
    /*
    PREENCHIMENTO SAIDA
    */

    ordem = n;
    tamanho = tamanhoGrafo(grafo);
    vizinhosVertice(grafo,verticeV,vertovizinhos,&qtdv);
    grau = grauVertice(grafo,verticeGrau);

    /*
    SAIDA, POSSIBILIDA A ESCOLHA NO TERMINAL OU SOMENTE EM ARQUIVO EXTERNO
    */
    msgMenuSaida();
    do
    {
    scanf("%d",&opcao);
    if(opcao == 1){
        strcpy(nomeArquivoSaida,nomeArquivo);
        strcat(nomeArquivoSaida,"_SAIDA.txt");
        
        arquivo = fopen(nomeArquivoSaida,"w");


        fprintf(arquivo,"Ordem do grafo V(G): %d\n",ordem);
        fprintf(arquivo,"Tamanho do grafo E(G): %d\n",tamanho);
        fprintf(arquivo,"Vizinhos do vertice %d:{ ",verticeV);
        for(i = 0; i < qtdv; i++){
            fprintf(arquivo,"%d ",vertovizinhos[i]);
        }
        fprintf(arquivo,"}\n");
        fprintf(arquivo,"Grau do vertice d(X%d): %d\n",verticeGrau,grau);
    }else if(opcao == 2){
        printf("\n*****************************************************\n\n");
        printf("Ordem do grafo V(G): %d\n",ordem);
        printf("Tamanho do grafo E(G): %d\n",tamanho);
        printf("Vizinhos do vertice %d:{ ",verticeV);
        for(i = 0; i < qtdv; i++){
            printf("%d ",vertovizinhos[i]);
        }
        printf("}\n");
        printf("Grau do vertice d(X%d): %d\n",verticeGrau,grau);
    }else{
        printf("Opcao nao faz parte do sistema. Tente Novamente!\n");
        printf("Escolha uma opcao: ");
    }
    } while (opcao !=1 && opcao != 2);
    

    graphShow(grafo);



 
    //printf("=======================\n");
    //printf("E UMA ARTICULACAO %d ? %d\n",1,articulacaoVertice(grafo,1));
    //printf("=======================\n");
    // printf("E UMA ARTICULACAO %d ? %d\n",2,articulacaoVertice(grafo,2));
    // printf("=======================\n");
    // printf("E UMA ARTICULACAO %d ? %d\n",3,articulacaoVertice(grafo,3));
    // printf("=======================\n");
    // printf("E UMA ARTICULACAO %d ? %d\n",4,articulacaoVertice(grafo,4));
    // printf("=======================\n");
    // printf("E UMA ARTICULACAO %d ? %d\n",5,articulacaoVertice(grafo,5));
    // printf("=======================\n");
    // printf("E UMA ARTICULACAO %d ? %d\n",6,articulacaoVertice(grafo,6));
    // printf("=======================\n");
    // printf("E UMA ARTICULACAO %d ? %d\n",7,articulacaoVertice(grafo,7));
    return 0;
}
