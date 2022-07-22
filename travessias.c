#include <stdio.h>
#include <stdlib.h>

typedef struct Arvore{
int chave;
int fb;
struct Arvore *dir;
struct Arvore *esq;

}arvore;

void insere(arvore **raiz,int valor)
{
    if(*raiz==NULL)
    {
        *raiz=(arvore *)malloc(sizeof(arvore));
        if(*raiz==NULL)exit(1);
        (*raiz)->dir=NULL;
        (*raiz)->esq=NULL;
        (*raiz)->chave=valor;
        (*raiz)->fb=0;

    }
    else
    if (valor > (*raiz)->chave)
    {
        (*raiz)->fb=(*raiz)->fb+1;
        insere(&(*raiz)->dir,valor);
    }
    if(valor < (*raiz)->chave)
    {
        (*raiz)->fb=(*raiz)->fb-1;
        insere(&(*raiz)->esq,valor);
    }

}

void imprimepreordem(arvore *raiz)
{
    if(raiz!=NULL)
    {
        printf("%d %d\n",raiz->chave,raiz->fb);
        imprimepreordem(raiz->esq);
        imprimepreordem(raiz->dir);
    }



}
void imprimeposordem(arvore *raiz)
{
    if(raiz!=NULL)
    {
        imprimeposordem(raiz->esq);
        imprimeposordem(raiz->dir);
        printf("%d %d\n",raiz->chave,raiz->fb);
    }

}

void imprimeordem(arvore *raiz)
{
    if(raiz!=NULL)
    {
        imprimeordem(raiz->esq);
        printf("%d %d\n",raiz->chave,raiz->fb);
        imprimeordem(raiz->dir);


    }


}




int main()
{
    arvore *raiz=NULL;
    int i,n,v;
    printf("Numero de nos da arvore:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&v);
        insere(&raiz,v);

    }
    imprimepreordem(raiz);
    imprimeordem(raiz);
    imprimeposordem(raiz);






}