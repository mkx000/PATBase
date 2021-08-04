#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int A, B;
    scanf("%d%d", &A, &B);

    string s = to_string(A * B);

    reverse(s.begin(), s.end());
    printf("%d", stoi(s));
    return 0;
}