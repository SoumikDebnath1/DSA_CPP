#include <iostream>
#include <string.h>
using namespace std;

void Subsequence(string str, string output, int index)
{
    if (index >= str.length())
    { // when the index will be at it's limit the ans will be already built
        cout << "->" << output << endl;
        return;
    }
    // included
    char ch = str[index];
    output.push_back(ch);
    Subsequence(str, output, index + 1);
    // excludec
    output.pop_back();
    Subsequence(str, output, index + 1);
}
int main()
{
    string s = "abc";
    string output = "";
    Subsequence(s, output, 0);
}