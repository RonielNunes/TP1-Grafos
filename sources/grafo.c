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
    for (int i = 0; i < grafo->n; i++){
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
void vizinhosVertice(Graph grafo, int vertice){
    link aux;
    printf("{");
    for (int i = 0; i < grafo->n; i++)
    {
        for (aux = grafo->Apontador[i]; aux != NULL; aux = aux->nextDestino){
            if (aux->verticeDestino == vertice)
            {
                printf("%d ",i);
            }
            if(i == vertice){
                printf("%d ",aux->verticeDestino);
            }
        }
    }
    printf("}\n");
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

// void articulacaoVertice(Graph grafo, int v){
//     link aux;
//     int count = 0;
//     int vetorAux[grafo->n]; //Vetor para guardar os vertices
//     int countVetor = 0;
//     int i;
//     for (i = 0; i < grafo->n; i++){
//         for (aux=grafo->Apontador[i]; aux != NULL; aux = aux->nextDestino)
//         {
//             if (aux->verticeDestino == v){
//                 count++; 
//            }    
//         }
//         if(count > 0 || i == 0 || i == v || aux == NULL){
//             count = 0;
//         }else{
//             printf("valor do i: %d\n", i);
//             vetorAux[countVetor] = ;
//             countVetor++;
//         }
//     }

//     //Mostra os vertices que não fazem ligação com v
//     for (i = 0; i < countVetor; i++)
//     {
//         printf("%d = %d\n",i,vetorAux[i]);
//     }
//     printf("valor de countVetor: %d",countVetor);
// }

int articulacaoVertice(Graph grafo, int v){
    link aux;
    int i;
    int countVetor = 0;
    int auxVetor[grafo->n];
    int auxConexao[grafo->n];

    //Identifica os vertices de destino que inteliga o vertice fornecido
    for (i = 0; i < grafo->n; i++)
    {
        for (aux = grafo->Apontador[i]; aux != NULL; aux = aux->nextDestino)
        {
            if(v == i){
                auxVetor[countVetor] = aux->verticeDestino;
                countVetor++;
            }          
        }
    }
    // for ( i = 0; i < countVetor; i++)
    // {
    //     printf("Vertices conectados: %d \n",auxVetor[i]);
    // }

    //Verifica se esses vertices ficaram descontinuos

    for (i = 0; i < countVetor; i++)
        auxConexao[i] = 0;
    

    for (i = 0; i < grafo->n; i++)
    {
        for (aux = grafo->Apontador[i]; aux!= NULL && i != v; aux = aux->nextDestino)
        {
            for (int j = 0; j < countVetor; j++)
            {
                if (i == auxVetor[j] || aux->verticeDestino == auxVetor[j])
                {
                    auxConexao[j] +=1; 
                }
            }
        }
    }
    // for ( i = 0; i < countVetor; i++)
    // {
    //     printf("Quantidade Conexao: %d \n",auxConexao[i]);
    // }

    if (countVetor == 0)
        return 1; // É uma articulação
    else
        return 0; // Não é uma articulação
}