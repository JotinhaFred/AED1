#include <stdio.h>
#include <stdlib.h>
void inserir(int);
void remover();
void visualizar();
void listar();
void verifica_vazia();
typedef struct no {
    int val;
    struct no *prox;
    struct no *ant;
}Lista;
Lista *q,*p,*prim,*fim;
int main(){
    q = NULL;
    p = NULL;
    prim = NULL;
    fim = NULL;
    int n=0,op,max = 0;
    int conta = 0;
    while(op!=6){
        printf("Escolha :\n0 - define tamanho\n1 - inserir elem\n2 - remover elem\n3 - visualizar primeiro elemento\n4 - listar elem\n5 - verificar se esta vazia\n6 - sair\n\n");
        scanf("%d",&op);
        switch (op){
        case 0:

            printf("Defina o tamanho da Lista\n\n");
            scanf("%d",&max);

            break;
        case 1:

            if(conta>=max){
                printf("Lista cheia\n\n");
                break;
            }
            printf("Digite um inteiro para inserir: \n\n");
            scanf("%d",&n);
            inserir(n);
            conta++;

            break;
        case 2:
            printf("Digite um inteiro para remover: \n\n");
            scanf("%d",&n);
            remover(n);
            conta--;
            break;
        case 3:

            visualizar();
            break;
        case 4:

            listar();
            break;
        case 5:

            verifica_vazia();
            break;
        default:
            break;
        }
    }

}
void inserir(int val){
    p = (Lista*) malloc(sizeof(Lista));
    p->ant = q;
    p->prox = prim;
    p->val = val;
    if(prim==NULL){
        prim = p;
        q = p;
        fim = p;
        return;
    }
    fim = p;
    q->prox = p;
    q = p;
}
void remover(int val){

    if(prim->val == val){
        printf("Removendo %d\n\n",val);

        free(prim);
        p=NULL;
        q=NULL;
        fim=NULL;
        prim = NULL;
        return;
    }
    Lista *aux = prim;


    while(aux!=fim){
        q = aux->ant;
        if(aux->val == val){

            printf("Removendo %d\n\n",val);
            q->prox = aux->prox;
            (aux->prox)->ant = q;
            if(fim == aux){
                fim = aux->ant;
            }
            free(aux);
            return;
        }

        aux = aux->prox;

    }



    printf("Elemento não encontrado\n\n");


}
void visualizar(){
    if(prim!=NULL){
        printf("Primeiro elemento %d\n\n",prim->val);
        return;
    }
    printf("Lista vazia\n\n");

}
void listar(){
    if(prim!=NULL){
        p = prim;
    }
    else{
        printf("Lista vazia\n\n");
        return;
    }
    while(p!=NULL){
        printf("%d ",p->val);
        p = p->prox;
    }
    printf("\n\n");
}
void verifica_vazia(){

        printf("Lista esta vazia\n\n");
        return;

    printf("Lista nao esta vazia\n\n");
}


