#include <stdio.h>

void torre(int n, char origem, char destino, char auxiliar) {
    if (n == 1) {
        printf("Disco %d de %c para %c\n", n, origem, destino);
        return;
    }
    torre(n - 1, origem, auxiliar, destino);

    printf("Disco %d de %c para %c\n", n, origem, destino);

   
    torre(n - 1, auxiliar, destino, origem);
}

int main() {
    int num_discos;
    scanf("%d", &num_discos);
    torre(num_discos, 'A', 'C', 'B');  

    return 0;
}