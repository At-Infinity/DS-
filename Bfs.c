*BFS*

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

int vertex_count = 0;

struct vertex {
    char data;
    bool visited;
};

struct vertex *graph[MAX];
int adj_matrix[MAX][MAX];
int queue[MAX];
int rear = -1;
int front = 0;
int queue_count = 0;

void enqueue(int data) {
    queue[++rear] = data;
    queue_count++;
}

int dequeue() {
    queue_count--;
    return queue[front++];
}

bool is_queue_empty() {
    return queue_count == 0;
}

void add_vertex(char data) {
    struct vertex *new_node = (struct vertex*)malloc(sizeof(struct vertex));
    new_node->data = data;
    new_node->visited = false;
    graph[vertex_count] = new_node;
    vertex_count++;
}

void add_edge(int start, int end) {
    adj_matrix[start][end] = 1;
    adj_matrix[end][start] = 1;
}

int adj_vertex(int vertex_get) {
    for (int i = 0; i < vertex_count; i++) {
        if (adj_matrix[vertex_get][i] == 1 && graph[i]->visited == false) {
            return i;
        }
    }
    return -1;
}

void display_vertex(int pos) {
    printf("%c -> ", graph[pos]->data);
}

void bfs(int start) {
    if (start < 0 || start >= vertex_count || !graph[start]) {
        printf("\nInvalid starting vertex! Nothing to display.\n");
        return;
    }

    // Reset queue pointers before traversal
    rear = -1;
    front = 0;
    queue_count = 0;

    int unvisited;
    printf("\nBFS Traversal Order:\n");
    printf("|||||||||||||||||||||||||||||||\n");
    
    graph[start]->visited = true;
    display_vertex(start);
    enqueue(start);

    while (!is_queue_empty()) {
        int pop_vertex = dequeue();
        while ((unvisited = adj_vertex(pop_vertex)) != -1) {
            graph[unvisited]->visited = true;
            display_vertex(unvisited);
            enqueue(unvisited);
        }
    }
    printf("END\n|||||||||||||||||||||||||||||||\n");

    // Reset visited status
    for (int i = 0; i < vertex_count; i++) {
        graph[i]->visited = false;
    }
}

void show() {
    printf("\n--- Vertex Index Reference ---\n");
    for (int i = 0; i < vertex_count; i++) {
        printf("Position %d : '%c'\n", i, graph[i]->data);
    }
    printf("------------------------------\n");
}

int main() {
    int num_vertices, num_edges;
    char data;
    int edge_1, edge_2, start;

    // Initialize adjacency matrix to 0
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            adj_matrix[i][j] = 0;
        }
    }

    // Step 1: Take number of vertices and their data
    printf("Enter the number of vertices (max %d): ", MAX);
    scanf("%d", &num_vertices);

    if (num_vertices <= 0 || num_vertices > MAX) {
        printf("Invalid number of vertices! Exiting.\n");
        return 1;
    }

    for (int i = 0; i < num_vertices; i++) {
        printf("Enter label (character) for vertex %d: ", i);
        scanf(" %c", &data);
        add_vertex(data);
    }

    show();

    // Step 2: Take number of edges and connect them
    printf("\nEnter the number of edges: ");
    scanf("%d", &num_edges);

    for (int i = 0; i < num_edges; i++) {
        printf("\nEdge %d:\n", i + 1);
        printf("  Enter starting vertex position (0 to %d): ", vertex_count - 1);
        scanf("%d", &edge_1);
        printf("  Enter ending vertex position (0 to %d): ", vertex_count - 1);
        scanf("%d", &edge_2);

        if (edge_1 < 0 || edge_1 >= vertex_count || edge_2 < 0 || edge_2 >= vertex_count) {
            printf("  Invalid vertex position! Please re-enter this edge.\n");
            i--; // Repeat this iteration so the user doesn't lose an edge
        } else {
            add_edge(edge_1, edge_2);
        }
    }

    // Step 3: Ask for starting vertex and print BFS traversal
    printf("\nEnter starting vertex position for BFS traversal (0 to %d): ", vertex_count - 1);
    scanf("%d", &start);
    
    bfs(start);

    return 0;
}
