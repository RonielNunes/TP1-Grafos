
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
int grauVertice(Graph grafo, int v);
void vizinhosVertice(Graph grafo, int vertice);
int tamanhoGrafo(Graph grafo);
//int articulacaoVertice(Graph grafo, int v);
int articulacaoVertice(Graph grafo, int v);