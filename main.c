#include "./headers/menu.h"
#include "./headers/grafo.h"

#include <stdio.h>
#include <stdlib.h>
//gcc -o teste main.c ./sources/grafo.c ./sources/menu.c ./headers/grafo.h ./headers/menu.h
int main(int argc, char const *argv[])
{  
    int n = 5;
    Graph grafo;

    grafo = graphInit(n);
    graphInsertArc(grafo,1,2);
    graphInsertArc(grafo,2,5);
    graphInsertArc(grafo,3,5);
    graphInsertArc(grafo,3,4);
    graphInsertArc(grafo,4,5);

    graphShow(grafo);
    //graphPrint(grafo);
    return 0;
}
