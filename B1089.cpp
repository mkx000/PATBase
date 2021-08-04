#include <cstdio>
#include <iostream>
#include <utility>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;
int N;
int arr[110];
int a[110] = {0};

typedef pair<int, int> p;
map<p, bool> m;

bool operator<(p p1, p p2)
{
    if (p1.first != p2.first)
        return p1.first < p2.first;
    if (p1.second != p2.second)
        return p1.second < p2.second;
    return true;
}

bool judge()
{
    int recWolf = 0, recNor = 0; //分别记录狼人和好人撒谎的人数
    for (int i = 1; i < N + 1; i++)
    {
        if (a[i] == 1) //第i个人为狼人
        {
            if (arr[i] > 0 && a[arr[i]] == 0)
                ;
            else if (arr[i] < 0 && a[-arr[i]] == 1)
                ;
            else
                recWolf++;
        }
        else
        {
            if (arr[i] > 0 && a[arr[i]] == 0)
                ;
            else if (arr[i] < 0 && a[-arr[i]] == 1)
                ;
            else
                recNor++;
        }
    }

    return recNor == 1 && recWolf == 1; //狼人和好人各有一个人撒谎
}

int main()
{
    scanf("%d", &N);
    for (int i = 1; i < N + 1; i++) //假定没有解
    {
        for (int j = i + 1; j < N + 1; j++)
            m[make_pair(i, j)] = false;
    }

    for (int i = 1; i < N + 1; i++)
        scanf("%d", &arr[i]);

    //假定无解
    for (auto it : m)
    {
        memset(a, 0, sizeof(a));
        int f = it.first.first, s = it.first.second;
        a[f] = 1;
        a[s] = 1;

        if (judge())
        {
            printf("%d %d", f, s);
            return 0;
        }
    }

    printf("No solution");
    return 0;
}