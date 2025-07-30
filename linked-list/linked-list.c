#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
    int dado;
    struct NO *prox;
} NO;

typedef struct {
    NO *inicio;
    int tamanho;
} LISTA;

void criarListaVazia(LISTA *l) {
    l->inicio = NULL;
    l->tamanho = 0;
}

int verificarVazia(LISTA *l) {
    return l->tamanho == 0;
}

int tamanhoLista(LISTA *l) {
    return l->tamanho;
}

int obterElemento(LISTA *l, int pos, int *valor) {
    if (pos < 1 || pos > l->tamanho) return 0;
    
    NO *atual = l->inicio;
    for (int i = 1; i < pos; i++) {
        atual = atual->prox;
    }
    *valor = atual->dado;
    return 1;
}

int modificarElemento(LISTA *l, int pos, int novoValor) {
    if (pos < 1 || pos > l->tamanho) return 0;

    NO *atual = l->inicio;
    for (int i = 1; i < pos; i++) {
        atual = atual->prox;
    }
    atual->dado = novoValor;
    return 1;
}

int inserirElemento(LISTA *l, int valor, int pos) {
    if (pos < 1 || pos > l->tamanho + 1) return 0;

    NO *novo = (NO *)malloc(sizeof(NO));
    novo->dado = valor;

    if (pos == 1) {
        novo->prox = l->inicio;
        l->inicio = novo;
    } else {
        NO *anterior = l->inicio;
        for (int i = 1; i < pos - 1; i++) {
            anterior = anterior->prox;
        }
        novo->prox = anterior->prox;
        anterior->prox = novo;
    }

    l->tamanho++;
    return 1;
}

int removerElemento(LISTA *l, int pos) {
    if (pos < 1 || pos > l->tamanho) return 0;

    NO *remover;
    if (pos == 1) {
        remover = l->inicio;
        l->inicio = remover->prox;
    } else {
        NO *anterior = l->inicio;
        for (int i = 1; i < pos - 1; i++) {
            anterior = anterior->prox;
        }
        remover = anterior->prox;
        anterior->prox = remover->prox;
    }

    free(remover);
    l->tamanho--;
    return 1;
}

void imprimirLista(LISTA *l) {
    NO *atual = l->inicio;
    printf("Lista: ");
    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {
    LISTA lista;
    criarListaVazia(&lista);

    printf("Lista criada\n");
    printf("Esta vazia? %s\n", verificarVazia(&lista) ? "Sim" : "Nao");

    inserirElemento(&lista, 10, 1);
    inserirElemento(&lista, 20, 2);
    inserirElemento(&lista, 15, 2);
    imprimirLista(&lista);

    int valor;
    if (obterElemento(&lista, 2, &valor))
        printf("Elemento na posicao 2: %d\n", valor);

    modificarElemento(&lista, 2, 99);
    imprimirLista(&lista);

    removerElemento(&lista, 1);
    imprimirLista(&lista);

    printf("Tamanho da lista: %d\n", tamanhoLista(&lista));

    return 0;
}
