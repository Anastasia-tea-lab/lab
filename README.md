#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Пузырек
void bubbleSort(int arr[], int n) {
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Вставки
void insertionSort(int arr[], int n) {
    int i, j, x;

    for (i = 1; i < n; i++) {
        x = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > x) {
            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = x;
    }
}

// Слияние
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Сортировка слиянием
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int sizes[] = {10, 1000, 10000, 100000};
    int original[100000], arr[100000];
    int i, j, n;

    clock_t start, end;
    double t1, t2, t3;

    srand(time(NULL));

    printf("Размер | Пузырек | Вставки | Слияние\n");

    for (i = 0; i < 4; i++) {
        n = sizes[i];

        for (j = 0; j < n; j++)
            original[j] = rand() % 1000;

        for (j = 0; j < n; j++)
            arr[j] = original[j];

        start = clock();
        bubbleSort(arr, n);
        end = clock();
        t1 = end - start;

        for (j = 0; j < n; j++)
            arr[j] = original[j];

        start = clock();
        insertionSort(arr, n);
        end = clock();
        t2 = end - start;

        for (j = 0; j < n; j++)
            arr[j] = original[j];

        start = clock();
        mergeSort(arr, 0, n - 1);
        end = clock();
        t3 = end - start;

        printf("%d | %.0f | %.0f | %.0f\n", n, t1, t2, t3);
    }

    return 0;
}
