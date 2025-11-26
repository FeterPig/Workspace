// 基于 动态规划 的 Floyd 算法
// 由于是 dp 所以必须用邻接矩阵

/*题目描述
给出一张由 n 个点 m 条边组成的无向图。

求出所有点对 (i,j) 之间的最短路径。

输入格式
第一行为两个整数 n,m，分别代表点的个数和边的条数。

接下来 m 行，每行三个整数 u,v,w，代表 u,v 之间存在一条边权为 w 的边。*/

#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e15;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<long long>> dist(n + 1, vector<long long>(n + 1, INF));

    for (int i = 1; i <= n; i++)
    {
        dist[i][i] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long w;
        cin >> u >> v >> w;

        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
    }

    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF)
                {
                    dist[i][j] = min(dist[i][k] + dist[k][j], dist[i][j]);
                }
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << i << " -> " << j << " : " << dist[i][j] << "    ";
        }
        cout << endl;
    }

    return 0;
}