#include <stdio.h>
#include <stdlib.h>

void mergeSort(int v[], int esq, int dir){
	int meio;
	
	if (dir > esq){
		meio = (dir + esq)/2;
		mergeSort(v, esq, meio);
		mergeSort(v, meio+1, dir);
		merge(v, esq, meio, dir);
	}
}

void merge(int v[], int esq, int meio, int dir){
	int temp[];
	int i = esq;
	int j = meio+1;
	int k = 0;
	
	while(i < meio + 1 && j < esq + 1)
	{
		if(i == meio + 1){
			temp[k] = v[j];
			j++;
			k++;
		}
		else if(j == dir + 1){
			temp[k] = v[i];
			i++;
			k++;
		}
		else if(v[i] < v[j]){
			temp[k] = v[i];
			i++;
			k++;
		}
		else
		{
			temp[k] = v[j];
			j++;
			k++;
		}
	}
	for(i = esq; i <= dir; i++){
		v[i] = temp[i - esq];
	}
}

int main(){
	v = {10, 31, 11, 1, 2, 4, 21, 12};
	mergeSort(v, 0, 7);
	printf(v);
}