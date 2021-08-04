#include <cstdio>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

struct node
{
    string sch;
    int score, num;
};

bool cmp(node a, node b)
{
    if (a.score != b.score)
        return a.score > b.score;
    else if (a.num != b.num)
        return a.num < b.num;
    else
        return a.sch < b.sch;
}

int main()
{
    int n;
    cin >> n;

    unordered_map<string, int> sum;
    unordered_map<string, int> cnt;

    for (int i = 0; i < n; i++)
    {
        string id, sch;
        double score;
        cin >> id >> score >> sch;

        for (int j = 0; j < sch.size(); j++)
        {
            if (sch[j] <= 'Z')
                sch[j] += 32;
        }

        if (id[0] == 'B')
            score /= 1.5;
        else if (id[0] == 'T')
            score *= 1.5;

        sum[sch] += score;
        cnt[sch]++;
    }

    vector<node> ans;
    for (auto it : cnt)
        ans.push_back(node{it.first, (int)sum[it.first], it.second});
    sort(ans.begin(), ans.end(), cmp);

    cout << ans.size() << endl;
    int rank = 0;
    int pre = -1;
    for (int i = 0; i < ans.size(); i++)
    {
        if (i != 0 && ans[i].score == ans[i - 1].score)
        {
            rank = pre;
        }
        else
        {
            rank = i + 1;
            pre = rank;
        }

        cout << rank << ' ' << ans[i].sch << ' ' << ans[i].score << ' ' << ans[i].num << endl;
    }

    return 0;
}