#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;
const int maxn = 1e5 + 10;
int arr[maxn] = {0};

int main()
{
    int n, k, t1, t2;
    map<int, vector<int> > m;

    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
    {
        scanf("%d%d", &t1, &t2);
        m[t1].push_back(t2);
        m[t2].push_back(t1);
    }

    while (k--)
    {
        memset(arr, sizeof(arr), 0);
        int K;
        scanf("%d", &K);

        vector<int> tmp(K);
        for (int i = 0; i < K; i++)
        {
            scanf("%d", &tmp[i]);
            arr[tmp[i]] = 1; //以空间换时间
        }

        bool flag = true;
        for (int i = 0; i < K && flag; i++)
        {
            for (int j = 0; j < m[tmp[i]].size(); j++)
            {
                if (arr[m[tmp[i]][j]] == 1)
                {
                    flag = false;
                    break;
                }
            }
        }

        printf("%s\n", flag ? "Yes" : "No");
    }

    return 0;
}