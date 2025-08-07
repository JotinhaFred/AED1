#ifndef BIBLIOTECA_H 
#define BIBLIOTECA_H
#include <stdlib.h>
#include <stdio.h>
typedef struct livros Livros;
typedef struct biblioteca Biblioteca;

Biblioteca* cria_biblioteca(int);

void cria_livro(Biblioteca* ,int, char *,char *, int);
void libera(Biblioteca*);
void acessa(Biblioteca*,int);
void remove_livro(Biblioteca*,int);
void exibe(Biblioteca*);
void append(Biblioteca*,Livros*);



#endif