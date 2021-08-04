#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
    int a, b;
    scanf("%d%d", &a, &b);

    int ans = a * b;

    while(ans % 10 == 0)
        ans /= 10;

    while(ans)
    {
        printf("%d", ans % 10);
        ans /= 10;
    }

    return 0;
}