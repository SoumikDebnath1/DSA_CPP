#include <iostream>
using namespace std;

double myPow(double x, int n)
{

    int p = abs(n); // abc(int) returns the absolute value of the int
    double ans = 1.0;
    while (p > 1)
    {
        p /= 2;
        x *= x;
    }
    ans = x;
    return n < 0 ? 1 / ans : ans;
}
int main()
{
    cout << myPow(8.0, 2);
}