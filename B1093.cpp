#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main()
{
    string a, b;
    getline(cin, a);
    getline(cin, b);
    a += b;
    unordered_map<char, int> m;
    for (auto it : a)
    {
        if (m[it] == 0)
        {
            m[it]++;
            cout << it;
        }
    }

    return 0;
}