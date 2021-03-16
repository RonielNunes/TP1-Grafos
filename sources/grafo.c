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
