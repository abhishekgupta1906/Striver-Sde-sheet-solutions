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
    vector<int> adj[n];
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        /* code */
    }
    vector<int>ans(n,0);
    vector<int> dist1(n, 0);
    bfs(0, adj, dist1, n);
    int maxnode1 = 0;
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        if (dist1[i] > maxi)
        {
            maxi = dist1[i];
            maxnode1 = i;
        }
        /* code */
    }
    // diameter ka end point
    vector<int> dist2(n, 0);
    bfs(maxnode1, adj, dist2, n);
    // diameter ka agla end point
    int maxnode2 = 0;
    maxi = 0;
    for (int i = 0; i < n; i++)
    {
        if (dist2[i] > maxi)
        {
            maxi = dist2[i];
            maxnode2 = i;
        }
        /* code */
    }
    // dist1 koi kaam nhi bs maxnode 1 nikalne ke liy tha
    // now dist1 is used to calculate the distance for maxnode2
    dist1.clear();
    dist1.assign(n,0);
    bfs(maxnode2, adj, dist1, n);
    for (int i = 0; i <n; i++)
    {
        ans[i]=max(dist1[i],dist2[i]);
        cout<<ans[i]<<" ";
        /* code */
    }
    


    return 0;
}