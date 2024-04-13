#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 8

typedef struct {
    int row;
    int col;
} Position;

int isValidPosition(int row, int col) {
    return row >= 0 && row < SIZE && col >= 0 && col < SIZE;
}

int knightMoves(Position start, Position end) {
    // Posições do Cavalo em qualquer direção
    int dr[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dc[] = {1, 2, 2, 1, -1, -2, -2, -1};
    // Matriz de movimentos
    int dist[SIZE][SIZE];
    memset(dist, -1, sizeof(dist));
    // Fila
    Position queue[SIZE * SIZE];
    int front = 0, rear = 0;
    queue[rear++] = start;
    dist[start.row][start.col] = 0;
    // BFS
    while (front < rear) {
        Position current = queue[front++];
        if (current.row == end.row && current.col == end.col) {
            return dist[current.row][current.col];
        }
        for (int i = 0; i < 8; ++i) {
            int newRow = current.row + dr[i];
            int newCol = current.col + dc[i];
            if (isValidPosition(newRow, newCol) && dist[newRow][newCol] == -1) {
                queue[rear++] = (Position){newRow, newCol};
                dist[newRow][newCol] = dist[current.row][current.col] + 1;
            }
        }
    }
    return -1;
}

int main() {
    char a[3], b[3];
    while (scanf("%s %s", a, b) != EOF) {
        Position start = {(int)(a[1] - '1'), (int)(a[0] - 'a')};
        Position end = {(int)(b[1] - '1'), (int)(b[0] - 'a')};
        int moves = knightMoves(start, end);
        printf("To get from %s to %s takes %d knight moves.\n", a, b, moves);
    }
    return 0;
}
