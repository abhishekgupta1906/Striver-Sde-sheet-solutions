#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#define int long long
using namespace std;
void dfs(int currnode, vector<int> adj[], vector<int> &parent, int p)
{
    parent[currnode] = p;
    for (auto neighbour : adj[currnode])
    {
        if (neighbour!= p)
        {
            dfs(neighbour, adj, parent, currnode);
        }
    }
}
int find_kthparent(int x,int k, vector<vector<int>> &parent)
{
    for (int i = 0; i <= log2(k); i++)
    {
        if (k & (1 << i))
        {
            x = parent[i][x];
            if(x==-1)
            {
                return -1;
            }
        }
        /* code */
    }
    return x;
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
    // parent[k][i]
    // parent[2][5]=5 ka 2^2 parent,or 5 ka 4th parent
    // 1st parent array calculated
    // parent[0],first parent array of each node
    dfs(0, adj, parent[0], -1);
    // 2nd of parent of x=1st parent(1st parent of x)
    // 2^k-1(2^k-1 parent of x)
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
        int x, k;
        cin >> x >> k;
        x--;
        int ans = find_kthparent(x,k,parent);
        if(ans==-1)
        {
            cout<<ans<<'\n';
        }
        else
        {
            cout<<ans+1<<"\n";

        }
        /* code */
    }
   

    return 0;
}