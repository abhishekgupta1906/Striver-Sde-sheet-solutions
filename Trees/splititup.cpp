#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
void dfs1(int currnode, int parent, vector<int> adj[], vector<int> &subtree)
{
    for (auto it : adj[currnode])
    {
        if (it != parent)
        {
            dfs1(it, currnode, adj, subtree);
            subtree[currnode] += subtree[it];
        }
    }
    subtree[currnode] += (currnode + 1);
}
void dfs2(int currnode, int parent, vector<int> adj[], vector<int> &subtree, int&mini)
{
    for (auto it : adj[currnode])
    {
        // after removing the edge
        if (it != parent)
        {
            int val = subtree[0] - subtree[it];
            mini = min(mini, val - subtree[it]);
            dfs2(it, currnode, adj, subtree, mini);
        }
    }
}
int main()
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
    vector<int> subtree(n, 0);
    int mini = INT_MAX;
    dfs1(0, -1, adj, subtree);
    dfs2(0, -1, adj, subtree, mini);
    cout << mini;

    return 0;
}