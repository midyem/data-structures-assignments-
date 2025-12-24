#include <stdio.h>
#define MAX 100

int arr[MAX];
int size = 0;

// إضافة في النهاية
void ekle(int deger) {
    if (size < MAX) {
        arr[size++] = deger;
    }
}

// إضافة في موضع محدد
void arayaEkle(int index, int deger) {
    if (index < 0 || index > size || size >= MAX) return;
    for (int i = size; i > index; i--) {
        arr[i] = arr[i-1];
    }
    arr[index] = deger;
    size++;
}

// حذف من موضع محدد
void sil(int index) {
    if (index < 0 || index >= size) return;
    for (int i = index; i < size-1; i++) {
        arr[i] = arr[i+1];
    }
    size--;
}

// حذف بقيمة محددة
void degerleSil(int deger) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == deger) {
            sil(i);
            return;
        }
    }
}

// عرض المصفوفة
void goster() {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// اختبار
int main() {
    ekle(10); ekle(20); ekle(30);
    printf("الأصل: "); goster(); // 10 20 30
    
    arayaEkle(1, 15);
    printf("بعد الإضافة: "); goster(); // 10 15 20 30
    
    sil(2);
    printf("بعد الحذف: "); goster(); // 10 15 30
    
    degerleSil(10);
    printf("حذف بالقيمة: "); goster(); // 15 30
    
    return 0;
}