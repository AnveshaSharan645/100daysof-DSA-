#include <stdio.h>
#include <limits.h>

#define MAX 100

struct Edge {
    int u, v, w;
};

int main() {
    int n, m, i, j, source;
    struct Edge edges[MAX];
    int dist[MAX];

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &m);

    printf("Enter edges (u v w):\n");
    for(i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    // Initialize distances
    for(i = 0; i < n; i++)
        dist[i] = INT_MAX;

    dist[source] = 0;

    // Relax edges (n-1) times
    for(i = 1; i <= n-1; i++) {
        for(j = 0; j < m; j++) {
            int u = edges[j].u;
            int v = edges[j].v;
            int w = edges[j].w;

            if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    // Check negative cycle
    for(j = 0; j < m; j++) {
        int u = edges[j].u;
        int v = edges[j].v;
        int w = edges[j].w;

        if(dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("NEGATIVE CYCLE DETECTED\n");
            return 0;
        }
    }

    // Print distances
    printf("Shortest distances from source:\n");
    for(i = 0; i < n; i++) {
        if(dist[i] == INT_MAX)
            printf("Vertex %d: INF\n", i);
        else
            printf("Vertex %d: %d\n", i, dist[i]);
    }

    return 0;
}