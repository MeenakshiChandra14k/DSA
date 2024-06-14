#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 7

int visited[MAX_NODES] = {0};
int adjacencyMatrix[MAX_NODES][MAX_NODES] = {
    {0, 1, 1, 1, 0, 0, 0},
    {1, 0, 1, 0, 0, 0, 0},
    {1, 1, 0, 1, 1, 0, 0},
    {1, 0, 1, 0, 1, 0, 0},
    {0, 0, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0, 0}
};

int queue[MAX_NODES];
int front = -1, rear = -1;

void enqueue(int item) {
    if (rear == MAX_NODES - 1) {
        printf("Queue is full\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = item;
}

int dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
        return -1;
    }
    int item = queue[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
    return item;
}

int isEmpty() {
    return front == -1;
}

void BFS(int startNode) {
    printf("Breadth-First Traversal starting from node %d: ", startNode);
    printf("%d ", startNode);
    visited[startNode] = 1;
    enqueue(startNode);

    while (!isEmpty()) {
        int currentNode = dequeue();

        for (int i = 0; i < MAX_NODES; i++) {
            if (adjacencyMatrix[currentNode][i] == 1 && !visited[i]) {
                printf("%d ", i);
                visited[i] = 1;
                enqueue(i);
            }
        }
    }

    printf("\n");
}

int main() {
    int startNode;
    printf("Enter the starting node for BFS: ");
    scanf("%d", &startNode);

    if (startNode < 0 || startNode >= MAX_NODES) {
        printf("Invalid starting node\n");
        return 1;
    }

    BFS(startNode);

    return 0;
}
