// 基于 栈 + 回溯 的 深度优先搜索

#include <bits/stdc++.h>
using namespace std;

int n;
int k = 1; // 递归深度
bool mark[6][6];
int path[26][3];

int dx[5] = {0, 0, 1, 0, -1};
int dy[5] = {0, 1, 0, -1, 0};

stack<pair<int, int>> s;

int main()
{
    cin >> n;

    mark[1][1] = true;
    s.push({1, 1});
    path[k][1] = 1;
    path[k][2] = 1;

    while (!s.empty())
    {
        {
        }
    }

    return 0;
}
