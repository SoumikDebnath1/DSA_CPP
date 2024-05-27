#include <iostream>
#include <vector>

using namespace std;
int main()
{
    vector<int> numbers = {1, 2, 3, 4, 5};

    // Using a range-based for loop special to traverse a .............................vector
    for (int num : numbers)
    {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
