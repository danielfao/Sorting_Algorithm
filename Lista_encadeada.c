#include <stdlib.h>
#include <stdio.h>

typedef struct lista {
	int valor;
	struct lista *prox;
}lista;

void insere (lista *l, int v){
	lista *nova;
	nova = malloc(sizeof(lista));
	nova -> valor = v;
	nova -> prox = l -> prox;
	l -> prox = nova;
}

int main(){
	lista l;
	int v;
	
	printf("Digite o valor v: ");
	scanf("%d", &l);
	insere(&l, v);
}