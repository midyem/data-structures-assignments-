#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Max Heap
typedef struct { int arr[MAX], size; } MaxHeap;

void mh_insert(MaxHeap* h, int val) {
    if (h->size >= MAX) return;
    int i = h->size++;
    h->arr[i] = val;
    while (i > 0 && h->arr[(i-1)/2] < h->arr[i]) {
        int t = h->arr[i];
        h->arr[i] = h->arr[(i-1)/2];
        h->arr[(i-1)/2] = t;
        i = (i-1)/2;
    }
}

int mh_extract(MaxHeap* h) {
    if (h->size == 0) return -1;
    int max = h->arr[0];
    h->arr[0] = h->arr[--h->size];
    int i = 0;
    while (1) {
        int l = i, left = 2*i+1, right = 2*i+2;
        if (left < h->size && h->arr[left] > h->arr[l]) l = left;
        if (right < h->size && h->arr[right] > h->arr[l]) l = right;
        if (l == i) break;
        int t = h->arr[i]; h->arr[i] = h->arr[l]; h->arr[l] = t;
        i = l;
    }
    return max;
}

// Min Heap
typedef struct { int arr[MAX], size; } MinHeap;

void min_insert(MinHeap* h, int val) {
    if (h->size >= MAX) return;
    int i = h->size++;
    h->arr[i] = val;
    while (i > 0 && h->arr[(i-1)/2] > h->arr[i]) {
        int t = h->arr[i];
        h->arr[i] = h->arr[(i-1)/2];
        h->arr[(i-1)/2] = t;
        i = (i-1)/2;
    }
}

int min_extract(MinHeap* h) {
    if (h->size == 0) return -1;
    int min = h->arr[0];
    h->arr[0] = h->arr[--h->size];
    int i = 0;
    while (1) {
        int s = i, left = 2*i+1, right = 2*i+2;
        if (left < h->size && h->arr[left] < h->arr[s]) s = left;
        if (right < h->size && h->arr[right] < h->arr[s]) s = right;
        if (s == i) break;
        int t = h->arr[i]; h->arr[i] = h->arr[s]; h->arr[s] = t;
        i = s;
    }
    return min;
}

// طباعة
void print(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

// اختبار
int main() {
    MaxHeap max = {0};
    MinHeap min = {0};
    
    mh_insert(&max, 10); mh_insert(&max, 30); mh_insert(&max, 20);
    printf("Max: "); print(max.arr, max.size);
    printf("Extract: %d\n", mh_extract(&max));
    print(max.arr, max.size);
    
    min_insert(&min, 10); min_insert(&min, 30); min_insert(&min, 20);
    printf("\nMin: "); print(min.arr, min.size);
    printf("Extract: %d\n", min_extract(&min));
    print(min.arr, min.size);
    
    return 0;
}