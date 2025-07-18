#include <stdio.h>

void insertionSort(int vetor[], int n) {
    for (int i = 1; i < n; i++) {
        int chave = vetor[i];
        int j = i - 1;

        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j--;
        }

        vetor[j + 1] = chave;
    }
}

int main() {
    int vetor[] = {5, 2, 8, 1, 9};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("===== ANTES =====\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    insertionSort(vetor, tamanho);

    printf("===== DEPOIS =====\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
