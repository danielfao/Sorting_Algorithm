#include<stdio.h>
#include<malloc.h>

typedef enum { FALSE ,TRUE } bool;
struct noArvore
{
    int info;
    int balance;
    struct  noArvore *esquerda;
    struct  noArvore *direita;
};

struct noArvore* insere(int , struct noArvore *, int *);
struct noArvore* procura(struct noArvore *,int);

struct noArvore* procura(struct noArvore *ptr,int info)
{
    if(ptr!=NULL)
        if(info < ptr->info)
            ptr=procura(ptr->esquerda,info);
        else if( info > ptr->info)
            ptr=procura(ptr->direita,info);
    return(ptr);
}/*Fim da procura()*/

struct noArvore *insere (int info, struct noArvore *pptr, int *ht_inc)
{
    struct noArvore *aptr;
    struct noArvore *bptr;

    if(pptr==NULL)
    {
        pptr = (struct noArvore *) malloc(sizeof(struct noArvore));
        pptr->info = info;
        pptr->esquerda = NULL;
        pptr->direita = NULL;
        pptr->balance = 0;
        *ht_inc = TRUE;
        return (pptr);
    }

    if(info < pptr->info)
    {
        pptr->esquerda = insere(info, pptr->esquerda, ht_inc);
        if(*ht_inc==TRUE)
        {
            switch(pptr->balance)
            {
            case -1: /* Desbalanceado a direita */
                pptr->balance = 0;
                *ht_inc = FALSE;
                break;
            case 0: /* Balanceado */
                pptr->balance = 1;
                break;
            case 1: /* desbalanceado a esquerda */
                aptr = pptr->esquerda;
                if(aptr->balance == 1)
                {
                    printf("Esquerda com rotacao a esquerda\n");
                    pptr->esquerda= aptr->direita;
                    aptr->direita = pptr;
                    pptr->balance = 0;
                    aptr->balance=0;
                    pptr = aptr;
                }
                else
                {
                    printf("Esquerda com rotacao a direita\n");
                    bptr = aptr->direita;
                    aptr->direita = bptr->esquerda;
                    bptr->esquerda = aptr;
                    pptr->esquerda = bptr->direita;
                    bptr->direita = pptr;

                    if(bptr->balance == 1 )
                        pptr->balance = -1;
                    else
                        pptr->balance = 0;
                    if(bptr->balance == -1)
                        aptr->balance = 1;
                    else
                        aptr->balance = 0;
                    bptr->balance=0;
                    pptr=bptr;
                }
                *ht_inc = FALSE;
            }
        }
    }

    if(info > pptr->info)
    {
        pptr->direita = insere(info, pptr->direita, ht_inc);
        if(*ht_inc==TRUE)
        {
            switch(pptr->balance)
            {
            case 1: /* Desbalanceado a esquerda */
                pptr->balance = 0;
                *ht_inc = FALSE;
                break;
            case 0: /* Balanceado */
                pptr->balance = -1;
                break;
            case -1: /* Desbalanceado a direita */
                aptr = pptr->direita;
                if(aptr->balance == -1)
                {
                    printf("Direita com rotacao a Direita\n");
                    pptr->direita= aptr->esquerda;
                    aptr->esquerda = pptr;
                    pptr->balance = 0;
                    aptr->balance= 0;
                    pptr = aptr;
                }
                else
                {
                    printf("Direita com rotacao a esquerda\n");
                    bptr = aptr->esquerda;
                    aptr->esquerda = bptr->direita;
                    bptr->direita = aptr;
                    pptr->direita = bptr->esquerda;
                    bptr->esquerda = pptr;

                    if(bptr->balance == -1)
                        pptr->balance = 1;
                    else
                        pptr->balance = 0;
                    if(bptr->balance == 1)
                        aptr->balance = -1;
                    else
                        aptr->balance = 0;
                    bptr->balance=0;
                    pptr = bptr;
                }
                *ht_inc = FALSE;
            }
        }
    }

    return(pptr);
}/*Fim do insere()*/

mostrar(struct noArvore *ptr,int nivel)
{
    int i;
    if ( ptr!=NULL )
    {
        mostrar(ptr->direita, nivel+1);
        printf("\n");
        for (i = 0; i < nivel; i++)
            printf("    ");
        printf("%d", ptr->info);
        mostrar(ptr->esquerda, nivel+1);
    }
}/*Fim do mostrar()*/

ordenado(struct noArvore *ptr)
{
    if(ptr!=NULL)
    {
        ordenado(ptr->esquerda);
        printf("%d  ",ptr->info);
        ordenado(ptr->direita);
    }
}/*Fim do ordenado()*/


main()
{
    bool ht_inc;
    int info ;
    int escolha;
    struct noArvore *raiz = (struct noArvore *)malloc(sizeof(struct noArvore));
    raiz =  NULL;

    while(1)
    {
    	printf("Arvore AVL\n");
    	printf("Menu: \n");
        printf("1.Insere\n");
        printf("2.Mostrar\n");
        printf("3.Sair\n");
        printf("Entre com sua escolha: ");
        scanf("%d",&escolha);
        switch(escolha)
        {
        case 1:
            printf("Entre com o numero a ser inserido: ");
            scanf("%d", &info);
            if( procura(raiz,info) == NULL )
                raiz = insere(info, raiz, &ht_inc);
            else
                printf("\nValor duplicado ignorado.\n");
            break;
        case 2:
            if(raiz==NULL)
            {
                printf("\nArvore vazia.\n");
                continue;
            }
            printf("Arvore balanceada: \n");
            mostrar(raiz, 1);
            printf("\n\n");
            printf("Em ordem: ");
            ordenado(raiz);
            printf("\n");
            break;
        case 3:
            exit(1);
        default:
            printf("Escolha invalida\n");
        }/*Final do menu*/
    }/*Final do enquanto*/
}/*Fim do menu()*/

