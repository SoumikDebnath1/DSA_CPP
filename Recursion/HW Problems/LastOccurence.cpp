#include <iostream>
#include <string.h>
using namespace std;
void LastOccurence(string str, int i, char target, int &ans)
{
    int len = str.length();

    if (i > len)
    {
        return;
    }
    if (str[i] == target)
    {
        ans = i;
    }

    LastOccurence(str, i + 1, target, ans);
}

int main()
{
    string str;
    cin >> str;
    int ans = -1;

    LastOccurence(str, 0, 'd', ans);
    cout << ans;
}