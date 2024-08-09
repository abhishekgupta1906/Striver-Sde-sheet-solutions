#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#define int long long
using namespace std;

void dfs(int currnode, vector<int> adj[], vector<int> &parent, vector<int> &depth, int p, int d)
{
    parent[currnode] = p;
    depth[currnode] = d;
    for (auto neighbour : adj[currnode])
    {
        if (neighbour != p)
        {
            dfs(neighbour, adj, parent, depth, currnode, d + 1);
        }
    }
}
int find_kthparent(int x, int k, vector<vector<int>> &parent)
{
    for (int i = 0; i <= log2(k); i++)
    {
        if (k & (1 << i))
        {
            x = parent[i][x];
            if (x == -1)
            {
                return -1;
            }
        }
        /* code */
    }
    return x;
}
int lca(int x, int y, vector<vector<int>> &parent, vector<int> &depth, int n)
{
    if (depth[y] > depth[x])
    {
        int val = depth[y] - depth[x];
        y = find_kthparent(y, val, parent);
    }
    else
    {
        int val = depth[x] - depth[y];
        x = find_kthparent(x, val, parent);
    }

    if (x == y)
    {
        return x;
    }
    for (int k = log2(n); k >= 0; k--)
    {
        int parent_x = parent[k][x];
        int parent_y = parent[k][y];
        if (parent_x != parent_y)
        {
            x = parent_x;
            y = parent_y;
        }
        /* code */
    }
    return parent[0][x];
}
signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> adj[n];
    for (int i =0; i <n - 1; i++)
    {
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        
        /* code */
    }
    vector<vector<int>> parent(log2(n) + 1, vector<int>(n, -1));

    vector<int> depth(n, 0);
    dfs(0, adj, parent[0], depth, -1, 0);

    for (int k = 1; k <= log2(n); k++)
    {
        for (int i = 0; i < n; i++)
        {
            int intermediate = parent[k - 1][i];
            // 1st parent of x
            if (intermediate != -1)
            {
                parent[k][i] = parent[k - 1][intermediate];
            }
            /* code */
        }

        /* code */
    }
    for (int i = 0; i < q; i++)
    {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        int lcaboth= lca(x, y, parent, depth, n);
        int ans=depth[x]+depth[y]-2*depth[lcaboth];
        cout<<ans<<"\n";

        /* code */
    }

    return 0;
}