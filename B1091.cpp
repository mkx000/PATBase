#include <cstdio>
#include <iostream>
#include <string>

using namespace std;
typedef long long ll;
ll M;
ll arr[25];

int judge(ll n)
{
    ll m = n * n;
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 1e9; j *= 10)
        {
            if ((m * i) % j == n)
                return i;
        }
    }
    return 0;
}

int main()
{
    cin >> M;
    for (ll i = 0; i < M; i++)
        cin >> arr[i];

    for (ll i = 0; i < M; i++)
    {
        int num = judge(arr[i]);
        if (num == 0)
            cout << "No" << endl;
        else
            cout << num << ' ' << num * arr[i] * arr[i] << endl;
    }

    return 0;
}