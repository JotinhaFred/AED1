#include "biblioteca.h"

#include <string.h>

struct livros
{
    int codigo;
    char titulo[100];
    char autor[100];
    int ano;
    
};
struct biblioteca{
    int tamanho;
    Livros **colecao;
    int max;
};

Biblioteca * cria_biblioteca(int max){
    Biblioteca* b = (Biblioteca*) calloc(1,sizeof(Biblioteca));
    if (b == NULL) {
        printf("ERRO AO ALOCAR MEMORIA!\n");
        exit(1);
    }
    b->max = max;
    b->tamanho = 0;
    b->colecao = (Livros**) calloc(max,sizeof(Livros));
    if(b->colecao == NULL){
        printf("ERRO AO ALOCAR MEMORIA!\n");
        exit(1);
    }
    return b;
}
void cria_livro (Biblioteca* b,int cod, char *titulo,char *autor, int ano) {
    Livros* l = (Livros*) calloc(1,sizeof(Livros));
    if (l == NULL) {
        printf("ERRO AO ALOCAR MEMORIA!\n");
        exit(1);
    }
    for(int i = 0; i<(b->tamanho); i++){
        if(b->colecao[i]->codigo == cod){
            printf("Ja existe um livro com este codigo");
            return;
        }   
    }
    l->codigo = cod;
    for(int i=0; i<strlen(titulo); i++){
        l->titulo[i] = titulo[i];
    }
    for(int i=0; i<strlen(autor); i++){
        l->autor[i] = autor[i];
    }
    l->ano = ano;
    append(b,l);
}
void libera(Biblioteca* b){
    while(b->tamanho){
        free(b->colecao[b->tamanho]);
        b->tamanho--;
    }
    free(b->colecao);
    free(b);
}
void acessa(Biblioteca* b,int cod){
    for(int i = 0; i<(b->tamanho); i++){
        if(b->colecao[i]->codigo == cod){
            printf("\nRESULTADO DA BUSCA:\n");
            printf("\nAno: %d\n",b->colecao[i]->ano);
            printf("Titulo: %s\n",b->colecao[i]->titulo);
            printf("Autor: %s\n",b->colecao[i]->autor);
        }
    }
}
void append(Biblioteca* b,Livros *livro){
    if(b->tamanho <= b->max){
        if(b->colecao[b->tamanho]==NULL){
            b->colecao[b->tamanho++] = livro;
        }
        
        return;
    }
    
    printf("TAMANHO MAXIMO EXCEDIDO");
    exit(EXIT_FAILURE);
}
void exibe(Biblioteca* b){
    printf("\n-----------BIBLIOTECA----------\n");
    for(int i = 0; i<(b->tamanho);i++){
        if(b->colecao[i]==NULL) continue;
        printf("\nAno: %d\n",b->colecao[i]->ano);
        printf("Titulo: %s\n",b->colecao[i]->titulo);
        printf("Autor: %s\n",b->colecao[i]->autor);
        printf("Codigo: %d\n",b->colecao[i]->codigo);
    }
}
void remove_livro(Biblioteca* b,int cod){
    for(int i = 0; i<(b->tamanho);i++){
        if(b->colecao[i]->codigo == cod){
            Livros *l = b->colecao[i];
            free(l);
            b->colecao[i] = NULL;
        }
    }
}