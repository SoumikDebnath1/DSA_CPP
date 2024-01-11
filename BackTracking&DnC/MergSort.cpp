#include <iostream>
using namespace std;
int MergSort(int arr[], int s, int e)
{
    // mid calculation
    int mid = (s + e) / 2;
    int lengthLeft = mid - s + 1;
    int lengthRight = e - mid;
    // create left and right array
    int *left = new int[lengthLeft];
    int *right = new int[lengthRight];
    // copy value from original array to left array
    int k = s;
    for (int i = 0; i < lengthLeft; i++)
    {
        left[i] = arr[k];
        k++;
    }
    // copy value from original array to right array
    k = mid + 1;
    for (int i = 0; i < lengthRight; i++)
    {
        right[i] = arr[k];
        k++;
    }
    // left array and right array alerady sorted
    int leftIndex = 0;
    int rightIndex = 0;
    int mainIndex = s;
    while (leftIndex < lengthLeft && rightIndex < lengthRight)
    {
        if (left[leftIndex] < right[rightIndex])
        {
            arr[mainIndex] = left[leftIndex];
            mainIndex++;
            leftIndex++;
        }
        else
        {
            arr[mainIndex] = right[rightIndex];
            mainIndex++;
            rightIndex++;
        }
    }

    // case->1 left index exhausted
    while (rightIndex < lengthRight)
    {
        arr[mainIndex] = right[rightIndex];
        rightIndex++;
        mainIndex++;
    }
    // case->2 right index exhausted
    while (leftIndex < lengthLeft)
    {
        arr[mainIndex] = left[leftIndex];
        leftIndex++;
        mainIndex++;
    }
    // free space
    delete[] left;
    delete[] right;
}
void sort(int arr[], int s, int e)
{
    if (s >= e)
    {
        return;
    }

    int mid = (s + e) / 2;
    sort(arr, s, mid);
    sort(arr, mid + 1, e);
    MergSort(arr, s, e);
}

int main()
{

    int arr[] = {2, 1, 6, 9, 4, 5};
    int size = 6;
    int s = 0;
    int e = size - 1;

    cout << "Before merge sort: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    sort(arr, s, e);

    cout << "After merge sort: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}