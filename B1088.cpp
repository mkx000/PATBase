#include <cstdio>
#include <iostream>

using namespace std;
int M, X, Y;

bool judge(int n)
{
    int o, p;
    o = (n % 10) * 10 + n / 10;
    int cha = (n > o ? n - o : o - n);
    if (cha % X != 0)
        return false;
    p = cha / X;

    if (o == p * Y)
        return true;
    else
        return false;
}

int main()
{
    scanf("%d%d%d", &M, &X, &Y);

    for (int n = 99; n > 0; n--)
    {
        if (judge(n))
        {
            int o = (n % 10) * 10 + n / 10;
            int p = (n > o ? n - o : o - n) / X;

            printf("%d", n);
            int arr[3];
            arr[0] = n;
            arr[1] = o;
            arr[2] = p;
            for (int i = 0; i < 3; i++)
            {
                if (arr[i] < M)
                    printf(" Gai");
                else if (arr[i] == M)
                    printf(" Ping");
                else
                    printf(" Cong");
            }

            return 0;
        }
    }

    printf("No Solution");
    return 0;
}