 #include <stdio.h>
#include <stdlib.h>

void Bolha(int v[], int n)
{
    int j, i, aux, troca;
    for(j=n-1; j> 0; j--)
    {
        troca=0;
        for (i=0; i<j; i++)
        {
            if(v[i]>v[i+1])
            {
                troca = 1;
                aux = v[i];
                v[i]=v[i+1];
                v[i+1]=aux;
            }
        }
        if (!troca) break;
    }
}
void selecao(int v[], int n)
{
    int i,j, menor, aux;
    for(i=0; i< n-1; i++)
    {
        menor = i;
        for(j=i+1; j<n; j++)
        {
            if(v[j] < v[menor])
                menor =j;
        }
        aux = v[i];
        v[i]= v[menor];
        v[menor]= aux;
    }
}
void Insercao(int v[], int  n, int x)
{
    int i;
    for (i=n-1; n>=0; i--)
    {
        if (v[i] > x) v[i+1] = v[i];
        else break;
    }
    v[i+1] = x;
}

void QuickSort(int v[], int ini, int fim)
{
    int i=ini, j=fim, aux, pivo = ini;
    if (i>j )return;
    while (i < j)
    {
        while (v[i]< v[pivo])i++;
        while (v[j]> v[pivo]) j--;
        if ( i < j)
        {
            aux = v[i];
            v[i] = v[j];
            v[j] = aux;
        }
        if ( i == pivo) pivo = j;
        else if ( j == pivo) pivo = i;
    }
    QuickSort(v, ini, pivo -1);
    QuickSort(v, pivo +1, fim) ;

}
void contagem (int v[], int n)// Countining Sort
{
    int a[50]= {0};
    int i, j, p;
    for(i=0; i<n ; i++)
    {
        a[v[i]]++;
        p=0;
    }
    for (i=0; i< 50; i++)
    {
        for (j=0; j<a[i]; j++) v[p++]=i;
    }
}
int main()
{
    int n = 15;
    int v[20]= {27,10,5,18,19,21,34,15,17,8,14,22,16,9,10};
    //Bolha(v, 14);
    //QuickSort(v, 0, 13);
    //Insercao(v, 14, 90);
    //n++;
    contagem(v, n);
    for(int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    return 0;
}

