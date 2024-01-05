#include <iostream>
#include <limits.h>
using namespace std;

int MAX(int arr[], int size, int index, int mini)
{
    if (index >= size)
    {
        return mini;
    }

    mini = max(mini, arr[index]); // the minimum num will be stored it's a comparison fun in #include <limits.h>
    MAX(arr, size, index + 1, mini);
}

int main()
{
    int arr[] = {78, 11, 45, 77, 34};
    int min = INT_MIN;

    cout << MAX(arr, 5, 0, min);
}