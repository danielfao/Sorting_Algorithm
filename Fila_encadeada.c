#include <stdlib.h>
#include <stdio.h>

typedef struct cel {
	int valor;
	struct cel *prox;
}celula;

typedef struct {
	celula *inicio;
	celula *fim;
} fila;

celula * cria_fila(){
	celula *aux = malloc(sizeof(celula)); //cabeça
	aux->prox = NULL;
	return aux;
}

void insere(celula *cabeca, int v){
	celula *nova;
	nova = malloc(sizeof(celula));
	nova -> valor = v;
	nova -> prox = cabeca -> prox;
	cabeca -> prox = nova;
}

int remove(celula *cabeca){
	int x;
	celula *aux;
	aux = cabeca -> prox;
	x = aux -> valor;
	cabeca -> prox = aux -> prox;
	free(aux);
	return x;
}

void imprime (celula *ler){
	celula *p;
	for (p = ler->prox; p != NULL; p = p->prox){
		printf("%d \n", p->valor);
	}
}

int main(){
	celula *fila = cria_pilha();
	insere(fila, 1);
	insere(fila, 2);
	insere(fila, 3);
	insere(fila, 4);
	insere(fila, 5);
	imprime(fila);
	printf("\n");
	remove(fila);
	remove(fila);
	imprime(fila);
}