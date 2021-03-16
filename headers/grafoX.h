//link ponteiro para node que é uma struct{int index, link next};
typedef struct node *link;
struct node{
 int index;
 link next;
};

//Graph Ponteiro para graph que é uma struct{link *A, int n, int m};
typedef struct graph *Graph;
struct graph{
    link *A;//Aponta para os proximos vertices
    int n; //Vertice
    int m; //Aresta
    float peso; //Peso 
};

Graph graphInit(int n);
void graphInsertArc(Graph G, int v, int w);
void graphInsertArcNotSafe(Graph G, int v, int w);
void graphShow(Graph G);
void graphPrint(Graph G);