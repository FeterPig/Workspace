#include <bits/stdc++.h>
using namespace std;

#define int long long

// 没招了, 试试传引用
bool cmp(const vector<int> &x, const vector<int> &y)
{
    if (x[2] != y[2])
    {
        return x[2] < y[2];
    }
    return x[1] > y[1];
}

bool cmp_1(const vector<int> &x, const vector<int> &y)
{
    if (x[1] != y[1])
    {
        return x[1] < y[1];
    }
    return x[0] < y[0];
}

#undef int

int main()
{
#define int long long

    // 优化cin效率
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; // n个岛屿
    int m; // m个桥
    cin >> n >> m;

    int dyzb[2];                                   // 岛屿坐标 [左/右]
    vector<int> dy;                                // 岛屿长度
    vector<vector<int>> dyzb_v(n, vector<int>(2)); // 岛屿坐标 [左/右]
    vector<vector<int>> qiao(m, vector<int>(2));   // 桥的编号/长度 (1-base)

    for (int i = 0; i < n; i++)
    {
        cin >> dyzb[0] >> dyzb[1];

        dy.push_back(dyzb[1] - dyzb[0]);
        dyzb_v[i][0] = (dyzb[0]);
        dyzb_v[i][1] = (dyzb[1]);
    }

    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        qiao[i][0] = (i + 1);
        qiao[i][1] = (temp);
    }

    vector<vector<int>> qiao_min_max(n - 1, vector<int>(3)); // 桥的索引/长度区间 (1-base) (两边都是闭区间)
    for (int i = 0; i < n - 1; i++)
    {
        qiao_min_max[i][0] = i + 1;
        qiao_min_max[i][1] = dyzb_v[i + 1][0] - dyzb_v[i][1];
        qiao_min_max[i][2] = qiao_min_max[i][1] + dy[i] + dy[i + 1];
    }

    // 贪心?

    sort(qiao_min_max.begin(), qiao_min_max.end(), cmp);
    sort(qiao.begin(), qiao.end(), cmp_1);

    vector<int> ans(n, 0); // 1-base

    int ii = 0;
    int j = 0;

    while (ii < n - 1 && j < m)
    {
        if (qiao[j][1] >= qiao_min_max[ii][1] && qiao[j][1] <= qiao_min_max[ii][2])
        {
            ans[qiao_min_max[ii][0]] = qiao[j][0];
            ii++;
            j++;
        }
        else
        {
            j++;
        }
    }

    if (ii < n - 1)
    {
        cout << "No\n";
    }
    else
    {
        cout << "Yes\n";
        for (int k = 1; k <= n - 1; k++)
        {
            if (k != 1)
            {
                cout << " ";
            }
            cout << ans[k];
        }
        cout << "\n";
    }

    return 0;
}