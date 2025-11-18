// 广度优先搜索

#include <bits/stdc++.h>
using namespace std;

int n;
bool visited[6][6];
int mat[6][6];
queue<pair<int, int>> q;

int dx[5] = {0, 0, 1, 0, -1};
int dy[5] = {0, 1, 0, -1, 0};

void bfs()
{
    while (!q.empty())
    {
        pair<int, int> p = q.front();
        q.pop();

        int x = p.first;
        int y = p.second;

        // 如果到达目标点，可以在这里添加终止条件
        // if (x == target_x && y == target_y) return;

        for (int i = 1; i <= 4; i++)
        {
            int tx = x + dx[i];
            int ty = y + dy[i];

            if (mat[tx][ty] == false && tx >= 1 && tx <= n && ty >= 1 && ty <= n)
            {
                visited[tx][ty] = true;
                q.push({tx, ty});
            }
        }
    }
}

int main()
{
    cin >> n;

    visited[1][1] = true;
    q.push({1, 1});
    bfs();

    return 0;
}