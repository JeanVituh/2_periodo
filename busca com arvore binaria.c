#include <stdio.h>
#include <stdlib.h>

struct abb  // arvore binaria de busca
{
    int Info;
    struct abb *esq, *dir;
};
typedef struct abb Abb;

// Protótipos das funções
Abb* AbbBuscar(Abb* a, int v);
Abb* AbbCriar(int Info, Abb *esq, Abb *dir);
void AbbImprimir(Abb *No, int Nivel);
Abb* AbbInserir(Abb *a, int v);
void QuickSort(int v[], int ini, int fim);
int BuscaBinaria(int VET[], int n, int v);
int Busca(int VET[], int n, int v);

// Implementações
Abb* AbbBuscar(Abb* a, int v) // O(log n)
{
    if (a == NULL) return NULL;

    if (v < a->Info)
        return AbbBuscar(a->esq, v);   // corrigido com return
    else if (v > a->Info)
        return AbbBuscar(a->dir, v);
    else
        return a;
}

Abb* AbbCriar(int Info, Abb *esq, Abb *dir)
{
    Abb *Novo = (Abb*)malloc(sizeof(Abb));
    Novo->Info = Info;
    Novo->esq = esq;
    Novo->dir = dir;
    return Novo;
}

void AbbImprimir(Abb *No, int Nivel)
{
    if (No == NULL) return;
    AbbImprimir(No->dir, Nivel + 1);
    printf("%*d\n", Nivel * 5, No->Info);
    AbbImprimir(No->esq, Nivel + 1);
}

Abb* AbbInserir(Abb *a, int v)
{
    if (a == NULL)
    {
        Abb *Novo = (Abb*)malloc(sizeof(Abb));
        Novo->Info = v;
        Novo->esq = Novo->dir = NULL;
        return Novo;
    }
    if (v < a->Info)
        a->esq = AbbInserir(a->esq, v);
    else if (v > a->Info)
        a->dir = AbbInserir(a->dir, v);
    return a;
}

void QuickSort(int v[], int ini, int fim)
{
    int i = ini, j = fim, aux, pivo = ini;
    if (i > j) return;
    while (i < j)
    {
        while (v[i] < v[pivo]) i++;
        while (v[j] > v[pivo]) j--;
        if (i < j)
        {
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }
        if (i == pivo) pivo = j;
        else if (j == pivo) pivo = i;
    }
    QuickSort(v, ini, pivo - 1);
    QuickSort(v, pivo + 1, fim);
}

int BuscaBinaria(int VET[], int n, int v) // (O log n) deve estar ordenado
{
    int ini = 0, fim = n - 1, meio;
    while (ini <= fim)
    {
        meio = (ini + fim) / 2;
        if (v < VET[meio]) fim = meio - 1;
        else if (v > VET[meio]) ini = meio + 1;
        else return meio;
        for (int j = ini; j <= fim; j++)
        {
            printf("%d\t", VET[j]);
        }
        printf("\n");
    }
    return -1;
}

int Busca(int VET[], int n, int v) // SEQUENCIAL 1 POR 1 (On)
{
    for (int i = 0; i < n; i++)
    {
        if (VET[i] == v) return i;
    }
    return -1;
}

int main()
{
    int v;
    Abb *a1 = AbbCriar(50, NULL, NULL);
    AbbInserir(a1, 25);
    AbbInserir(a1, 62);
    AbbInserir(a1, 22);
    AbbInserir(a1, 29);
    AbbInserir(a1, 55);
    AbbInserir(a1, 52);
    AbbInserir(a1, 60);

    printf("Digite um numero para procurar: ");
    scanf("%d", &v);

    Abb* temp = AbbBuscar(a1, v);
    if (temp != NULL)
        printf("O endereco de %d e: %p\n", temp->Info, (void*)temp);
    else
        printf("Valor %d nao encontrado na arvore.\n", v);

    /*p = Busca(V,13,v);
    p = BuscaBinaria(V,13,v);
    if(p<0)
        printf("Nao encontrado!\n");
    else
        printf ("Encontrado em %d!\n", p);*/

    return 0;
}
