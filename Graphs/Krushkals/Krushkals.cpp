#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int u, v, weight;
} Edge;

int comparator(const void* p1, const void* p2) {
    return ((Edge*)p1)->weight - ((Edge*)p2)->weight;
}

void makeSet(int parent[], int rank[], int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int findParent(int parent[], int component) {
    if (parent[component] != component) {
        parent[component] = findParent(parent, parent[component]);
    }
    return parent[component];
}

void unionSet(int u, int v, int parent[], int rank[]) {
    int rootU = findParent(parent, u);
    int rootV = findParent(parent, v);

    if (rootU != rootV) {
        if (rank[rootU] > rank[rootV]) {
            parent[rootV] = rootU;
        } else if (rank[rootU] < rank[rootV]) {
            parent[rootU] = rootV;
        } else {
            parent[rootV] = rootU;
            rank[rootU]++;
        }
    }
}

void kruskalAlgo(int n, Edge edges[], int m) {
    qsort(edges, m, sizeof(Edge), comparator);

    int parent[n];
    int rank[n];

    makeSet(parent, rank, n);

    int minCost = 0;
    printf("Following are the edges in the constructed MST:\n");

    for (int i = 0; i < m; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int wt = edges[i].weight;

        if (findParent(parent, u) != findParent(parent, v)) {
            unionSet(u, v, parent, rank);
            minCost += wt;
            printf("%d -- %d == %d\n", u, v, wt);
        }
    }

    printf("Minimum Cost Spanning Tree: %d\n", minCost);
}

int main() {
    Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    int n = 4; // Number of vertices (0 to 3)
    int m = sizeof(edges) / sizeof(edges[0]); // Number of edges

    kruskalAlgo(n, edges, m);

    return 0;
}
