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
}Fila;
Fila *prim,*q,*p,*fim;
int main(){
    prim = NULL;
    q = NULL;
    p = NULL;
    int n=0,op,max = 0;
    int conta = 0;
    while(op!=6){   
        printf("Escolha :\n0 - define tamanho\n1 - inserir elem\n2 - remover elem\n3 - visualizar primeiro elemento\n4 - listar elem\n5 - verificar se esta vazia\n6 - sair\n\n");
        scanf("%d",&op);
        switch (op){
        case 0:
            
            printf("defina o tamanho da fila\n\n");
            scanf("%d",&max);
            
            break;
        case 1:
            
            if(conta>=max){
                printf("Lista cheia\n\n");
                break;
            }
            printf("digite um inteiro\n\n");
            scanf("%d",&n);
            inserir(n);
            conta++;
            
            break;
        case 2:
            
            remover();
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
    p = (Fila*) malloc(sizeof(Fila));
    
    p->val = val;
    p->prox = NULL;
    if(q!=NULL)
        q->prox = p;
    
    if(prim==NULL){
        prim = p;
    }
    q = p;
    fim = p;
}
void remover(){
    int val;
    Fila *aux;
    if(prim!=NULL){
        val = prim->val;
        printf("Removendo o %d\n\n",val);
        aux = prim;
        prim = prim->prox;
        free(aux);
    }
    else{
        printf("Lista vazia\n\n");
    }
    
}
void visualizar(){
    if(prim!=NULL){
        printf("Primeiro elemento %d\n\n",prim->val);
        return;
    }
    printf("Fila vazia\n\n");
    
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
    if(prim==NULL){
        printf("Lista esta vazia\n\n");
        return;
    }
    printf("Lista nao esta vazia\n\n");
}



//0) Definir o tamanho da fila
//1) Inserir um elemento na fila
//2) Remover um elemento da fila
//3) Visualizar o primeiro elemento da fila (frente da fila)
//4) Exibir todos os elementos da fila
//5) Verificar se a fila está vazia ou cheia (caso utilize vetor fixo)
//6) Sair do programa
