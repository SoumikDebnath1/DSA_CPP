#include <iostream>
#include <string.h>
#include <vector>
using namespace std;
// conditions for idSafe
// path closed
// index out of bounds
// check if the position is visited before
bool isSafe(int arr[][4], vector<vector<bool>> &visited, int srcx, int srcy, int nx, int ny, int row, int col)
{
    if (arr[nx][ny] == 1 && (nx >= 0 && nx < row) && (ny >= 0 && ny < col) && visited[nx][ny] == false)
    {

        return true;
    }
    else
        return false;
}
void Allpath(int row, int col, int arr[][4], int srcx, int srcy, string &output, vector<vector<bool>> &visited, int &count)
{
    // base case
    if (srcx == row - 1 && srcy == col - 1)
    {
        cout << output << endl;
        count++;
        return;
    }
    // dont go if a path is visited before
    //  up
    if (isSafe(arr, visited, srcx, srcy, srcx - 1, srcy, row, col))
    {
        // mark visited
        visited[srcx - 1][srcy] = true;
        // call visited
        output.push_back('U');
        Allpath(row, col, arr, srcx - 1, srcy, output, visited, count);

        // backtracking while coming back mark that place as not visited
        output.pop_back();
        visited[srcx - 1][srcy] = false;
    }
    //  down
    if (isSafe(arr, visited, srcx, srcy, srcx + 1, srcy, row, col))
    {
        // mark visited
        visited[srcx + 1][srcy] = true;
        // call visited
        output.push_back('D');
        Allpath(row, col, arr, srcx + 1, srcy, output, visited, count);

        // backtracking while coming back mark that place as not visited
        output.pop_back();
        visited[srcx + 1][srcy] = false;
    }
    //  right
    if (isSafe(arr, visited, srcx, srcy, srcx, srcy + 1, row, col))
    {
        // mark visited
        visited[srcx][srcy + 1] = true;
        // call visited
        output.push_back('R');
        Allpath(row, col, arr, srcx, srcy + 1, output, visited, count);

        // backtracking while coming back mark that place as not visited
        output.pop_back();
        visited[srcx][srcy + 1] = false;
    }
    //  left
    if (isSafe(arr, visited, srcx, srcy, srcx, srcy - 1, row, col))
    { // mark visited
        visited[srcx][srcy - 1] = true;
        // call visited
        output.push_back('L');
        Allpath(row, col, arr, srcx, srcy - 1, output, visited, count);

        // backtracking while coming back mark that place as not visited
        output.pop_back();
        visited[srcx][srcy - 1] = false;
    }
}
int main()
{
    int arr[4][4] = {
        {1, 0, 0, 0},
        {1, 1, 0, 0},
        {1, 1, 1, 0},
        {1, 1, 1, 1}

    };
    int row = 4, col = 4;
    int srcx = 0;
    int srcy = 0;
    string output = "";
    int count = 0;
    // vector for visited array
    vector<vector<bool>> visited(row, vector<bool>(col, false));
    if (arr[0][0] == 0)
    {
        cout << "no path exist" << endl;
    }
    else
    {
        visited[srcx][srcy] = true;
        Allpath(row, col, arr, srcx, srcy, output, visited, count);
        cout << count;
    }
}