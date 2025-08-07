#include <stdio.h>
#include <stdlib.h>
#include "Lista_estatica.h"



void inserir(int lista[],int tam,int val){
    lista[tam] = val;
    printf("\n%d Inserido da Lista\n",val);
}
void remover_inicio(int lista[],int tam){
    int aux = lista[0];
    int i = 0;
    if(tam == 0){
        printf("\nLista vazia\n");
        return;
    }
    printf("\n%d Removido da lista\n",aux);
    while(i<tam){
        lista[i] = lista[i+1];
        lista[i+1] = aux;
        aux = lista[i+1];
        i++;
    }
}
void visualizar(int lista[]){
    
    printf("\nPrimeiro elemento %d\n",lista[0]);
    return;   
}
void listar(int lista[],int tam){
    int i=0;
    if(tam==0){
        printf("\nLista vazia\n");
        return;
    }
    while(i<tam){
        printf("%d ",lista[i]);
        i++;
    }
    printf("\n");
}
void alterar(int lista[],int tam, int val){
    int aux = 0;
    int novoitem;
    int i;
    if(tam == 0){
        printf("\nLista vazia\n");
        return;
    }
    for(i = 0; i<tam;i++){
        if(lista[i]==val){    
            
            printf("Digite o elemento que voce quer inserir no lugar\n");
            scanf("%d",&novoitem);  
            printf("\n%d Trocado por \n",lista[i],novoitem);
            aux = lista[i]; 
            lista[i] = novoitem;
            
            
            break;
        }
    }
    if(aux!=lista[i]&&aux!=val){
        printf("\nElemento nao encontrado na lista\n");
        return;
    }
   
}