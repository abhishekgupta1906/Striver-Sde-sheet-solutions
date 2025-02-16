#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
map<int,int>mp;
void dfs1(int node, int parent, vector<vector<pair<int, int>>> &adj, vector<int> &prefix)
{
    for (auto it : adj[node])
    {
        if (it.first != parent)
        {
            prefix[it.first] = prefix[node] + it.second;
            dfs1(it.first, node, adj, prefix);
        }
    }
}


void longestSpecialPath(vector<vector<int>> &edges, vector<int> &nums)
{
    // vector<pair<int,int>ans=for each longest path and no nodes ok aur ek baat downward path hmesha har node lowest mankr kitna upar ja skte h
    // vector<int>prefix-sum of weights till that node
    // mp-for storing last accurence of a particular node
    int n = edges.size() + 1;
    vector<pair<int, int>> ans(n);
    vector<int> prefix(n, 0);
    vector<vector<pair<int, int>>> adj(n);
    map<int,int>mp;
    vector<int> arr;
    prefix[0] = 0;
    // build adjacency list
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        /* code */
    }
   
    dfs1(0, -1, adj, prefix);
    // passed
    int last=0;
    dfs2(0, -1, adj, prefix,arr, ans, nums,last);
    for (auto it : ans)
    {
        cout << it.first << " " << it.second << " ";
    }
    sort(ans.begin(), ans.end());
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> edges = {{1, 0, 5}, {0, 2, 10}};
    vector<int> nums = {3,3,5};
    longestSpecialPath(edges, nums);

    return 0;
}