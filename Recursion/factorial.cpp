#include <iostream>
using namespace std;

int Factorial(int num)
{
    int f;
    if (num == 1)
        return 1;
    if (num == 0)
        return 0;
    f = num * Factorial(num - 1);
    return f;
}

int main()
{
    int num;
    cin >> num;
    cout << "factorial of " << num << "is" << Factorial(num);
}