#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <utility>
#include <map>

using namespace std;
int arr[1010];
int N, M;
typedef pair<int, int> p;

bool operator<(p p1, p p2)
{
    if (p1.first != p2.first)
        return p1.first < p2.first;
    if (p1.second != p2.second)
        return p1.second < p2.second;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> N >> M;
    map<p, int> m;

    for (int i = 0; i < N; i++)
    {
        int f, s;
        cin >> f >> s;

        m[make_pair(f, s)]++;
        m[make_pair(s, f)]++;
    }

    while (M--)
    {
        int k;
        cin >> k;
        for (int i = 0; i < k; i++)
            cin >> arr[i];

        bool flag = true;
        for (int i = 0; i < k && flag; i++)
        {
            for (int j = i + 1; j < k; j++)
                if (m[make_pair(arr[i], arr[j])])
                {
                    flag = false;
                    break;
                }
        }

        if (flag)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}