#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct Queue { // queue structure for BFS
    int items[MAX];
    int front, rear;
};

void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int isEmpty(struct Queue* q) {
    return q->front == -1;
}

void enqueue(struct Queue* q, int value) {
    if (q->rear == MAX - 1) return; // overflow check
    if (q->front == -1) q->front = 0;
    q->rear++;
    q->items[q->rear] = value;
}

int dequeue(struct Queue* q) {
    if (isEmpty(q)) return -1; // underflow check
    int val = q->items[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else {
        q->front++;
    }
    return val;
}

// Graph using adjacency matrix
struct Graph {
    int vertices;
    int adjMatrix[MAX][MAX];
};

// Initializing graph
void initGraph(struct Graph* g, int v) {
    g->vertices = v;
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            g->adjMatrix[i][j] = 0;
}

// Add edge (undirected)
void addEdge(struct Graph* g, int u, int v) {
    g->adjMatrix[u][v] = 1;
    g->adjMatrix[v][u] = 1;
}

// DFS traversal
void DFSUtil(struct Graph* g, int v, int visited[]) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < g->vertices; i++) {
        if (g->adjMatrix[v][i] && !visited[i])
            DFSUtil(g, i, visited);
    }
}

void DFS(struct Graph* g, int start) {
    int visited[MAX] = {0};
    printf("DFS starting from vertex %d: ", start);
    DFSUtil(g, start, visited);
    printf("\n");
}

// BFS traversal
void BFS(struct Graph* g, int start) {
    int visited[MAX] = {0};
    struct Queue q;
    initQueue(&q);

    visited[start] = 1;
    enqueue(&q, start);

    printf("BFS starting from vertex %d: ", start);

    while (!isEmpty(&q)) {
        int v = dequeue(&q);
        printf("%d ", v);

        for (int i = 0; i < g->vertices; i++) {
            if (g->adjMatrix[v][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(&q, i);
            }
        }
    }
    printf("\n");
}

// displaying adjacency matrix
void displayMatrix(struct Graph* g) {
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < g->vertices; i++) {
        for (int j = 0; j < g->vertices; j++) {
            printf("%d ", g->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    struct Graph g;
    int V = 5; // number of vertices
    initGraph(&g, V);

    // adding edges
    addEdge(&g, 0, 1);
    addEdge(&g, 0, 2);
    addEdge(&g, 1, 3);
    addEdge(&g, 1, 4);
    addEdge(&g, 2, 4);

    displayMatrix(&g);

    DFS(&g, 0);
    BFS(&g, 0);

    return 0;
}
