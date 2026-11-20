*DFS*


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

// Stack variables (replaces Queue from BFS)
int stack[MAX];
int top = -1;

void push(int data) {
    stack[++top] = data;
}

int pop() {
    return stack[top--];
}

int peek() {
    return stack[top];
}

bool is_stack_empty() {
    return top == -1;
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

void dfs(int start) {
    if (start < 0 || start >= vertex_count || !graph[start]) {
        printf("\nInvalid starting vertex! Nothing to display.\n");
        return;
    }

    // Reset stack pointer before traversal
    top = -1;

    printf("\nDFS Traversal Order:\n");
    printf("|||||||||||||||||||||||||||||||\n");
    
    // Mark starting node visited, display it, and push to stack
    graph[start]->visited = true;
    display_vertex(start);
    push(start);

    while (!is_stack_empty()) {
        // Look at the top vertex without removing it yet
        int unvisited = adj_vertex(peek());

        if (unvisited == -1) {
            // No unvisited neighbors left; backtrack by popping
            pop();
        } else {
            // Visit the first unvisited neighbor and go deeper
            graph[unvisited]->visited = true;
            display_vertex(unvisited);
            push(unvisited);
        }
    }
    printf("END\n|||||||||||||||||||||||||||||||\n");

    // Reset visited status for future traversals
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
            i--; 
        } else {
            add_edge(edge_1, edge_2);
        }
    }

    // Step 3: Ask for starting vertex and print DFS traversal
    printf("\nEnter starting vertex position for DFS traversal (0 to %d): ", vertex_count - 1);
    scanf("%d", &start);
    
    dfs(start);

    return 0;
}
