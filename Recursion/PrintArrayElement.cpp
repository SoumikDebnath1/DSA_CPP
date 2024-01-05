#include <iostream>
using namespace std;

void PrintArrayElemtnt(int arr[], int size, int index)
{

    if (index >= size)
    {
        return;
    }
    cout << arr[index];
    PrintArrayElemtnt(arr, size, index + 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    PrintArrayElemtnt(arr, 5, 0);
}