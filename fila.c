#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da lista
struct lista {
    int info;
    struct lista* prox;
};

// Definição da estrutura da fila
struct fila {
    struct lista* ini;
    struct lista* fim;
};
typedef struct fila Fila;

// === Protótipos das funções ===
Fila* FilaCriar();
void FilaInserir(Fila* f, float v);
float FilaRetirar(Fila* f);
int FilaVazia(Fila* f);
void FilaLiberar(Fila* f);
void FilaTransfere(Fila* F1, Fila* F2);

// === Implementação das funções ===
Fila* FilaCriar() {
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

void FilaInserir(Fila* f, float v) {
    struct lista* Novo;
    Novo = (struct lista*)malloc(sizeof(struct lista));
    Novo->info = v;
    Novo->prox = NULL;
    if (f->fim != NULL)
        f->fim->prox = Novo;
    else
        f->ini = Novo;
    f->fim = Novo;
}

float FilaRetirar(Fila* f) {
    struct lista* t;
    float v;
    if (FilaVazia(f)) {
        printf("fila Vazia!\n");
        exit(1);
    }
    v = f->ini->info;
    t = f->ini->prox;
    free(f->ini);
    f->ini = t;
    if (f->ini == NULL)
        f->fim = NULL;
    return v;
}

int FilaVazia(Fila* f) {
    return f->ini == NULL;
}

void FilaLiberar(Fila* f) {
    struct lista* t;
    while (f->ini != NULL) {
        t = f->ini->prox;
        free(f->ini);
        f->ini = t;
    }
    free(f);
}

void FilaTransfere(Fila* F1, Fila* F2) {
    while (!FilaVazia(F1)) {
        float v = FilaRetirar(F1);
        FilaInserir(F2, v);
    }
}

// === Função principal ===
int main() {
    Fila* F1 = FilaCriar();
    Fila* F2 = FilaCriar();

    FilaInserir(F1, 10);
    FilaInserir(F1, 20);
    FilaInserir(F1, 30);
    FilaInserir(F1, 40);
    FilaInserir(F1, 50);
    FilaInserir(F2, 60);
    FilaInserir(F2, 70);
    FilaInserir(F2, 80);
    FilaInserir(F2, 90);
    FilaInserir(F2, 100);

    float v;
    while (!FilaVazia(F1)) {
        v = FilaRetirar(F1);
        printf("%.2f\n", v);
    }

    FilaInserir(F1, 10);
    FilaInserir(F1, 20);
    FilaInserir(F1, 30);
    FilaInserir(F1, 40);
    FilaInserir(F1, 50);
    FilaTransfere(F1, F2);

    while (!FilaVazia(F2)) {
        v = FilaRetirar(F2);
        printf("%.2f\n", v);
    }

    FilaLiberar(F1);
    FilaLiberar(F2);

    return 0;
}
