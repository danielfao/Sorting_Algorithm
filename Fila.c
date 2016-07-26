/*Fila - FIFO (First In, First Out) - implementação sem percorrer*/

#include <stdlib.h>
#include <stdio.h>

typedef struct cel {
	int valor;
	struct cel *prox;
}celula;

typedef struct{
	celula *inicio;
	celula *fim;
}fila;

celula * cria_fila(){
	celula *aux = malloc(sizeof(celula)); //cabeça
	aux->prox = NULL;
	return aux;
}

void insere (celula *cabeca, int v){
	celula *nova;
	nova = malloc(sizeof(celula));
	nova -> valor = v
}

int main(){
	celula *fila = cria_fila();
	
}