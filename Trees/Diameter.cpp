#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#define int long long
using namespace std;
void bfs(int src, vector<int> adj[], vector<int> &dist, int n)
{
    dist[src] = 0;
    vector<int> visited(n, 0);
    visited[src] = 1;
    queue<int>q;
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
    vector<int> adj[n];
    for (int i = 0;i<n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        /* code */
    }
    vector<int> dist1(n, 0);
    bfs(0, adj, dist1, n);
    int maxnode = 0;
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        if (dist1[i] > maxi)
        {
            maxi = dist1[i];
            maxnode = i;
        }
        /* code */
    }
    vector<int> dist2(n, 0);
    bfs(maxnode, adj, dist2, n);
    maxi = 0;
    for (int i = 0; i < n; i++)
    {
        if (dist2[i] > maxi)
        {
            maxi = dist2[i];
           
        }
        /* code */
    }
    cout<<maxi<<"\n";

    return 0;
}