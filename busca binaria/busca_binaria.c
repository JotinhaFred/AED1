#include <stdio.h>
#include <stdlib.h>

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
    while(fread(&vector[i], sizeof(int), 1, arquivo) == 1){
        i++;
    }      
    printf("%d",busca_binaria(vector,chave));
    fclose(arquivo);
    return 0;
}
int busca_binaria(int vector[100],int item){
    int begin = 0;
    int end = 100;
    while (begin <= end) {
        int i = (begin + end) / 2;
        if (vector[i] == item) {
            return i;
        }
        if (vector[i] < item) {
            begin = i + 1;
        } else {
            end = i;
        }
    }
    return -1;
}