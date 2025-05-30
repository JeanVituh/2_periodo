#include <stdio.h>
#include <stdlib.h>
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

int BuscaBinaria (int VET[], int n, int v)// (O log n) deve estar ordenado
{
    int ini = 0, fim = n-1, meio;
    while(ini<=fim)
    {
        meio = (ini + fim)/2;
        if(v<VET[meio])fim = meio-1;
        else if(v>VET[meio])ini = meio +1;
        else return meio;
        for(int j=ini;j<=fim;j++){
            printf("%d\t", VET[j]);
        }
        printf("\n");
    }
    return -1;
}


int Busca (int VET[], int n, int v) // SEQUENCIAL 1 POR 1 (On)
{
    for (int i=0; i< n; i++)
    {
        if (VET[i]== v) return i;
    }
    return -1;
}

int main()
{
    int V[]= {15,20,5,10,7,2,1,4,3,12,30,19,13};
    int v,p;
    QuickSort(V,0,12);
    printf("digite um numero para procurar: ");
    scanf("%d", &v);
    //p = Busca(V,13,v);
    p = BuscaBinaria(V,13,v);
    if(p<0)
        printf("nao encontrado!\n");
    else printf ("encontrado em %d!\n", p);
    return 0;
}
