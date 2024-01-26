#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <climits>
using namespace std;
// har bar wo vertex chaiye jiska weight minimum ho
int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    vector<int> visited(n, 0);
    vector<int> weight(n, INT_MAX);
    vector<pair<int, int>> adj[n];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int weights = edges[i][2];
        adj[u].push_back({v, weights});
        adj[v].push_back({u, weights});
        /* code */
    }
    weight[0] = 0;
    // distance of src from src
    pq.push({0, 0});
    while (!pq.empty())
    {  
        int node = pq.top().second;
        visited[node]=1;
        pq.pop();
        for (auto it : adj[node])
        {
            int adjnode = it.first;
            if (!visited[adjnode])
            {
                int edgeweight = it.second;
                if (edgeweight < weight[adjnode])
                {
                    weight[adjnode] =edgeweight;
                    pq.push({weight[adjnode], adjnode});
                }
            }

            /* code */
        }
    }
    int sum=0;
    for (int i = 0; i <n; i++)
    {
        /* code */
        sum=sum+weight[i];
    }
    return sum;
    
}
int main()
{
    vector<vector<int>>edges={{1,2,6},{2,3,2},{1,3,2},{1,0,2}};
    int ans=minimumSpanningTree(edges,4);
    cout<<ans;

    return 0;
}