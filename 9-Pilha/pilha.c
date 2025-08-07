#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void insere(char);
char retira();
typedef struct no{
    char c;
    struct no *ant;
}Pilha;
Pilha *p,*q,*topo;
int main(){
    p,q,topo = NULL;
    char s[15];
    int i = 0;
    scanf("%s",s);
    while(s[i]!='\0'){
        insere(s[i++]);
    }
    while(topo!=NULL){ 
        printf("%c",retira());
    }
}
void insere(char c){
    p = (Pilha *)malloc(sizeof(Pilha));
    topo = p;
    p->c = c;
    p->ant = q;
    q = p;
}
char retira(){
    p = topo;
    char c;
    if(p!=NULL){
        topo = p->ant;
        c = p->c;
        free(p);
        return c;
    }
}