#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#define int long long
using namespace std;
void dijkstra(int src,vector<pair<int,int>>adj[],vector<int>&dist,vector<int>&parent)
{
    // using min priority queue
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
    pq.push({0,src});
    // dist ,then node
    while(!pq.empty())
    {
        int currNode = pq.top().second;
        pq.pop();
        for(auto it:adj[currNode])
        {
            // it adjacent node h
            int adjNode=it.first;
            int wt=it.second;
            if(dist[currNode]+wt<dist[adjNode])
            {
                dist[adjNode]=dist[currNode]+wt;
                parent[adjNode]=currNode;
                pq.push({dist[adjNode],adjNode});
            }
        }
    }
}
signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    //    zero based directed graph
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >>c;
        a--;
        b--;
        adj[a].push_back({b, c});

        /* code */
    }
    vector<int>dist(n,LLONG_MAX);
    dist[0]=0;
    vector<int>parent(n);
    for (int i = 0; i <n; i++)
    {
        parent[i] = i;
        /* code */
    }
    dijkstra(0,adj,dist,parent);
    int maxcost=0;
    int node=n-1;
    while(parent[node]!=node)
    {
        int p=parent[node];
        for(auto it:adj[p])
        {
            if(it.first==node)
            {
                maxcost=max(maxcost,it.second);
            }
        }
        node=parent[node];
    }
    cout<<dist[n-1]-maxcost+(maxcost)/2;
    

    return 0;
}