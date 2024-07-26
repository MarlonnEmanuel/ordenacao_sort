#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void ler_Array(const char *nomeArquivo, int **arr, int *tamanho) {
    FILE *file = fopen(nomeArquivo, "r");
    if (!file) {
        fprintf(stderr, "Não foi possível abrir o arquivo %s\n", nomeArquivo);
        exit(EXIT_FAILURE);
    }

    if (fscanf(file, "%d", tamanho) != 1) {
        fprintf(stderr, "Falha ao ler o tamanho do arquivo %s\n", nomeArquivo);
        exit(EXIT_FAILURE);
    }

    *arr = (int *)malloc(*tamanho * sizeof(int));
    if (*arr == NULL) {
        fprintf(stderr, "Erro de alocação de memória\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < *tamanho; i++) {
        if (fscanf(file, "%d", &(*arr)[i]) != 1) {
            fprintf(stderr, "Falha ao ler elemento do arquivo %s\n", nomeArquivo);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
}

void print_Array(int arr[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void insertionSort(int arr[], int tamanho) {
    for (int i = 1; i < tamanho; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void testarAlgoritmo(void (*ordenacao_sort)(int*, int), const char *nomeAlgoritmo, const char *nomeArquivo) {
    int *arr;
    int tamanho;
    ler_Array(nomeArquivo, &arr, &tamanho);

    clock_t inicio, fim;
    double tempo;

    inicio = clock();
    fim = clock();

    ordenacao_sort(arr, tamanho);

    tempo = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tempo usado pelo %s no arquivo %s: %f segundos\n", nomeAlgoritmo, nomeArquivo, tempo);
    printf("Array ordenado usando %s:\n", nomeAlgoritmo);
    print_Array(arr, tamanho);

    free(arr);
}

int main() {
    const char *nomeArquivo = "num.1000.1.in";

    testarAlgoritmo(selectionSort, "Selection Sort", nomeArquivo);
    testarAlgoritmo(insertionSort, "Insertion Sort", nomeArquivo);

    return 0;
}
