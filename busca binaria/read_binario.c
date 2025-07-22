#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivo;
    int numero;

    // Abre o arquivo para leitura binária
    arquivo = fopen("numeros.bin", "rb");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    printf("Conteudo do arquivo numeros.bin:\n");

    // Lê e exibe os números até o final do arquivo
    while (fread(&numero, sizeof(int), 1, arquivo) == 1) {
        printf("%d\n", numero);
    }

    fclose(arquivo);
    return 0;
}
