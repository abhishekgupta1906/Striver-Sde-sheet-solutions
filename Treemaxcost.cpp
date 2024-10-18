#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#define int long long
using namespace std;
// https://codeforces.com/problemset/problem/1092/F
void bfs(int src, vector<int> adj[], vector<int> &dist, int n)
{
    dist[src] = 0;
    vector<int> visited(n, 0);
    visited[src] = 1;
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int currnode = q.front();
        q.pop();
        for (auto neighbour : adj[currnode])
        {
            if (!visited[neighbour])
            {
                dist[neighbour] = dist[currnode] + 1;
                q.push(neighbour);
                visited[neighbour] = 1;
            }
        }
    }
}
signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int>a(n);
    vector<int>adj[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        /* code */
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        /* code */
    }
    vector<int> dist1(n);
    bfs(0, adj, dist1, n);
    // end points
    int maxdist = 0;
    // 1st end point
    int maxnode1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (dist1[i] > maxdist)
        {
            maxdist = dist1[i];
            maxnode1 = i;
        }
        /* code */
    }
    vector<int> dist2(n);
    bfs(maxnode1, adj, dist2, n);
    // end points
    maxdist = 0;
    // 1st end point
    int maxnode2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (dist2[i] > maxdist)
        {
            maxdist = dist2[i];
            maxnode2 = i;
        }
        /* code */
    }
    // dist 1 koi kaam nhi
    dist1.clear();
    dist1.assign(n, 0);
    bfs(maxnode2, adj, dist1, n);
    int maxcost1 = 0;
    int maxcost2 = 0;
    for (int i = 0; i < n; i++)
    {
        maxcost1 += a[i] * dist1[i];
        maxcost2 += a[i] * dist2[i];
        /* code */
    }
    cout << max(maxcost1, maxcost2) << "\n";

    return 0;
}