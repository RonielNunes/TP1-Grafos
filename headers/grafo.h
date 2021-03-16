
typedef struct node *link;

struct node
{
    int verticeDestino;//index
    float peso;
    link nextDestino;
};

typedef struct graph *Graph;

struct graph
{
    link *Apontador;
    int n; //vertice
    int m; //aresta
};

Graph graphInit(int n);
void graphShow(Graph grafo);
void graphInsert(Graph grafo, int v, int destino, float peso);