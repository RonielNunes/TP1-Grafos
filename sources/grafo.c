#include "../headers/grafo.h"
#include "../headers/menu.h"

#include <stdio.h>
#include <stdlib.h>

//Iniciar grafo;
Graph graphInit(int n){
    Graph grafo = malloc(sizeof *grafo);
    n++;
    grafo->n = n;
    grafo->m = 0;
    grafo->Apontador= malloc(n*sizeof(link));

    for (int i = 0; i < n; i++)
        grafo->Apontador[i] = NULL;
    
    return grafo;
}
//Função graphInsert faz a inserção de um vertice de origem e um destino com seu determinado peso
void graphInsert(Graph grafo, int v, int destino, float peso){
    link p;
    for (p = grafo->Apontador[v]; p != NULL; p = p->nextDestino){
        if (p->verticeDestino == destino)
            return;
    }
    p = malloc(sizeof(struct node));
    p->verticeDestino = destino;
    p->peso = peso;

    p->nextDestino = grafo->Apontador[v];
    grafo->Apontador[v] = p;
    grafo->m++;
}

//Motrar grafo
void graphShow(Graph grafo){
    link p;
    printf("\n");
    for(int i = 0; i < grafo->n; i++){
        printf("%d: ",i);
        for (p = grafo->Apontador[i]; p != NULL; p = p->nextDestino){
            printf("->([%.2f | %d])",p->peso,p->verticeDestino);
        }
        printf("->NULL\n");
    }
    
}

//Retorna o tamanho do grafo, ou seja a quantidade de arestas.
int tamanhoGrafo(Graph grafo){
    link aux;
    int tamanho = 0;
    for (int i = 0; i < grafo->n; i++){
        for (aux = grafo->Apontador[i]; aux != NULL; aux = aux->nextDestino)
        {
            if(aux != NULL)
                tamanho +=1;
        }
        
    }
    return tamanho;
}

//Motra os vizinhos de um determinado verticie fornecido
void vizinhosVertice(Graph grafo, int vertice, int *vertovizinhos,int *qtdv){
    link aux;
    int count = 0;
    for (int i = 0; i < grafo->n; i++)
    {
        for (aux = grafo->Apontador[i]; aux != NULL; aux = aux->nextDestino){
            if(i == vertice){
                vertovizinhos[count] = aux->verticeDestino;
                count++;
            }
        }
    }
    (*qtdv) = count;
}

//Retorna o grau deu um vertice fornecido, ou seja a quantidade de arestas de entrada/saida
int grauVertice(Graph grafo, int v){
    link aux;
    int count = 0;
    for (int i = 0; i < grafo->n; i++){
        for (aux = grafo->Apontador[i]; aux != NULL ; aux = aux->nextDestino){
            if(aux->verticeDestino == v || i == v)
                count++;   
        }
    }
    return count;
}

//Retorna 1 para vertice aticulado e 0 para vertice não articulado. Ou seja, sua remocação faz o número
//de componentes conexas aumentar. 
/*
Um grafo é dito conexo se existir pelo menos um caminho entre
cada par de vértices do grafo. Caso contrário, o grafo é chamado
de desconexo.

Um vértice v é uma articulação se e somente se a remoção de v produz 
um grafo com mais componentes conexas que o grafo original.  Essa 
observação permite decidir se um dado vértice é uma articulação. 
Esse algoritmo é consome tempo linear no tamanho do grafo.
*/


// int articulacaoVertice(Graph grafo, int v){
//     link aux;
//     int i;
//     int countVetor = 0;
//     int auxVetor[grafo->n];
//     int auxConexao[grafo->n];
//     int verifica;

//     //Identifica os vertices de destino que inteliga o vertice fornecido
//     for (i = 0; i < grafo->n; i++)
//     {
//         for (aux = grafo->Apontador[i]; aux != NULL; aux = aux->nextDestino)
//         {
//             if(v == i){
//                 auxVetor[countVetor] = aux->verticeDestino;
//                 countVetor++;
//             }
//             else if ( v == aux->verticeDestino)
//             {
//                  auxVetor[countVetor] = i;
//                 countVetor++; 
//             }
            
//         }
//     }
//     for ( i = 0; i < countVetor; i++)
//     {
//          printf("Vertices conectados: %d \n",auxVetor[i]);
//     }

//     //Verifica se esses vertices ficaram descontinuos

//     for (i = 0; i < countVetor; i++)
//         auxConexao[i] = 0;
    

//     for (i = 0; i < grafo->n; i++)
//     {
//         for (aux = grafo->Apontador[i]; aux!= NULL && i != v; aux = aux->nextDestino)
//         {
//             for (int j = 0; j < countVetor; j++)
//             {
//                 if ((i == auxVetor[j] || (aux->verticeDestino == auxVetor[j] )) && aux->verticeDestino != v)
//                 {
//                     auxConexao[j] +=1; 
//                 }
//             }
//         }
//     }
//     for ( i = 0; i < countVetor; i++)
//     {
//         printf("Quantidade Conexao: %d \n",auxConexao[i]);
//         if (auxConexao[i] == 0)
//         {
//             verifica = 0;
//         }
//     }



//     if (verifica == 0)
//         return 1; // É uma articulação
//     else
//         return 0; // Não é uma articulação
// }

//VERSÃO 12:00
// int articulacaoVertice(Graph grafo, int v){
//     link aux;
//     int i;
//     int conexo = 0; //Nao é articulação
//     Graph grafoAux = graphInit((grafo->n)-1);
 

//     for (i = 0; i < grafo->n ; i++){
//             for (aux = grafo->Apontador[i]; aux != NULL && i != v; aux = aux->nextDestino){    
//                 //i = 1 
//                 if (aux->verticeDestino != v){
//                     //as conexóes 6
//                       graphInsert(grafoAux,i,aux->verticeDestino,0);

//                 }
//         }
//     }

//     int indice = 0;
//     int quantidadeVizinhos[grafoAux->n];
    

//     for ( i = 0; i < grafoAux->n; i++)
//     {
//         quantidadeVizinhos[i] = 0;
//         for (aux = grafoAux->Apontador[i]; aux !=NULL;aux = aux->nextDestino)
//         {
//             quantidadeVizinhos[i]++;
//         }
 
//     }
//     printf("quantidade zinhoss: \n");
//     for ( i = 0; i < grafoAux->n; i++)
//     {
//         printf("%d vetor: %d\n",i,quantidadeVizinhos[i]);
//     }

//     //NOTA TENTATIVA ZZERAR VETOR Vizinhos
    
//     //procurar o ultimo vertice, se ele n tiver logo e desconexo e v é uma articulação
//     while(indice < grafoAux->n)
//     {
//         for (aux = grafoAux->Apontador[indice]; aux != NULL; aux = aux->nextDestino){
            
//             quantidadeVizinhos[indice]--;
//             indice = aux->verticeDestino;
//         }
//         indice++;
//     }
//     printf("==============\n");
//     graphShow(grafoAux);
//     printf("==============\n");
//     for ( i = 0; i < grafoAux->n; i++)
//     {
//         printf("%d vetor: %d\n",i,quantidadeVizinhos[i]);
//     }
    
//     if (quantidadeVizinhos[indice-1] == 0 && grafoAux->Apontador[indice-1] == NULL){;
//         return 1;
//     }else{
//         return 0;
//     }
//     return 1;

// }

//mODIFICAÇÃO
int articulacaoVertice(Graph grafo, int v){
    link aux;
    int i;
    int conexo = 0; //Nao é articulação
    int j;
    int indice = 0;
    
    Graph grafoAux = graphInit((grafo->n)-1);
 
    //GERA UM NOVO GRAFO CONTENDO SOMENTE AS ARESTAS QUE NÃO PARTICIA DE V
    //TIPO UMA REMOÇÃO DE V
    for (i = 0; i < grafo->n ; i++){
            for (aux = grafo->Apontador[i]; aux != NULL && i != v; aux = aux->nextDestino){    
                //i = 1 
                if (aux->verticeDestino != v){
                    //as conexóes 6
                      graphInsert(grafoAux,i,aux->verticeDestino,0);

                }
        }
    }

    int vizinhosOriginais[grafo->m];
    printf("valor de m: %d\n",grafo->m);
    j = 0;
    for ( i = 0; i < grafo->n; i++){
        for (aux = grafo->Apontador[i]; aux !=NULL;aux = aux->nextDestino){
            vizinhosOriginais[j] = (i*10)+aux->verticeDestino;
            j++;
        }
    }


    int quantidadeVizinhos[grafoAux->n];
    int vizinhos[grafoAux->m];
    
    //FAZ A DESCOBERTA DA QUANTIDADE DE VIZINHOS DE CADA VERTICE
    j = 0;
    for ( i = 0; i < grafoAux->n; i++){
        quantidadeVizinhos[i] = 0;
        for (aux = grafoAux->Apontador[i]; aux !=NULL;aux = aux->nextDestino){
            quantidadeVizinhos[i]++;
            vizinhos[j] = (i*10)+aux->verticeDestino;
            j++;
        }
    }

    graphShow(grafoAux);
    
    
    printf("quantidade Vizinhos: \n");
    for ( i = 0; i < grafoAux->n; i++)
        printf("%d vetor: %d\n",i,quantidadeVizinhos[i]);

    printf("VIZINHOS ORIGINAIS\n");
    for ( i = 0; i < grafo->m; i++)
        printf("%d vetor: %d\n",i,vizinhosOriginais[i]);

    printf("VIZINHOS: \n");
    for ( i = 0; i < grafoAux->m; i++)
        printf("%d vetor: %d\n",i,vizinhos[i]);

    

    if (quantidadeVizinhos[indice-1] == 0 && grafoAux->Apontador[indice-1] == NULL){;
        return 1;
    }else{
        return 0;
    }
    return 1;

}
