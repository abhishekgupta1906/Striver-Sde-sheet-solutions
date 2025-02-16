#include <iostreaM>
#include <bits/stdc++.h>
using namespace std;
void bfs(int src, vector<vector<int>> &adj, vector<int> &dist)
{
    dist[src] = 0;
    queue<int> q;
    q.push(src);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto it : adj[node])
        {
            if (dist[node] + 1 < dist[it])
            {
                dist[it] = dist[node] + 1;
                q.push(it);
            }
        }
    }
}
vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
{
    int n = numCourses;
    int m = queries.size();
    vector<bool> ans(m);
    vector<vector<int>> adj(n);

    vector<int> topo;
    if (prerequisites.size() == 0)
    {
        vector<bool> ans1(m, false);
        return ans1;
    }
    for (int i = 0; i < prerequisites.size(); i++)
    {
        int u = prerequisites[i][0];
        int v = prerequisites[i][1];
        adj[u].push_back(v);
    }
    // start bfs from each node
    vector<vector<int>> reach;
    for (int i = 0; i < n; i++)
    {
        vector<int> dist(n, INT_MAX);
        bfs(i, adj, dist);
        reach.push_back(dist);
    }

    for (int i = 0; i < queries.size(); i++)
    {
        int u = queries[i][0];
        int v = queries[i][1];
        if(reach[u][v]!=INT_MAX){
            ans[i]=true;
        }
        else{
            ans[i]=false;
        }
    }
    return ans;
}
int main()
{
    vector<vector<int>> pre = {};
    vector<vector<int>> queries = {{1, 0}, {0, 1}};
    vector<bool> ans = checkIfPrerequisite(2, pre, queries);
    for (auto it : ans)
    {
        cout << it << " ";
    }

    return 0;
}