#include <stdio.h>
#include <stdlib.h>

struct arv {
    int Info;
    struct arv *esq, *dir;
};
typedef struct arv Arv;

// Protótipos das funções
Arv* NovoNo(int Info, Arv *esq, Arv *dir);
void ArvImprimir(Arv *No, int Nivel);
int ArvSoma(Arv *No);
int ContaImpar(Arv *No);
int ContaFolha(Arv *No);

// Funções (mantidas exatamente como você escreveu)
Arv* NovoNo(int Info, Arv *esq, Arv *dir)
{
    Arv *Novo = (Arv*)malloc(sizeof(Arv));
    Novo->Info = Info;
    Novo->esq = esq;
    Novo->dir = dir;
    return Novo;
}

void ArvImprimir(Arv *No, int Nivel)
{
    if(No == NULL)return;
    /* printf("%d\n", No->Info);
     ArvImprimir(No -> esq);
     ArvImprimir(No -> dir);*/
    ArvImprimir(No -> dir, Nivel +1);
    printf("%*d\n", Nivel *5, No -> Info);
    ArvImprimir(No -> esq, Nivel +1);
}
int ArvSoma (Arv *No)
{
    if(No == NULL)return 0;
    return No->Info + ArvSoma(No->dir) + ArvSoma(No->esq);
}
int ContaImpar(Arv *No)
{
    if (No == NULL)
        return 0;
    int cont = 0;

    if (No -> Info % 2 != 0)cont = 1;
    cont += ContaImpar(No->esq)+ ContaImpar(No->dir);

    return cont;             // devolve a soma total
}
int ContaFolha (Arv *No)
{
    if (No == NULL)
        return 0;
    int folha = 0;
    if (No -> esq == NULL && No -> dir == NULL)
        folha = 1;
    folha += ContaFolha(No -> esq)+ ContaFolha(No -> dir);
    return folha;
}


int main()
{
    //int nivel;
    Arv *a9 =NovoNo(44, NULL, NULL);
    Arv *a8=NovoNo(11, NULL, NULL);
    Arv *a7=NovoNo(7, NULL, NULL);
    Arv *a6=NovoNo(27, a8, a9);
    Arv *a5=NovoNo(50, a7, NULL);
    Arv *a4=NovoNo(9, NULL, NULL);
    Arv *a3=NovoNo(19, a6, NULL);
    Arv *a2=NovoNo(10, a4, a5);
    Arv *a1=NovoNo(90, a2, a3);
    ArvImprimir(a1, 0);
    printf("\n");
    printf("A soma e %d\n", ArvSoma(a1));
    printf("Os impares sao %d\n", ContaImpar(a1));
    printf("O numero de folhas e %d\n", ContaFolha(a1));

    return 0;
}
