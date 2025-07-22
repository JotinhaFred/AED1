#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo;
    int i;

    // Abre o arquivo para escrita binária
    arquivo = fopen("numeros.bin", "wb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    // Escreve os números de 1 a 100 no arquivo binário
    for (i = 1; i <= 100; i++) {
        if (fwrite(&i, sizeof(int), 1, arquivo) != 1) {
            perror("Erro ao escrever no arquivo");
            fclose(arquivo);
            return 1;
        }
    }

    printf("Arquivo binário 'numeros.bin' gerado com sucesso.\n");

    fclose(arquivo);
    return 0;
}
