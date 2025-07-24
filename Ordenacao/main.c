#include <stdio.h>
#include <stdlib.h>
//ESSE ALGORITMO É INEFICIENTE, POREM CRIATIVO DE CERTA FORMA (nao usar isso em casa)
void ordena_vet(int v_origem[],int n,int *comp,int *troca){
    int v[n];
    for (int i = 0; i<n ; i++){
        (*comp)++;
        if(v_origem[i] < n/2){
            
            v[i] = v_origem[i];
            (*troca)++;
        }
        else{   
            v[(n/2)+*troca] = v_origem[i]; 
            (*troca)++;
        }
    }
    
	for (int i=n/2-1; i > 0; i-- ){
		for ( int j=0; j < i; j++ ){
            (*comp)++;
			if ( v[j] > v[j+1] ) {
                (*troca)++;
                int aux = v[j];
		        v[j] = v[j+1];
		        v[j+1] = aux; 
            }
				

		}
		

	}
    
    for (int i=n-1; i > n/2; i-- ){
		for ( int j=n/2; j < i; j++ ){
            (*comp)++;
			if ( v[j] > v[j+1] ){
                (*troca)++;
                int aux = v[j];
		        v[j] = v[j+1];
		        v[j+1] = aux; 
                
            }
				

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
