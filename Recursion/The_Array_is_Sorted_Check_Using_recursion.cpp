#include <iostream>
using namespace std;
bool Validation(int arr[], int size, int index, int j)
{
    if (index >= size)
        return true;
    if (arr[index] > arr[j])
        return false;

    Validation(arr, size, index + 1, j + 1);
}
bool NewProcess(int arr[], int size, int index)
{
    if (index >= size)
    {
        return true;
    }
    if (arr[index] > arr[index + 1])
    {
        return false;
    }
    NewProcess(arr, size, index + 1);
}

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    // cout << Validation(a, 5, 0, 1);
    cout << "NEw  " << NewProcess(a, 5, 0);
}