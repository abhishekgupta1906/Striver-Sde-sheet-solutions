#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
int reachableNodes(vector<vector<int>> &edges, int maxMoves, int n)
{
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < edges.size(); i++)
    {
        adj[edges[i][0]].push_back({edges[i][1], edges[i][2] + 1});
        adj[edges[i][1]].push_back({edges[i][0], edges[i][2] + 1});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    vector<int> dist(n, INT_MAX);

    dist[0] = 0;
    pq.push({0, 0});

    while (!pq.empty())
    {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();

        for (auto it : adj[node])
        {
            int v = it.first;
            int w = it.second;
            if (dis + w < dist[v])
            {
                dist[v] = dis + w;

                pq.push({dis + w, v});
            }
        }
    }
    // calculate the number of nodes that are reachable
    // main crux har remaining moves mt nikalo
    // mtlb itne aur node reacable h
    int ans=0;
    for (int i =0; i <dist.size(); i++)
    {
        if(dist[i]<=maxMoves){
            ans++;
        }
        /* code */
    }
    for(int i=0;i<edges.size();i++){
        int u=edges[i][0];
        int v=edges[i][1];
        int w=edges[i][2];
        int left_rem=max(0LL,maxMoves-dist[u]);
        int right_rem=max(0LL,maxMoves-dist[v]);
        ans+=min(w,left_rem+right_rem);
        // iska mtlb man le left se 4 and right 5
        // but abe edge toh 3 toh 3 hi le skte h

       
    }
    return ans;
    
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> edges = {{0, 1, 10}, {0, 2, 1}, {1, 2, 2}};
    int ans=reachableNodes(edges,6,3);
    cout<<ans;
    return 0;
}