/*Conceito de pilha: LIFO (Last In, First Out).
Utilizando a cabeça como topo, então o novo item sempre será adicionado
logo depois da cabeça, para manter tempo constante e tempo de pilha.*/

#include <stdlib.h>
#include <stdio.h>

typedef struct cel {
	int valor;
	struct cel *prox;
}celula;

celula * cria_pilha(){
	celula *aux = malloc(sizeof(celula)); //cabeça
	aux->prox = NULL;
	return aux;
}

void push(celula *cabeca, int v){
	celula *nova;
	nova = malloc(sizeof(celula));
	nova -> valor = v;
	nova -> prox = cabeca -> prox;
	cabeca -> prox = nova;
}

int pop(celula *cabeca){
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
	celula *pilha = cria_pilha();
	push(pilha, 1);
	push(pilha, 2);
	push(pilha, 3);
	push(pilha, 4);
	push(pilha, 5);
	imprime(pilha);
	printf("\n");
	pop(pilha);
	pop(pilha);
	pop(pilha);
	imprime(pilha);
	printf("\n");
	push(pilha, 8);
	push(pilha, 9);
	push(pilha, 10);
	imprime(pilha);
	
}