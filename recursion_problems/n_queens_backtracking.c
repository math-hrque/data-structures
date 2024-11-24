#include <stdio.h>
#include <stdlib.h>

#define N 8

void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", board[i][j] ? 'Q' : '.');
        }
        printf("\n");
    }
    printf("\n");
}

int isSafe(int board[N][N], int row, int col) {
    for (int i = 0; i < col; i++) {
        if (board[row][i]) return 0;
    }
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j]) return 0;
    }
    for (int i = row, j = col; i < N && j >= 0; i++, j--) {
        if (board[i][j]) return 0;
    }
    return 1;
}

int solveNQueensUtil(int board[N][N], int col) {
    if (col >= N) return 1;

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            board[i][col] = 1;
            if (solveNQueensUtil(board, col + 1)) return 1;
            board[i][col] = 0;
        }
    }
    return 0;
}

void solveNQueens() {
    int board[N][N] = {0};
    if (!solveNQueensUtil(board, 0)) {
        printf("Solution does not exist\n");
        return;
    }
    printSolution(board);
}

int main() {
    printf("N-Queens Problem Solution:\n");
    solveNQueens();
    return 0;
}
