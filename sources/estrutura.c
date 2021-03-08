#include "estrutura.h"



void FLVazia(TlistaEncadeada *pLista){
    pLista->pPrimeiro = (Apontador)malloc(sizeof(Tcelula));

    pLista->pUltimo = pLista->pPrimeiro;

    pLista->pPrimeiro->pProx = NULL;
}

int LEHVazia(TlistaEncadeada *pLista){
    return (pLista->pPrimeiro == pLista->pUltimo);
}

void insere(TlistaEncadeada *pLista, Titem *pItem){
    pLista->pUltimo->pProx = (Apontador)malloc(sizeof(Tcelula));
    pLista->pUltimo = pLista->pUltimo->pProx;
    pLista->pUltimo->item = *pItem;
    pLista->pUltimo->pProx = NULL;
}
int LRetira(TlistaEncadeada *pLista, Titem *pItem){
    Apontador pAux;

    if(LEHVazia(pLista))
        return 0;
    
    *pItem = pLista->pPrimeiro->item;
    pAux = pLista->pPrimeiro;
    pLista->pPrimeiro = pLista->pPrimeiro->pProx;
    free(pAux);
    if (pLista->pPrimeiro == NULL)
    {
        pLista->pUltimo =  NULL; //Lista vazia
    }
    return 1;
    
}   

void imprime(TlistaEncadeada *pLista){
    Apontador pAux;

    pAux = pLista->pPrimeiro->pProx;

    while(pAux != NULL)
    {
        printf("VALOR DA LISTA ENCADEADA: %d \n",pAux->item.numero);
        pAux =pAux->pProx;
    }