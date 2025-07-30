#include <stdio.h>
    #include <stdlib.h>
//ESSE ALGORITMO É INEFICIENTE, POREM CRIATIVO DE CERTA FORMA (nao usar isso em casa)
void ordena_vet(int v_origem[],int n,int *comp,int *troca){
    int v[n*2];
    for(int i = 0 ; i< n; i++){
        v[i] = 0;
    }
    int troca1 = 0, troca2 = 0;
    for (int i = 0; i<n ; i++){
        (*comp)++;
        if(v_origem[i] < n){
            
            v[troca1] = v_origem[i];
            troca1++;
        }
        else{   
            v[n+troca2] = v_origem[i]; 
            troca2++;
        }
    }
    *troca = troca1+troca2;
    if(troca1>0){
        for (int i=n; i > 0; i-- ){
		for ( int j=0; j < i; j++ ){
            (*comp)++;
            if(v[j]!=0 && v[j+1]!= 0){
                if ( v[j] > v[j+1] ) {
                (*troca)++;
                int aux = v[j];
		        v[j] = v[j+1];
		        v[j+1] = aux; 
                }
            }
			
		}
    }    
    }
	if(troca2>0){
        for (int i=2*n+1; i > n; i-- ){
            for ( int j=n; j < i; j++ ){
                (*comp)++;
                if(v[j]!=0 && v[j+1]!= 0){
                    if ( v[j] > v[j+1] ) {
                    (*troca)++;
                    int aux = v[j];
                    v[j] = v[j+1];
                    v[j+1] = aux; 
                    }
                }
            }
        }
    }
    troca1 = 0;
    for(int i = 0; i<n*2 ; i++){
        if(v[i]!=0){
            v_origem[troca1++] = v[i];
        }
        
    }
}
int main(){
    int N;
    int comp=0, trocas=0;    
    scanf("%d",&N);
    int v[N];
    for(int i = 0 ; i<N ; i++){
        scanf("%d",&v[i]);
    }
    ordena_vet(v,N,&comp,&trocas);
    for(int i = 0 ; i<N ; i++){
        printf("%d",v[i]);
    }
    printf("\ncomparacoes: %d \n",comp );
    printf("trocas: %d",trocas);
}
