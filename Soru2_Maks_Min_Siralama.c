#include <stdio.h>

void maxMinSiralama(int arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    int tempArr[n];
    int sol = 0;          
    int sag = n - 1;      
    int siraBuyukte = 1; 

    for (int i = 0; i < n; i++) {
        if (siraBuyukte == 1) {
            tempArr[i] = arr[sag];
            sag--;
        } else {
            tempArr[i] = arr[sol];
            sol++;
        }
        siraBuyukte = !siraBuyukte; 
    }

    printf("Maks-Min Siralanmis Dizi: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", tempArr[i]);
    }
    printf("\n");
}

int main() {
    int dizi[] = {60, 80, 3, 9, 57, 11};
    int boyut = sizeof(dizi) / sizeof(dizi[0]);

    printf("Orijinal Dizi: 60 80 3 9 57 11\n");
    maxMinSiralama(dizi, boyut);

    return 0;
}
