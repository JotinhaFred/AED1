#include <stdio.h>
#include "lista_estatica.h"

int main(){
    
    int n=0,op=0,max = 0;
    printf("Defina o tamanho\n");
    scanf("%d",&max);
    int lista[max];  
    int conta = 0; 
    while(op!=7){
        
        printf("Escolha :\n1 - inserir elem\n2 - remover primeiro elemento \n3 - visualizar primeiro elemento\n4 - listar elem\n5 - verificar se esta vazia\n6 - alterar elemento especifico\n7 - sair\n");
        scanf("%d",&op);
        switch (op){
        case 1:
            if(conta>=max){
                printf("Lista cheia\n");
                break;
            }
            printf("\ndigite um inteiro\n");
            scanf("%d",&n);
            inserir(lista,conta++,n);
            
            break;
        case 2:  
            remover_inicio(lista,conta);
            conta--;
            break;
        case 3:
            if(conta==0){
                printf("Lista vazia\n");
                break;
            }
            visualizar(lista);
            break;
        case 4:
            
            listar(lista,conta);
            break;
        case 5:
            if(conta>0)
                printf("Nao esta vazia\n");
            else
                printf("Esta vazia\n");
            break;
        case 6:
            printf("\nDigite o valor do elemento a ser trocado\n");
            scanf("%d",&n);
            alterar(lista,conta,n);
            
            break;
        default:
            break;
        }
    }
    
}
