#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int maxQueens = 0;

int **createBoard(int N)
{
    int **board = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++)
    {
        board[i] = (int *)malloc(N * sizeof(int));
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            if (j >= i)
            {
                board[i][j] = 0;
            }
            else
            {
                board[i][j] = 2;
            }
        }
    }

    return board;
}

void printBoard(int N, int **board)
{
    for (int i = N - 1; i >= 0; --i)
    {
        for (int j = N - 1; j >= 0; --j)
        {
            if (board[i][j] != 2)
            {
                printf("%d", board[i][j]);
            }
        }
        printf("\n");
    }
}

bool isSafe(int **board, int row, int col, int N)
{
    // Check column
    for (int i = 0; i < N; i++)
    {
        if (board[i][col] == 1)
        {
            return false;
        }
    }

    // Check row
    for (int i = 0; i < N; i++)
    {
        if (board[row][i] == 1)
        {
            return false;
        }
    }

    // Check diagonal from top left to bottom right
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }
    for (int i = row, j = col; i < N && j < N; i++, j++)
    {
        if (board[i][j] == 1)
        {
            return false;
        }
    }

    return true;
}

void solve(int **board, int col, int N, int queens)
{
    // Base case
    if (N == 0)
    {
        maxQueens = 0;
        return;
    }

    if (col == N)
    {
        if (queens > maxQueens)
        {
            maxQueens = queens;
            printf("Solution with %d queens:\n", maxQueens);
            printBoard(N, board);
        }
        return;
    }

    // Recursive case
    for (int i = 0; i < N; i++)
    {
        if (board[i][col] != 2 && isSafe(board, i, col, N))
        {
            board[i][col] = 1;
            queens++;
            solve(board, col + 1, N, queens);
            board[i][col] = 0;
            queens--;
        }
    }

    solve(board, col + 1, N, queens);
}

int main()
{
    int N;
    printf("Enter N: ");
    scanf("%d",&N);


    int **board = createBoard(N);

    solve(board, 0, N, 0);

    printf("The maximum number of queens that can be placed in a N=%d triangle is %d\n",N,maxQueens);

    free(board);
    return 0;
}
