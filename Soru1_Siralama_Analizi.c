#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 500

// Insertion Sort (Araya Sokma Sıralaması)
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Selection Sort (Seçmeli Sıralama)
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main() {
    int arr1[SIZE], arr2[SIZE];
    clock_t start, end;
    double cpu_time_used_insertion, cpu_time_used_selection;

    // 0-1000 arası rastgele 500 sayı üretip iki diziye de aynı sayıları kopyalıyoruz
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        int num = rand() % 1001;
        arr1[i] = num;
        arr2[i] = num;
    }

    // Insertion Sort Süre Ölçümü
    start = clock();
    insertionSort(arr1, SIZE);
    end = clock();
    cpu_time_used_insertion = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Selection Sort Süre Ölçümü
    start = clock();
    selectionSort(arr2, SIZE);
    end = clock();
    cpu_time_used_selection = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Sonuçları Ekrana Yazdırma
    printf("500 Elemanli Dizi Icin Siralama Sureleri:\n");
    printf("Insertion Sort Suresi: %f saniye\n", cpu_time_used_insertion);
    printf("Selection Sort Suresi: %f saniye\n", cpu_time_used_selection);

    return 0;
}
