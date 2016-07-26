#include <stdlib.h>
#include <stdio.h>

void Insercao(TipoItem *A, TipoIndice n){
	TipoIndice i, j;
	TipoItem x;
	
	for(i=2; i<=n; i++){
		x=A[i];
		j=i-1;
		A[0]=x; /* sentinela */
		while(x.Chave<A[j].Chave){
			A[j+1] = A[j];
			j--;
		}
		A[j+1] = x;
	}
}

int main(){

}