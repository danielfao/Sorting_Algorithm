#include <stdio.h>
#include <time.h>

void duplica(int a[], int v[], int max){
    int i;
    for(i=0;i<max;i++){
        a[i]=v[i];
    }
}

void imprime(int v[], int max){
    int i;
    for(i=0;i<max;i++)
        printf("%2d ", v[i]);
    printf("\n");
}

void troca(int* a, int* b){
    int t;
    t=*a;
    *a=*b;
    *b=t;
}

void mergeSort(int v[], int esq, int dir){
	int meio;
	
	if(dir>esq){
		meio = (dir+esq)/2;
		mergeSort(v, esq, meio);
		mergeSort(v, meio+1, dir);
		merge(v, esq, meio, dir);
	}
}

void merge(int vetor[], int inicio, int meio, int fim){
	int tamanho = fim - inicio + 1;
	int i, j, k, posicao; 
	int temp[tamanho];
	
	for (i=inicio; i<=fim; i++) {
		temp[i] = vetor[i]; 
	}
	for (i=inicio, j=meio+1, posicao=inicio; (i <= meio) && (j <= fim); posicao++) {
		if(temp[i]<temp[j]){
			vetor[posicao] = temp[i];
			i ++;
		}
		else{
			vetor[posicao] = temp[j];
			j++;
		} 
	}    
	if(i == meio+1){
		for(k=j; k<=fim; k++){
			vetor[posicao] = temp[k];
			posicao++;
		}    
		}
		else {
			for(k=i; k<=meio; k++){
			vetor[posicao] = temp[k];
			posicao++;
			}    
		}
}


void bubble(int a[], int max){
    int i, j;
    unsigned long countC=0, countT=0;

    for(i=0;i<max;i++){
        for(j=0;j<max-i-1;j++){
                countC++;
            if(a[j]>a[j+1]){
                countT+=3;
                troca(&a[j], &a[j+1]);
            }
        }
    }
    printf("Foram feitas %3d comparacoes e %3d trocas\n",countC,countT);
}

void select(int a[], int max){
    int i, j, p;
    unsigned long countC=0, countT=0;

    for(i=0;i<max;i++){
        p=i;    
		countT++;
        for(j=i;j<max;j++){
            countC++;
            if(a[j]<a[p]){
                p=j; 
				countT++;
            }
        }
        countT+=3;
        troca(&a[i], &a[p]);
    }
    printf("Foram Feitas %3d comparacoes e %3d trocas\n",countC,countT);
}

void insertion(int a[], int max){
    int i,j,x;
    int *t;
    unsigned long countC=0, countT=0;

    t=malloc(sizeof(t)*max+1);
    for(i=0;i<max;i++)
        t[i+1]=a[i];

    for(i=2;i<max+1;i++){
        countT+=3;
        x=t[i];
        j=i-1;
        t[0]=x;
        countC++;
        while(t[j]>x){
            countC++;
            countT+=2;
            t[j+1]=t[j];
            j--;
        }
        countT++;
        t[j+1]=x;
    }
    for(i=0;i<max;i++)
        a[i]=t[i+1];

    printf("Foram feitas %3d comparacoes e %3d trocas\n",countC,countT);
}

int partition(int vec[], int left, int rigth, int c[]){
    int i,j;
    i=left;
    c[0]++;
    for(j=left+1;j<=rigth;j++){
            c[0]+=2;
        if(vec[j]<vec[left]){
            c[1]+=3;
            i++;
            troca(&vec[i], &vec[j]);
        }
    }
    c[1]++;
    troca(&vec[left],&vec[i]);
    return i;
}

void quicksort(int vec[], int left, int right, int c[]){
    int r;
    c[0]++;
    if(right>left){
        r=partition(vec, left, right, c);
        quicksort(vec, left, r-1, c);
        quicksort(vec,r+1,right, c);
    }
}

int main(){
    char op;
    int *v, *a;
    srand((unsigned)time(NULL));
    do{
    system("cls");
    int max;
    printf("Digite o tamanho do vetor: ");
    scanf("%d",&max);

    v=malloc(sizeof(int)*max);
    a=malloc(sizeof(int)*max);

    int i;
    for(i=0;i<max;i++){
        v[i]=rand()%100;
    }
   
    duplica(a,v,max);
    printf("\nBubble: ");
    bubble(a,max);

    duplica(a,v,max);
    printf("\nSelect: ");
    select(a,max);

    duplica(a,v,max);
    printf("\nInsert: ");
    insertion(a,max);
	
    duplica(a,v,max);
    unsigned long c[2]={0,0};
    printf("\nQuickSort: ");
    quicksort(a,0,max-1,c);
    printf("Foram feitas %3d comparacoes e %3d trocas\n",c[0],c[1]);

    printf("\nGostaria de fazer outro teste? [s/n]\n");
    fflush(stdin);
    op=getchar();
    }while(op=='s');

}

