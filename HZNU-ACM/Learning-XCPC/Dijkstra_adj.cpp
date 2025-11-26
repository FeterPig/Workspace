// 基于 贪心 + 优先队列 使用 邻接表 实现的 Dijkstra 算法
// 实际上一般采用的的都是邻接表

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

    vector<vector<pair<int, long long>>> adj(n + 1); // {目标节点, 权重}
    vector<long long> dist(n + 1, INF);              // 从起点到各点的距离
    vector<bool> marked(n + 1, false);               // 标记节点是否已确定最短路

    for (int i = 0; i < m; i++)
    {
        int u, v;
        long long w;

        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dist[1] = 0;

    // 优先队列，小顶堆，存储 {距离, 节点编号}
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;
    q.push({dist[1], 1});

    while (!q.empty())
    {
        // 1. 取出当前距离最短的节点
        long long d = q.top().first;
        int now = q.top().second;
        q.pop();

        // 2. 剪枝：如果该节点已被处理过，或者有更短的路径已经到达过它，则跳过
        if (marked[now] || d > dist[now])
        {
            continue;
        }
        else
        {
            // 3. 标记该节点为已确定最短路
            marked[now] = true;
        }

        // 4. 松弛操作：遍历该节点的所有邻居
        for (auto x : adj[now])
        {
            int next = x.first;
            long long w = x.second;

            // 如果邻居next未被标记，并且通过now可以使得到达next的路径更短
            if (!marked[next] && dist[next] > dist[now] + w)
            {
                // 更新最短距离
                dist[next] = dist[now] + w;
                // 将更新后的节点放入优先队列
                q.push({dist[next], next});
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
