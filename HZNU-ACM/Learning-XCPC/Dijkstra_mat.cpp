// 基于 贪心 + 优先队列 使用 邻接矩阵 实现的 Dijkstra 算法

/*题目描述
给出一张由 n 个点 m 条边组成的无向图。

求出从第一个点到所有点 (1,j) 之间的最短路径。

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

    vector<vector<long long>> mat(n + 1, vector<long long>(n + 1, INF));
    // 节点 i 的最短路径是否已确定
    vector<bool> marked(n + 1, false);
    // 起点到节点 i 的当前已知最短距离
    vector<long long> dist(n + 1, INF);
    dist[1] = 0;

    int u, v;
    long long w;

    // 初始化邻接矩阵
    for (int i = 1; i <= n; i++)
    {
        mat[i][i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;

        mat[u][v] = min(mat[u][v], w);
        mat[v][u] = min(mat[v][u], w);
    }

    // 定义优先队列 q（小顶堆），用于存放 {距离, 节点编号}
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    q.push({dist[1], 1});

    while (!q.empty())
    {
        // 1. 取出当前距离最短的节点
        long long d = q.top().first;
        int s = q.top().second;
        q.pop();

        // 2. 剪枝：如果该节点已被处理过，或者有更短的路径已经到达过它，则跳过
        if (marked[s] || d >= dist[s])
        {
            continue;
        }
        else
        {
            // 3. 标记该节点为已确定最短路
            marked[u] = true;
        }

        // 4. 松弛操作：遍历该节点的所有邻居
        for (int i = 1; i <= n; i++)
        {
            // 松弛条件：
            // 1. 节点 i 的最短路径尚未确定 (!marked[i])
            // 2. 从 s 到 i 存在一条边 (mat[s][i] != INF)
            // 3. 通过 s 中转到达 i 的新路径 (d + mat[s][i]) 比当前记录的 dist[i] 更短
            if (!marked[i] && mat[s][i] != INF && dist[i] > d + mat[s][i])
            {
                // 更新 i 的最短距离
                dist[i] = d + mat[s][i];
                // 将更新后的 {新距离, 节点 i} 放入优先队列
                q.push({dist[i], i});
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (dist[i] == INF)
        {
            cout << "INF ";
        }
        else
        {
            cout << dist[i] << " ";
        }
    }
    cout << endl;

    return 0;
}
