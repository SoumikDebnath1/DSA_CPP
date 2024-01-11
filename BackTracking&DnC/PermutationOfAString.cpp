#include <iostream>
#include <string.h>
using namespace std;
void Permutation(string &str, int index)
{

    // base case to stop
    if (index >= str.length())
    {
        cout << str << " ";
        return;
    }
    for (int j = index; j < str.length(); j++)
    {
        // swaping for each position
        swap(str[index], str[j]);
        // recursive call
        Permutation(str, index + 1);

        /* while backtracking the original string is changing
         to undo it we have to swap again this is the concept of
         back tracking*/
        swap(str[index], str[j]);
    }
}
int main()
{
    string str = "abc";
    Permutation(str, 0);
}