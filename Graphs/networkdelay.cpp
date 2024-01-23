#include<iostream>
#include<string>
#include<vector>
using namespace std;
// minimum time taken to reach all nodes,or time taken to reach to farthest node
int networkDelayTime(vector<vector<int>> &edges, int n, int k)
{
   vector<pair<int, int> >adj[n+1];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int>distance(n+1,INT_MAX);
    for (int i = 0; i <edges.size(); i++)
    {
        int u=edges[i][0];
        int v=edges[i][1];     
        int time = edges[i][2];
        adj[u].push_back({v,time});
        // adj[v].push_back({u,weights});
        /* code */
    }
    distance[k]=0;
    // distance of src from src
    pq.push({0,k});
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
    // minimum time taken to reach farthes node
    int t=0;
    for(int i=1;i<=n;i++)
    {
        if(distance[i]==INT_MAX)
        {
            return -1;
        }
        t=max(distance[i],t);
    }
    return t;
   
    // Write your code here.
}
int main()
{
    
return 0;
}