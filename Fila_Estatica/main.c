#include <stdio.h>
#include <stdlib.h>
void inserir(int fila[],int,int);
void remover_inicio(int fila[],int);
void visualizar(int fila[]);
void listar(int fila[],int);
void remover(int fila[],int,int);


int main(){
    
    int n=0,op=0,max = 0;
    printf("Defina o tamanho\n");
    scanf("%d",&max);
    int fila[max];  
    int conta = 0; 
    while(op!=7){
        
        printf("Escolha :\n1 - inserir elem\n2 - remover primeiro elemento \n3 - visualizar primeiro elemento\n4 - listar elem\n5 - verificar se esta vazia\n6 - remover elemento especifico\n7 - sair\n");
        scanf("%d",&op);
        switch (op){
        case 1:
            if(conta>=max){
                printf("Lista cheia\n");
                break;
            }
            printf("\ndigite um inteiro\n");
            scanf("%d",&n);
            inserir(fila,conta++,n);
            
            break;
        case 2:  
            remover_inicio(fila,conta);
            conta--;
            break;
        case 3:
            if(conta==0){
                printf("Fila vazia\n");
                break;
            }
            visualizar(fila);
            break;
        case 4:
            
            listar(fila,conta);
            break;
        case 5:
            if(conta>0)
                printf("Nao esta vazia\n");
            else
                printf("Esta vazia\n");
            break;
        case 6:
            printf("\nDigite o valor do elemento a ser removido\n");
            scanf("%d",&n);
            remover(fila,conta,n);
            conta--;
            break;
        default:
            break;
        }
    }
    
}
void inserir(int fila[],int tam,int val){
    fila[tam] = val;
    printf("\n%d Inserido da fila\n",val);
}
void remover_inicio(int fila[],int tam){
    int aux = fila[0];
    int i = 0;
    if(tam == 0){
        printf("\nFila vazia\n");
        return;
    }
    printf("\n%d Removido da fila\n",aux);
    while(i<tam){
        fila[i] = fila[i+1];
        fila[i+1] = aux;
        aux = fila[i+1];
        i++;
    }
}
void visualizar(int fila[]){
    
    printf("\nPrimeiro elemento %d\n",fila[0]);
    return;   
}
void listar(int fila[],int tam){
    int i=0;
    if(tam==0){
        printf("\nFila vazia\n");
        return;
    }
    while(i<tam){
        printf("%d ",fila[i]);
        i++;
    }
    printf("\n");
}
void remover(int fila[],int tam, int val){
    int aux = 0;
    int i;
    if(tam == 0){
        printf("\nFila vazia\n");
        return;
    }
    for(i = 0; i<tam;i++){
        if(fila[i]==val){
            aux = fila[i];
            printf("\n%d Removido da fila\n",fila[i]);
            break;
        }
    }
    if(aux!=fila[i]&&aux!=val){
        printf("\nElemento nao encontrado na fila\n");
        return;
    }
    if(i==tam-1){
        return;
    }
    while(i<tam){
        fila[i] = fila[i+1];
        fila[i+1] = aux;
        aux = fila[i+1];
        i++;
    }
}


//0) Definir o tamanho da fila
//1) Inserir um elemento na fila
//2) Remover um elemento da fila
//3) Visualizar o primeiro elemento da fila (frente da fila)
//4) Exibir todos os elementos da fila
//5) Verificar se a fila está vazia ou cheia (caso utilize vetor fixo)
//6) Sair do programa
