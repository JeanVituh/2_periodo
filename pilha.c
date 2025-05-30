#include <stdio.h>
#include <stdlib.h>
#define TAM 50

struct pilha
{
    int N;
    float VET[TAM];
};
typedef struct pilha Pilha;

// PROTÓTIPOS
Pilha* PilhaCriar();
void PilhaPush(Pilha* P, float v);
float PilhaPop(Pilha* P);
int PilhaVazia(Pilha* P);
void PilhaLibera(Pilha* P);
void transfere(Pilha* P1, Pilha* P2);

Pilha* PilhaCriar()
{
    Pilha* P = (Pilha*)malloc(sizeof(Pilha));
    P->N = 0;
    return P;
}

void PilhaPush(Pilha* P, float v)
{
    if (P->N == TAM)
    {
        printf("Pilha cheia!\n");
        exit(1);
    }
    P->VET[P->N] = v;
    P->N++;
}

float PilhaPop(Pilha* P)
{
    if (PilhaVazia(P))
    {
        printf("Pilha vazia!\n");
        exit(1);
    }
    float v = P->VET[P->N - 1];
    P->N--;
    return v;
}

int PilhaVazia(Pilha* P)
{
    return P->N == 0;
}

void PilhaLibera(Pilha* P)
{
    free(P);
}

void transfere(Pilha* P1, Pilha* P2)
{
    while (!PilhaVazia(P1))
    {
        float v = PilhaPop(P1);
        PilhaPush(P2, v);
    }
}

int main()
{
    Pilha* P1 = PilhaCriar();
    Pilha* P2 = PilhaCriar();
    PilhaPush(P1, 10);
    PilhaPush(P1, 20);
    PilhaPush(P1, 30);
    PilhaPush(P1, 40);
    PilhaPush(P1, 50);
    PilhaPush(P2, 60);
    PilhaPush(P2, 70);
    PilhaPush(P2, 80);
    PilhaPush(P2, 90);
    PilhaPush(P2, 100);

    float v;
    while (!PilhaVazia(P1))
    {
        v = PilhaPop(P1);
        printf("%.2f\n", v);
    }

    printf("\n");
    PilhaPush(P1, 10);
    PilhaPush(P1, 20);
    PilhaPush(P1, 30);
    PilhaPush(P1, 40);
    PilhaPush(P1, 50);
    transfere(P1, P2);

    while (!PilhaVazia(P2))
    {
        v = PilhaPop(P2);
        printf("%.2f\n", v);
    }

    return 0;
}
