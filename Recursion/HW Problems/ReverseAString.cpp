#include <iostream>
#include <string.h>
using namespace std;
void rev(string str, int i)
{

    if (i > str.length())
    {
        return;
    }
    rev(str, i + 1);
    cout << str[i];
}
int main()
{
    string s = "abcrte";
    rev(s, 0);
}