#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int numero;
    struct no *esquerda;
    struct no *direita;
}No;
int conta;
void insercao(No **,int);
void ordena(No *,int[]);
int main() {
    No *raiz;
    raiz = NULL;
    int N;   
    scanf("%d",&N);
    int v[N];
    for(int i = 0 ; i<N ; i++){
        scanf("%d",&v[i]);
        insercao(&raiz,v[i]);
    }
    ordena(raiz,v);
}

void insercao(No **pRaiz, int numero2){
    if (*pRaiz == NULL){
        *pRaiz = (No *)malloc(sizeof(No));
        (*pRaiz)->esquerda = NULL;
        (*pRaiz)->direita = NULL;
        (*pRaiz)->numero = numero2;
    } 
    else {
        if (numero2 < ((*pRaiz)->numero)) {
            insercao(&((*pRaiz)->esquerda), numero2);
        } 
        else {
            insercao(&((*pRaiz)->direita), numero2);
        }
    }
}
void ordena(No *pRaiz,int p[]) {
    if (pRaiz != NULL) {
        ordena(pRaiz->esquerda,p);
        p[conta++] = pRaiz->numero;
        ordena(pRaiz->direita,p);
    }
}