#include <cstdio>
#include <iostream>
#include <set>

using namespace std;

int main()
{
    set<int> ans;

    int N;
    cin >> N;

    for (int i = 1; i < N + 1; i++)
    {
        int num = i / 2 + i / 3 + i / 5;
        ans.insert(num);
    }

    cout << ans.size();
    return 0;
}