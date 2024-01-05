#include <iostream>
using namespace std;
void solve(int arr[5], int size)
/*Here arr just an array pointer which is pointing
towards ar's first position that's why it's size is 4*/

{
    cout << "size of the array function " << sizeof(arr) << endl;
}
int main()
{
    int ar[] = {10, 20, 30, 40, 50};
    // here the size will be 4*5=20

    cout << "size of the array" << sizeof(ar) << endl;
    solve(ar, 5);
}