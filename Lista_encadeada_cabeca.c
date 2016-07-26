#include <stdlib.h>
#include <stdio.h>

//definindo ponteiro e valor da célula
typedef struct cel {
	int valor;
	struct cel *prox;
}celula;

//cria uma lista encadeada
celula * crialista(){
	celula *aux = malloc(sizeof(celula));
	aux->prox = NULL;
	return aux;
}

//insere elemento no final da lista, junto com um elemento cabeca
void insere (celula *cabeca, int v){
	celula *aux, *nova;
	nova = malloc(sizeof(celula));	
	nova -> valor = v;
	nova -> prox = NULL;
	aux = cabeca;
	while(aux->prox != NULL){
		aux=aux->prox;
	}
	aux->prox = nova;
}

/* recursiva
void imprime (celula *ler){
	celula *p;
	if (ler !=NULL){
		printf("%d \n", ler->valor);
		imprime (ler-prox);
	}
} */

//iterativa
void imprime (celula *ler){
	celula *p;
	for (p = ler->prox; p != NULL; p = p->prox){
		printf("%d \n", p->valor);
	}
}

//busca um elemento e remove da lista
void remove_ (celula *le, int y){
	celula *p, *q;
	p = le;
	q = le->prox;
	while (q != NULL && q-> valor != y){
		p = q;
		q = q->prox;
	}
	if (q != NULL){
		p->prox = q->prox;
		free(q);
	}
}

//remove o ultimo elemento da lista, independente do valor
void removeUltimo (celula *lista){
	celula *ultimo = lista->prox; //ultimo elemento recebe o endereco do penultimo
	celula *penultimo = lista; 
	
	//encontrando o endereco do penultimo e fazendo com que vire ultimo
	while(ultimo->prox != NULL){
		penultimo = ultimo;
		ultimo = ultimo->prox;
	}
	
	//tornando penultimo como ultimo da endereco da lista
	penultimo->prox = NULL;
	return ultimo;
}

int main(){
	celula *lista = crialista();
	insere(lista, 3);
	insere(lista, 21);
	insere(lista, 2);
	insere(lista, 12);
	insere(lista, 21);
	insere(lista, 333);
	insere(lista, 44);
	insere(lista, 678);
	insere(lista, 214);
	insere(lista, 10000);
	imprime(lista);
	printf("\n");
	remove_(lista, 21);
	imprime(lista);
	printf("\n");
	removeUltimo(lista);
	imprime(lista);
}