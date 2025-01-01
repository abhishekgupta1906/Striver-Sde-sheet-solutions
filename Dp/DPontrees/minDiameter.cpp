#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
// min diameter after merging trees
void bfs(int src, vector<int> &dist, vector<int> adj[])
{
    queue<int> q;
    int n = dist.size();
    vector<int> visited(n, 0);
    q.push(src);
    visited[src] = 1;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (!visited[it])
            {
                dist[it] = dist[node] + 1;
                visited[it] = 1;
                q.push(it);
            }
        }
    }
}
pair<int, int> maxDistanceNode(vector<int> &dist)
{
    int maxNode = 0;
    int maxDist = 0;
    for (int i = 0; i < dist.size(); i++)
    {
        if (dist[i] > maxDist)
        {
            maxDist = dist[i];
            maxNode = i;
        }
        /* code */
    }
    return {maxDist, maxNode};
}
int minimumDiameterAfterMerge(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
{
    // build adjacency list
    int n = edges1.size() + 1;
    int m = edges2.size() + 1;

    vector<int> adj1[n];
    vector<int> adj2[m];
    // build tree 1
    for (int i = 0; i < edges1.size(); i++)
    {
        int u = edges1[i][0];
        int v = edges1[i][1];
        adj1[u].push_back(v);
        adj1[v].push_back(u);
        /* code */
    }
    // build tree 2
    for (int i = 0; i < edges2.size(); i++)
    {
        int u = edges2[i][0];
        int v = edges2[i][1];
        adj2[u].push_back(v);
        adj2[v].push_back(u);
        /* code */
    }
    // apply bfs on adj1
    vector<int> dist1(n, 0);
    bfs(0, dist1, adj1);
    pair<int, int> p = maxDistanceNode(dist1);
    vector<int> dist2(n, 0);
    bfs(p.second, dist2, adj1);
    pair<int, int> ans = maxDistanceNode(dist2);
    int d1 = ans.first;

    // apply bfs on adj2
    dist1.clear();
    dist1.resize(m, 0);
    bfs(0, dist1, adj2);
    pair<int, int> q = maxDistanceNode(dist1);
    dist2.clear();
    dist2.resize(m, 0);
    bfs(q.second, dist2, adj2);
    ans = maxDistanceNode(dist2);
    int d2 = ans.first;
    // dekh isme ceil lene ka reason copy me dekhna and dusra mereko overall tree ka bhi diameter nikalna h
    // iss question dono tree diameter ka divide kiye taki minium diameter a ske h
    return max({d1, d2, (d1 + 1) / 2 + (d2 + 1) / 2 + 1});
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}