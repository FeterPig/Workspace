#include <bits/stdc++.h>
using namespace std;

int n;
int cnt;
int k = 1;
bool mark[6][6];
int path[26][3];

int dx[5] = {0, 0, 1, 0, -1};
int dy[5] = {0, 1, 0, -1, 0};

void dfs(int x, int y)
{
    path[k][1] = x;
    path[k][2] = y;

    if (x == n && y == n)
    {
        return;
    }

    for (int i = 1; i <= 4; i++)
    {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (mark[tx][ty] == false && tx >= 1 && tx <= n && ty >= 1 && ty <= n)
        {
            k++;
            mark[tx][ty] = true;
            dfs(tx, ty);

            k--;
            mark[tx][ty] = false;
            path[k + 1][1] = 0;
            path[k + 1][2] = 0;
        }
    }
}

int main()
{
    cin >> n;

    mark[1][1] = true;
    dfs(1, 1);

    return 0;
}