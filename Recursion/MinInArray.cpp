#include <iostream>
#include <limits.h>
using namespace std;

int MIN(int arr[], int size, int index, int mini)
{
    if (index >= size)
    {
        return mini;
    }

    mini = min(mini, arr[index]); // the minimum num will be stored it's a comparison fun in #include <limits.h>
    MIN(arr, size, index + 1, mini);
}

int main()
{
    int arr[] = {78, 11, 45, 77, 34};
    int min = INT_MAX;

    cout << MIN(arr, 5, 0, min);
}