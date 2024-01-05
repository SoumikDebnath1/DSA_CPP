#include <iostream>
using namespace std;

void PrintArrayElemtnt(int arr[], int size, int index, int searchElement)
{

    if (arr[index] == searchElement)
    {
        cout << "element found in " << index;
        return;
    }
    if (index > size)
    {
        cout << "not found";
        return;
    }

    PrintArrayElemtnt(arr, size, index + 1, searchElement);
}

int main()
{
    int arr[] = {10, 11, 45, 77, 34};
    int searchElement;
    cin >> searchElement;
    PrintArrayElemtnt(arr, 5, 0, searchElement);
}