#include <iostream>
using namespace std;
int BinarySearch(int arr[], int s, int e, int target)
{
    if (s > e)
    {
        return -1;
    }
    int mid = s + ((e - s) / 2);

    if (arr[mid] == target)
    {
        return 1;
    }
    else if (arr[mid] > target)
    {
        BinarySearch(arr, s, mid - 1, target);
    }
    else if (arr[mid] < target)
    {
        BinarySearch(arr, mid + 1, e, target);
    }
}
int main()
{
    int arr[] = {1, 4, 5, 6, 3, 7};
    cout << "Search result =>" << BinarySearch(arr, 0, 5, 78);
}