#include <cstdio>
#include <iostream>
#include <string>

using namespace std;
typedef long long ll;

ll L, K;

bool isPrime(ll a)
{
    if (a == 0 || a == 1)
        return false;
    for (ll i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
            return false;
    }

    return true;
}

int main()
{
    string N;

    cin >> L >> K >> N;

    for (int i = 0; i < L - K + 1; i++)
    {
        ll tmp = (ll)stoi(N.substr(i, K));
        if (isPrime(tmp))
        {
            cout << N.substr(i, K);
            return 0;
        }
    }

    cout << "404";
    return 0;
}