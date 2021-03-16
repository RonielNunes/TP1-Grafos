#include "./headers/menu.h"
#include "./headers/grafo.h"

#include <stdio.h>
#include <stdlib.h>
//gcc -o teste main.c ./sources/grafo.c ./sources/menu.c ./headers/grafo.h ./headers/menu.h
//https://www.geeksforgeeks.org/graph-and-its-representations/
int main(int argc, char const *argv[])
{  
    int n = 5;
    Graph grafo;
    int verticeOrigem = 1;
    int verticeDestino = 2;
    float peso = 1.2;

    grafo = graphInit(n);


    graphInsert(grafo,verticeOrigem,verticeDestino,peso);
    graphInsert(grafo,2,5,2.3);
    graphInsert(grafo,3,5,-8.4);
    graphInsert(grafo,3,4,0.3);
    graphInsert(grafo,4,5,4.6);
    graphInsert(grafo,1,5,0.1);
    graphInsert(grafo,5,6,22.3);
    graphShow(grafo);
    //graphPrint(grafo);
    return 0;
}
