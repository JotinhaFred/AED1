#include <stdio.h>
#include <stdlib.h>
void busca_binaria(int vector[],int item);
int main() {
    FILE *arquivo;
    arquivo = fopen("numeros.bin", "rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }
    int chave,i = 0;
    int vector[100];
    scanf("%d",&chave);
    while(fread(&vector[i], sizeof(int), 1, arquivo) == 1){//preenche o vetor com os valores do arquivo, ate fread retornar -1 (EOF)
        i++;
    }      
    busca_binaria(vector,chave);
    fclose(arquivo);
    return 0;
}

void busca_binaria(int vector[],int item){
    int inicio = 0;
    int fim = 100;
    while (inicio <= fim) {
        int i = (inicio + fim) / 2;//torna o indice o meio entre o inicio e o fim
        if (vector[i] == item) {
            printf("Elemento encontrado na posicao %d",i);
            return;
        }
        if (vector[i] < item) {
            inicio = i + 1;//arrasta para frente o ponto de inicio, o proximo elemento apos o elemento i, pois ele é menor que o item procurado e entao o item deve estar depois
        } else {
            fim = i;//faz o final da busca ser quando alcançar o elemento i, pois ele é maior que o item procurado e entao o item deve estar antes
        }
    }
    printf("Elemento não encontrado\n");
    
}