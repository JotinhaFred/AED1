#include "biblioteca.h"


int main(){
    Biblioteca *b = cria_biblioteca(10);
    cria_livro(b,1,"Herlock Sholmes","Maurice",1890);
    cria_livro(b,2,"exemplo","autor",1900);
    
    acessa(b,1);
    remove_livro(b,1);
    exibe(b);
    libera(b);

}