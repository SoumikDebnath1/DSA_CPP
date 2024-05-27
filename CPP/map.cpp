#include <iostream>
#include <map>
#include <string>

using namespace std;
// map is an associative array
int main()
{
    map<string, int> marksMap;
    marksMap["Soumik"] = 93;
    marksMap["mik"] = 92;
    marksMap["sou"] = 91;
    map<string, int>::iterator iter; // it is in the STL library
    for (iter = marksMap.begin(); iter != marksMap.end(); iter++)
    {
        cout << (*iter).first << " " << (*iter).second << "\n";
    }

    return 0;
}