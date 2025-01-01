#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
// leetcode 3367
// subans[it]-sum of weights of edges in subtree of it
// subsize[it]-no of nodes in subtree of it
void dfs1(int currnode, int parent, vector<pair<int, int>> adj[], vector<int> &subans, vector<int> &subsize)
{
    subsize[currnode] = 1;
    for (auto it : adj[currnode])
    {
        if (it.first != parent)
        {
            dfs1(it.first, currnode, adj, subans, subsize);
            subans[currnode] += subans[it.first] + it.second;
            // it.first-neighbour node and it.second weight
            subsize[currnode] += subsize[it.first];
        }
    }
}
void dfs2(int currnode, int parent, vector<pair<int, int>> adj[], vector<int> &subans, vector<int> &subsize, int &maxi, int k)
{
    int n = subans.size();
    int totalweight = subans[0];
    for (auto it : adj[currnode])
    {
        if (it.first != parent)
        {
            // removing edge
            // check new subtree size  parent and child ka
            int new_size = n - subsize[it.first];
            if (new_size <= k && subsize[it.first] <= k)
            {
                int newsum = totalweight+subans[it.first] - it.second;
                maxi = max(maxi, newsum);
            }
            dfs2(it.first, currnode, adj, subans, subsize, maxi, k);
        }
    }
}
long long maximizeSumOfWeights(vector<vector<int>> &edges, int k)
{
    int n = edges.size() + 1;
    vector<pair<int, int>> adj[n];
    vector<int> subans(n, 0);
    vector<int> subsize(n, 0);
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs1(0, -1, adj, subans, subsize);
    if (subsize[0] <=k)
    {
        return subans[0];
    }
    int maxi =INT_MIN;
    dfs2(0, -1, adj, subans, subsize, maxi, k);
    return maxi;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>>edges={{0, 1, 4}, {0, 2, 2}, {2, 3, 12}, {2, 4, 6}};
    cout<<maximizeSumOfWeights(edges,2);
    return 0;
}