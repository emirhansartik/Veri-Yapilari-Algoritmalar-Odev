#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ALFABE_BOYUTU 26


struct TrieDugum {
    struct TrieDugum *cocuklar[ALFABE_BOYUTU];
    bool kelimeSonuMu;
};

struct TrieDugum *yeniDugum(void) {
    struct TrieDugum *pNode = (struct TrieDugum *)malloc(sizeof(struct TrieDugum));
    pNode->kelimeSonuMu = false;
    for (int i = 0; i < ALFABE_BOYUTU; i++)
        pNode->cocuklar[i] = NULL;
    return pNode;
}

void ekle(struct TrieDugum *kok, const char *kelime) {
    struct TrieDugum *gecici = kok;

    for (int i = 0; kelime[i] != '\0'; i++) {
        int indeks = kelime[i] - 'a'; 
        
        if (!gecici->cocuklar[indeks]) {
            gecici->cocuklar[indeks] = yeniDugum();
        }
        gecici = gecici->cocuklar[indeks];
    }
    gecici->kelimeSonuMu = true; 
}

int main() {
    struct TrieDugum *kok = yeniDugum();
    ekle(kok, "veri");
    ekle(kok, "yapi");
    ekle(kok, "algoritma");
    printf("Kelimeler Trie agacina basariyla eklendi.\n");
    return 0;
}
