#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#define int long long
using namespace std;
// in[x]-sum of distances of all nodes from x,where nodes in the subtree of it
// dp[x]-sum of distances of all nodes from x
void dfs1(int currnode, vector<int> adj[], int parent, vector<int> &subtreesize, vector<int> &in)
{
    subtreesize[currnode] = 1;

    for (auto it : adj[currnode])
    {
        if (it != parent)
        {
            dfs1(it,adj,currnode,subtreesize,in);
            subtreesize[currnode] += subtreesize[it];
            in[currnode] += in[it] + subtreesize[it];
        }
    }
}
void dfs2(int currnode, vector<int> adj[], int parent, vector<int> &subtreesize, vector<int> &dp, int n)
{

    for (auto it : adj[currnode])
    {
        if (it != parent)
        {
            dp[it] = n - 2 * subtreesize[it] + dp[currnode];
            // in[it]+dp[currnode]-in[it]-subtreesize[it]+n-subtreesixe[it]
            dfs2(it, adj, currnode, subtreesize, dp, n);
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
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);

        /* code */
    }
    vector<int> subtreesize(n);
    vector<int>in(n,0);
    vector<int>dp(n);
    dfs1(0,adj,-1,subtreesize,in);
    dp[0]=in[0];
    dfs2(0,adj,-1,subtreesize,dp,n);
    for (int i = 0; i <n; i++)
    {
        cout<<dp[i]<<" ";
        /* code */
    }
    

    return 0;
}