#include <stdio.h>
#include <stdbool.h>
#define N 10

// DFS للعثور على جميع الرؤوس في العنقود
void DFS(int graph[N][N], bool visited[N], int node, int cluster[], int* size) {
    visited[node] = true;
    cluster[(*size)++] = node;
    
    for (int i = 0; i < N; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            DFS(graph, visited, i, cluster, size);
        }
    }
}

// استخراج جميع العناقيد من Graph
void extractClusters(int graph[N][N]) {
    bool visited[N] = {false};
    
    for (int i = 0; i < N; i++) {
        if (!visited[i]) {
            int cluster[N];
            int size = 0;
            
            DFS(graph, visited, i, cluster, &size);
            
            // طباعة العنقود إذا كان يحتوي على أكثر من رأس واحد
            if (size > 1) {
                printf("Cluster: ");
                for (int j = 0; j < size; j++) {
                    printf("%d ", cluster[j]);
                }
                printf("\n");
            }
        }
    }
}

// مثال اختبار
int main() {
    // مثال: مصفوفة تجاور (0 = لا يوجد اتصال، 1 = اتصال)
    int graph[N][N] = {
        {0,1,0,0,0,0,0,0,0,0},
        {1,0,1,0,0,0,0,0,0,0},
        {0,1,0,0,0,0,0,0,0,0},
        {0,0,0,0,1,1,0,0,0,0},
        {0,0,0,1,0,1,0,0,0,0},
        {0,0,0,1,1,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,0,0},
        {0,0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,0,0,0}
    };
    
    extractClusters(graph);
    return 0;
}