#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
// single source shortest path .
// not valid for -ve cycle and weights
vector<int> dijkstra(vector<vector<int>> &edge, int vertices, int edges, int source)
{
    // Write your code here.
    // 'edge' contains {u, v, distance} vectors.
    // adj list
    vector<pair<int, int> >adj[vertices];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int>distance(vertices,INT_MAX);
    for (int i = 0; i <edge.size(); i++)
    {
        int u=edge[i][0];
        int v=edge[i][1];
        int weights = edge[i][2];
        adj[u].push_back({v,weights});
        adj[v].push_back({u,weights});
        /* code */
    }
    distance[source]=0;
    // distance of src from src
    pq.push({0,source});
    while(!pq.empty())
    {
        int dist=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for (auto it:adj[node])
        {
            int adjnode=it.first;
            int edgeweight=it.second;
            if(dist + edgeweight < distance[adjnode])
            {
                distance[adjnode]=dist + edgeweight;
                pq.push({distance[adjnode],adjnode});

            }
            /* code */
        }
        
    }
    return distance;
    

}
int main()
{
    vector<vector<int>>edge={{0,1,5}, {0, 2, 8}, {1, 2, 9}, {1, 3, 2},{ 2, 3, 6}};
    vector<int>ans=dijkstra(edge,4,5,0);
    for (int i = 0; i <ans.size(); i++)
    {
        cout<<ans[i]<<" ";
        /* code */
    }
    
    
return 0;
}