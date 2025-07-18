#include <stdio.h>

void selectionsort(int vetor[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int aux = i;
        for (int j = i + 1; j < n; j++) {
            if (vetor[j] < vetor[aux]) {
                aux = j;
            }
        }
        int temp = vetor[i];
        vetor[i] = vetor[aux];
        vetor[aux] = temp;
    }

}

int main() {
    int vetor[] = {5,2,8,1,9};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("===== ANTES =====\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    };
    printf("\n");

    selectionsort(vetor, tamanho);

    printf("===== DEPOIS =====\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}