#include <stdio.h>
#include "lista.h"

void imprimirLista(Lista *l) {
    printf("Lista: ");
    for (int i = 1; i <= l->tamanho; i++) {
        int val;
        obterElemento(l, i, &val);
        printf("%d ", val);
    }
    printf("\n");
}

int main() {
    Lista l;
    criarLista(&l);

    printf("A lista esta vazia? %s\n", listaVazia(&l) ? "Sim" : "Nao");

    inserirElemento(&l, 1, 10);
    inserirElemento(&l, 2, 20);
    inserirElemento(&l, 2, 15);
    inserirElemento(&l, 4, 30);
    imprimirLista(&l);

    int val;
    obterElemento(&l, 3, &val);
    printf("Elemento na posicao 3: %d\n", val);

    modificarElemento(&l, 3, 25);
    imprimirLista(&l);

    removerElemento(&l, 2);
    imprimirLista(&l);

    printf("Tamanho da lista: %d\n", tamanhoLista(&l));
    printf("A lista esta cheia? %s\n", listaCheia(&l) ? "Sim" : "Nao");

    return 0;
}
