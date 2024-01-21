#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include<climits>
using namespace std;
vector<int> shortestPath(int n, vector<vector<int>> &edges, int src)
{
    vector<int>visited(n,0);
    vector<int>dist(n,INT_MAX);
    vector<int>adj[n];

    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    // src
    dist[src]=0;
    visited[src]=1;

    // push in the queue
    queue<int> q;
    q.push(src);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();
       
        for (auto it : adj[node])
        {
            if(!visited[it])
            {
                if(dist[node]+1<dist[it])
                {
                    dist[it]=dist[node]+1;
                }
                q.push(it);
                visited[it]=1;
            }
            
            /* code */
        }
    }
    return dist;
    // cannot find topo sort

    // Write your code here.
}
int main()
{
    vector<vector<int>>edges={{0, 1 }   ,  { 1, 4 }   ,  { 2, 3 }   ,  { 2, 4 }   ,  {3, 4 } };
    vector<int>ans=shortestPath(5,edges,1);
    for (int i = 0; i <ans.size(); i++)
    {
        cout<<ans[i]<<" ";
        /* code */
    }
    


    return 0;
}