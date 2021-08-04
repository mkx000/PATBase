#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int arr[1010] = {0};

int main()
{

    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int num;
            cin >> num;
            arr[j] += num;
        }
    }

    int maximum = *max_element(arr, arr + N); //使用了max_element()这个函数 一般返回迭代器或者指针
    vector<int> ans;
    for (int i = 0; i < N; i++)
    {
        if (arr[i] == maximum)
            ans.push_back(i + 1);
    }

    cout << maximum << endl;
    bool first = true;
    for (auto it : ans)
    {
        if (first)
            first = false;
        else
            cout << ' ';
        cout << it;
    }

    return 0;
}