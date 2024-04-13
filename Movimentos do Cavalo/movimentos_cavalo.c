#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 8

typedef struct{
    int row;
    int col;
} Position;

int isValidPosition(int row, int col) {
    return row >= 0 && row < SIZE && col >= 0 && col < SIZE;
}

int knightMovies(Position start, Position end){
    // Movimentações possíveis do cavalo
    int d_row[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int d_col[] = { 1,  2, 2, 1,-1,-2, -2, -1};

    int dist[SIZE][SIZE];
    memset(dist, -1, sizeof(dist));

    //Fila da BFS
    Position queue[SIZE * SIZE];
    int front = 0, rear = 0;

    //Posição inicial

    // Percurso em BFS
    
}

int main(){

    return 0;
}