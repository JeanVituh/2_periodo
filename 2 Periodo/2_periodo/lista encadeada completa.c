#include <stdio.h>
#include <stdlib.h>
struct lista
{
    int info;
    struct lista* prox;
};
typedef struct lista Lista;
Lista* ListaCriar()
{
    return NULL;
}

Lista* ListaInserir(Lista* l, int v)
{
    Lista* Novo=(Lista*)malloc(sizeof(Lista));
    Novo -> info = v;
    Novo -> prox = l;
    return Novo;
}

void ListaImprimir(Lista *l)
{
    for(Lista* p=l ; p!= NULL; p=p->prox)
    {
        printf("%d\n", p->info);
    }
}

Lista* Listaexcluir(Lista *l, int v)
{
    Lista* p, *ant = NULL;
    for(p=l; p!= NULL; p=p-> prox)
    {
        if (p->info == v)break;
        ant = p;
    }
    if(p== NULL)return l;
    if (ant != NULL)
        ant -> prox= p->prox;
    else
        l=p->prox;
    free(p);
    return l;
}
Lista* ListaInserirordenado(Lista* l, int v)
{
    Lista* p, *ant= 0;
    for(p=l; p != NULL; p = p-> prox)
    {
        if (p-> info > v) break;
        ant = p;
    }
    Lista* Novo= (Lista*)malloc (sizeof(Lista));
    Novo -> info = v;
    Novo -> prox = p;

    if (ant!= NULL) ant -> prox =  Novo;
    else l = Novo;
                 return l;
}

Lista* ListaInserirAntes(Lista* l, int v, int n)
{
    Lista* p, *ant=NULL;
    for(p=l; p != NULL; p = p-> prox)
    {
        if (p-> info == n) break;
        ant = p;


    }
    Lista* Novo= (Lista*)malloc (sizeof(Lista));
    Novo -> info = v;
    Novo -> prox = p;

    if (ant!= NULL) ant -> prox =  Novo;
    else l = Novo;
    return l;
}
Lista* ListaBuscar(Lista *l, int v)
{
    Lista* p;

    for (p=l; p!=NULL; p=p->prox)
    {
        if(p->info == v)
            return p;
    }

    return NULL;
}

int main()
{
    //int buscar=0;
    Lista* l1=ListaCriar();
    l1= ListaInserir(l1,40);
    l1= ListaInserir(l1,30);
    l1= ListaInserir(l1,20);
    l1= ListaInserir(l1,10);
    l1= Listaexcluir(l1,20);
    //ListaImprimir(l1);
    /*printf ("digite um valor para buscar:");
    scanf("%d", &buscar);
    if (ListaBuscar(l1, buscar)==NULL)
    {
        printf("nao encontrado!\n");
    }
    else
    {
        printf("encontrado!\n");
        printf ("O endereço encontrado e %p", ListaBuscar(l1, buscar));

    }*/
    int v, n;
    printf ("digite o valor para inserir: ");
    scanf("%d", &v);
    printf ("quer inserir antes de qual valor? ");
    scanf("%d", &n);
    ListaInserirAntes(l1, v, n);


     l1=ListaInserirordenado(l1, 20);
     l1=ListaInserirordenado(l1, 70);
     l1=ListaInserirordenado(l1, 5);
     ListaImprimir(l1);



    return 0;
}

