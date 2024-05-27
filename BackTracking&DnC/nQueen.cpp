
#include <iostream>
using namespace std;
bool isSafe(int **arr, int row, int col, int d)
{

    int duprow = row;
    int dupcol = col;
    // left diagonal upwards
    while (col >= 0 && row >= 0)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        row--;
        col--;
    }
    row = duprow;
    col = dupcol;
    // column
    while (col >= 0)
    {
        if (arr[row][col] == 1)
        {
            return false;
        }
        col--;
    }
    // diagonal left down wards
    col = dupcol;
    while (col < d && row >= 0)
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
    cin >> n;
    int **arr = new int *[n];

    for (int row = 0; row < n; row++)
    {
        arr[row] = new int[n];
        for (int col = 0; col < n; col++)
        {
            arr[row][col] = 0;
        }
    }
    if (solve(arr, 0, n))
    {
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                cout << arr[row][col] << " ";
            }
            cout << endl;
        }
    }
}
