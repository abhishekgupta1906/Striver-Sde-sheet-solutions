#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
// cycle detection in directed graph using kahn algorithm
bool detectCycleInDirectedGraph(int n, vector<pair<int, int>> &edges)
{
    // for adjacency list
   unordered_map<int, list<int>> adj;

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;

        adj[u].push_back(v);
    }
    // indegree
    // nodes
    vector<int> indegree1(n + 1, 0);
    for (int i = 1; i < n + 1; i++)
    {
        for (auto it:adj[i])
        {
            indegree1[it]++;
            /* code */
        }

        /* code */
    }
    // push in the queue
    queue<int> q;
    int count = 0;

    for (int i = 1; i < n + 1; i++)
    {
        if (indegree1[i] == 0)
        {
            q.push(i);
        }
        /* code */
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;
        for (auto it:adj[node])
        {
            indegree1[it]--;
            if (indegree1[it] == 0)
            {
                q.push(it);
            }
            /* code */
        }
    }
    // cannot find topo sort
    if (count < n)
    {
        return true;
        // cyclic
    }
    return false;

    // Write your code here.
}
int main()
{

    return 0;
}