#include "../headers/grafo.h"
#include "../headers/menu.h"

#include <stdio.h>
#include <stdlib.h>
/* REPRESENTAÇÃO POR LISTA DE ADJACÊNCIA: A função graphInit() constrói um grafo com
vértices 0 1 .. V-1 e nenhum arco. */
Graph graphInit(int n){
    int i;
    Graph G = malloc(sizeof *G);
    G->n = n;
    G->m = 0;
    G->A = malloc(n * sizeof(link));
    for (i = 0; i < n; i++)
    G->A[i] = NULL;
    return G;
}
/* REPRESENTAÇÃO POR LISTA DE ADJACÊNCIA: A função graphInsertArc() insere um arco v-w no
grafo G. A função supõe que v e w são distintos, positivos e menores que G->V. Se o grafo
já tem um arco v-w, a função não faz nada. */

void graphInsertArc(Graph G, int v, int w){
    link p;
    for (p = G->A[v]; p != NULL; p = p->next)
    if (p->index == w)
    return;
    p = malloc(sizeof(struct node));
    p->index = w;
    p->next = G->A[v];
    G->A[v] = p;
    G->m++;
}

void graphInsertArcNotSafe(Graph G, int v, int w)
{
    link p;
    p = malloc(sizeof(struct node));
    p->index = w;
    p->next = G->A[v];
    G->A[v] = p;
    G->m++;
}

/* REPRESENTAÇÃO POR LISTA DE ADJACÊNCIA: A função graphShow() imprime, para cada vértice v
do grafo G, em uma linha, todos os vértices adjacentes a v. */
void graphShow(Graph G){
    int i;
    link p;
    for (i = 0; i < G->n; i++)
    {
        printf("%2d:", i);
        for (p = G->A[i]; p != NULL; p = p->next)
        printf(" %2d", p->index);
        printf("\n");
    }
}

void graphPrint(Graph G){
    int i;
    link p;
    for (i = 0; i < G->n; i++)
    {
        for (p = G->A[i]; p != NULL; p = p->next)
        printf("%2d ", p->index);
        printf("-1"); // digito para marcar fim de lista
        printf("\n");
    }
}

Graph graphFree(Graph G){
    int i;
    link p;
    for (i = 0; i < G->n; i++){
        p = G->A[i];
        while (p != NULL){
            G->A[i] = p;
            p = p->next;
            free(G->A[i]);
        }
        G->A[i] = NULL;
    }
    free(G->A);
    G->A = NULL;
    free(G);
    return NULL;
}