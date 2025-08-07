#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct no{
    char op;
    float numero;
    struct no *ant;
}Pilha;
float resolver_expressao(char x[]);
Pilha* empilha(Pilha *,float);
Pilha* retira();
int main(){
    char entrada[50];    
    scanf("%[^/n]",entrada);
    printf("%f\n", resolver_expressao(entrada));
    return 0;
}

Pilha* empilha(Pilha *topo,float valor){
    Pilha *novo = (Pilha *)malloc(sizeof(Pilha));
    if(!novo)
        exit(1);
    novo->ant = topo;
    novo->numero = valor;
    return novo;
}
Pilha* retira(Pilha **topo){
    if(*topo){
        Pilha *removido = *topo;
        *topo = removido->ant;
        return (removido);
    }
    return NULL;
}
float operacao(float x, float y, char op){

    switch (op)
    {
    case '+':
        return x+y;
        break;
    case '-':
        return x-y;
        break;
    case '/':
        return x/y;
        break;
    case '*':
        return x*y;
        break;
    
    default:
        return 0.0;
    }
    
}
float resolver_expressao(char x[]){
    char *pt;
    float num;
    Pilha *n1, *n2, *pilha = NULL;
    pt = strtok(x, " ");
    while(pt){
        if(pt[0] == '+' || pt[0] == '-' || pt[0] == '/' || pt[0] == '*'){
            n1 = retira(&pilha);
            n2 = retira(&pilha);
            num = operacao(n2->numero, n1->numero, pt[0]);
            pilha = empilha(pilha, num);
            free(n1);
            free(n2);
        }
        else{
            num = strtol(pt, NULL, 10);
            pilha = empilha(pilha, num);
        }
        pt = strtok(NULL, " ");
    }
    n1 = retira(&pilha);
    num = n1->numero;
    free(n1);
    return num;
}