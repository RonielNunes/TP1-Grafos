typedef struct node *link;
struct node
{
 int index;
 link next;
};
typedef struct graph *Graph;

struct graph{
    link *A;
    int n;
    int m;
};

Graph graphInit(int n);
void graphInsertArc(Graph G, int v, int w);
void graphInsertArcNotSafe(Graph G, int v, int w);
void graphShow(Graph G);
void graphPrint(Graph G);