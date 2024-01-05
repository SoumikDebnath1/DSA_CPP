#include <iostream>
using namespace std;

int Fibonaci(int num)
{

    int f;
    if (num == 1)
        return 1;
    if (num == 0)
        return 0;
    f = Fibonaci(num - 1) + Fibonaci(num - 2);
    return f;
}

int main()
{
    int num;
    cin >> num;
    cout << Fibonaci(num);
}