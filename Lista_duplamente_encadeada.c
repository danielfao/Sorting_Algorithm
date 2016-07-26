#include <stdio.h>
#include <stdlib.h>

//Lista Duplamente Encadeada

//Criando dois ponteiros, um para o próximo endereço e outro para o anterior
typedef struct c{
	int valor;
	struct c *prox;
	struct c *ant;
} celula;

//Criando ponteiros para o inicio e fim de lista
typedef struct {
	celula *inicio;
	celula *fim;
} lista;

void insere (lista *lista, int v){
	celula *nova;
	
	nova = malloc(sizeof(celula));
	nova->valor = v;
	nova->prox = NULL;
	
	if (lista->inicio == NULL){
		nova->ant = NULL;
		lista->inicio = nova;
		lista->fim = nova;
	} else {
		nova->ant = lista->fim;
		lista->fim->prox = nova;
		lista->fim = nova;
	}
}

lista * crialista() {
	lista *aux = malloc(sizeof(lista));
	aux->inicio = NULL;
	aux->fim = NULL;
	return aux;
}

void imprime(lista *lista){
	celula *aux;
	aux = lista->inicio;
	
	while(aux != NULL){
		printf("%d", aux->valor);
		aux = aux->prox;
	}
}

void remover(lista *lista, int v){
	
}

void remover_ultimo(lista *lista){
	celula *aux;
	
	if (lista->fim != NULL){
		if(lista->fim->ant != NULL){
			aux = lista->fim->ant;
			aux->prox = NULL;
			free(lista->fim);
			lista->fim = aux;
		} else {
			free(lista->fim);
			lista->inicio = NULL;
			lista->fim = NULL;
		}
	}
}

int main(){
	lista *lista = crialista();
	insere(lista, 1);
	insere(lista, 2);
	insere(lista, 3);
	insere(lista, 4);
	imprime(lista);
	printf("\n");
	remover_ultimo(lista);
	printf("\n");
	imprime(lista);
}