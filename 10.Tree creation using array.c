#include <stdio.h>
#define MAX 100

int tree[MAX], size = 0;

void insert(int v) { if(size < MAX) tree[size++] = v; }
int left(int i) { return (2*i+1 < size) ? tree[2*i+1] : -1; }
int right(int i) { return (2*i+2 < size) ? tree[2*i+2] : -1; }
int parent(int i) { return (i == 0) ? -1 : tree[(i-1)/2]; }

int main() {
 
    insert(10); insert(20); insert(30);
    
    printf("root: %d\n", tree[0]);
    printf(left cheldrin: %d\n", left(0));
    printf(right children : %d\n", right(0));
    
    return 0;
}