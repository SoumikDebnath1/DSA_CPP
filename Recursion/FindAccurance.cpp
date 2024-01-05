#include <iostream>
using namespace std;

void PrintArrayElemtnt(int arr[], int size, int index, int searchElement, int count)
{

    if (arr[index] == searchElement)
    {
        count++;
    }
    if (index > size)
    {
        cout << "count is =>" << count;
        return;
    }

    PrintArrayElemtnt(arr, size, index + 1, searchElement, count);
}

int main()
{
    int count = 0;
    int arr[] = {10, 11, 11, 11, 34};
    int searchElement;
    cin >> searchElement;
    PrintArrayElemtnt(arr, 5, 0, searchElement, count);
}