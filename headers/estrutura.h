/*tAD ITEM*/
typedef struct item{
    int numero;
    /*mais coisas*/
}Titem;

typedef struct Celula* Apontador;

/*CELULA*/
typedef struct Celula{
    Titem item;
    struct  Celula *pProx; //Apontador para a proxima celula
}Tcelula;

/*TAD LISTA*/
typedef struct{
    Apontador pPrimeiro;
    Apontador pUltimo;
}TlistaEncadeada;

void FLVazia(TlistaEncadeada *pLista);

int LEHVazia(TlistaEncadeada *pLista);
void insere(TlistaEncadeada *pLista, Titem *pItem);
void imprime(TlistaEncadeada *pLista);
int LRetira(TlistaEncadeada *pLista, Titem *pItem);