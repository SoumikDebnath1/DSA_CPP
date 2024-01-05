// 1,2,3,4,5,6,7,8,9
// 2,4,6,8
#include <iostream>
#include <vector>
using namespace std;
void odd(vector<int> &vr, int arr[], int size, int index)
{
    if ((arr[index] % 2) == 0)
    {
        vr.push_back(arr[index]);
    }
    if (index >= size - 1)
    {
        return;
    }
    odd(vr, arr, size, index + 1);
}

void Prnt(vector<int> v)
{

    for (auto i : v)
    {
        cout << i << " ";
    }
}

int main()
{
    // vector containing integer elements
    int Arr[] = {10, 21, 30,
                 40, 55, 61};

    vector<int> vr;
    odd(vr, Arr, 6, 0);
    Prnt(vr);

    return 0;
}
