#include <stdio.h>
int funcao(int r, int *per,int *area){
    *per = 2 * 3.14 * r;
    *area = 3.14 * r * r;
}
int main(){
    int r;
    scanf("%d",&r);
    int perimetro,area;
    funcao(r,&perimetro,&area);
    printf("raio: %d\n",r);
    printf("perimetro: %d\n",perimetro);
    printf("area: %d\n",area);
}
