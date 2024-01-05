#include <iostream>
using namespace std;

void ReverseCount(int num)
{

    cout << num << " ";
    if (num == 1)
    {
        return;
    }
    ReverseCount(num - 1);
}

int main()
{
    int num;
    cin >> num;
    cout << "rev counting n ot 1 is " << endl;
    ReverseCount(num);
}