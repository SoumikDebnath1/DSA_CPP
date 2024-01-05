#include <iostream>
using namespace std;

int Exp(int num, int pow)
{
    int f;
    if (pow == 1)
        return num;
    f = num * Exp(num, pow - 1);
    return f;
}

int main()
{
    int num, pow;
    cin >> num;
    cin >> pow;
    cout << pow << " of " << num << "is " << Exp(num, pow);
}