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
    int n=0,op;
    
    while(op!=6){   
        printf("Escolha :\n1 - inserir elem\n2 - remover elem\n3 - visualizar primeiro elemento\n4 - listar elem\n5 - verificar se esta vazia\n6 - sair\n\n");
        scanf("%d",&op);
        switch (op){
        
        case 1:
            
            
            printf("Digite um inteiro para inserir: \n\n");
            scanf("%d",&n);
            inserir(n);
            
            
            break;
        case 2:
            printf("Digite um inteiro para remover: \n\n");
            scanf("%d",&n);
            remover(n);
            
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
    Lista *aux = prim;
    if(aux == NULL){
        printf("Lista vazia\n\n");
        return;
    }
    if(prim->val == val){
        printf("Removendo %d\n\n",val);
        prim = prim->prox;
        free(aux);
        p=NULL;
        q=NULL;
        if(aux==fim){
            prim = NULL;
            fim = NULL;
            return;
        }
        
        
        return;
    }

    while(aux!=fim){
        q = aux;
        aux = aux->prox;
        p = aux->prox;
        if(aux->val == val){
            
            printf("Removendo %d\n\n",val);
            q->prox = p;
            p->ant = q;
            if(fim == aux){
                fim = q;
                q->prox = prim;
            }
            
            free(aux);
            return;
        }
        
        
       
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
        printf("%d ",p->val);
    }
    else{
        printf("Lista vazia\n\n");
        return;
    }
    while(p!=fim){
        p = p->prox;
        printf("%d ",p->val);
        
    }
    printf("\n\n");
}
void verifica_vazia(){
    if(prim!=NULL){
        
        printf("Lista nao esta vazia\n\n");
    }
    else{
        printf("Lista vazia\n\n");
        return;
    }

}


