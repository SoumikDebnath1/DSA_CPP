// N_queens problems
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// isSafe function
bool isSafe(int **arr, int row, int col, int n)
{
    int duprow = row;
    int dupcol = col;
    while (col >= 0)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        col--;
    }
    row = dupcol;
    col = dupcol;
    while (col >= 0 && row >= 0)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col--;
    }
    row = dupcol;
    col = dupcol;
    while (col < n && row >= 0)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col++;
    }
}
bool solve(int **arr, int col, int n)
{
    // base case if col is finished work is done

    if (col == n)
    {

        return true;
    }
    for (int row = 0; row < n; row++)
    {

        if (isSafe(arr, row, col, n))
        {
            arr[row][col] = 1;
            if (solve(arr, col + 1, n))
            {
                return true;
            }
            arr[row][col] = 0;
        }
    }

    return false;
}

int main()
{
    int n;

    printf("Enter the number of rows and columns (same value): ");
    scanf("%d", &n);
    int **arr;
    arr = (int **)malloc(n * sizeof(int *));
    for (int row = 0; row < n; row++)
    {
        arr[row] = (int *)malloc(n * sizeof(int)); // alocation memory for every row
        for (int col = 0; col < n; col++)
        {
            arr[row][col] = 0;
        }
    }
    solve(arr, 0, n);
    if (solve(arr, 0, n))
    {

        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                printf("%d ", arr[row][col]);
            }
            printf("\n");
        }
    }
}
