#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#define int long long
using namespace std;
// binary search wla approach
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
bool check(int x, int y, int mid, vector<vector<int>> &parent)
{
    int kpx = find_kthparent(x, mid, parent);
    int kpy = find_kthparent(y, mid, parent);
    if (kpx == kpy)
    {
        return true;
    }
    return false;
}
signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> adj[n];
    for (int i = 1; i <= n - 1; i++)
    {
        int x;
        cin >> x;
        x--;
        adj[i].push_back(x);
        adj[x].push_back(i);

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
        int ans = 0;
        int high=min(depth[x],depth[y]);
        int low = 0;
        while (low<= high)
        {
            int mid = low + (high - low) / 2;
            if (check(x, y, mid, parent))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        int lca= find_kthparent(x, ans, parent);
        cout<<lca+1<<"\n";

      

        /* code */
    }

    return 0;
}