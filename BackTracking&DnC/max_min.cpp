// max_min
#include <stdio.h>
// Structure to store both maximum and minimum elements
struct Pair
{
    int max;
    int min;
};
struct Pair maxMinDivideConquer(int arr[], int low, int high)
{
    struct Pair result;
    struct Pair left;
    struct Pair right;
    int mid;
    // If only one element in the array
    if (low == high)
    {
        result.max = arr[low];
        result.min = arr[low];
        return result;
    }
    // If there are two elements in the array
    if (high == low + 1)
    {
        if (arr[low] < arr[high])
        {
            result.min = arr[low];
            result.max = arr[high];
        }
        else
        {
            result.min = arr[high];
            result.max = arr[low];
        }
        return result;
    }
    // If there are more than two elements in the array
    mid = (low + high) / 2;
    left = maxMinDivideConquer(arr, low, mid);
    right = maxMinDivideConquer(arr, mid + 1, high);
    // Compare and get the maximum of both parts
    result.max = (left.max > right.max) ? left.max : right.max;
    // Compare and get the minimum of both parts
    result.min = (left.min < right.min) ? left.min : right.min;
    return result;
}