#include<iostream>
#include<string>
#include<vector>
#include <bits/stdc++.h>
using namespace std;
// no of ways to reach n-1 from 0 in shortest amount of time,which means total no of shortest paths from 0 to n-1
// typedef long long int ll;
// const ll m = 1e9 + 7;
int numberOfWays(int n, int m, vector<vector<int>>&roads)
{
    int mod = 1e9 + 7;
    vector<pair<int, int> >adj[n];
    priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> pq;
    vector<long>distance(n,LONG_MAX);
    vector<long>path(n,0);
    for (int i = 0; i <roads.size(); i++)
    {
        int u=roads[i][0];
        int v=roads[i][1];
        int weights = roads[i][2];
        adj[u].push_back({v,weights});
        adj[v].push_back({u,weights});
        /* code */
    }
    distance[0]=0;
    path[0]=1;
    // distance of src from src
    pq.push({0,0});
    while(!pq.empty())
    {
        long dist=pq.top().first;
        int node=pq.top().second;
        pq.pop();
        for (auto it:adj[node])
        {
            int adjnode=it.first;
            int edgeweight=it.second;
            // first time adj node pr paunche h
            if(dist + edgeweight < distance[adjnode])
            {
                distance[adjnode]=dist + edgeweight;
                pq.push({distance[adjnode],adjnode});
                path[adjnode]=path[node];

            }
            // adjnode pr pehle bhi paunch chuke h
            else if(dist + edgeweight==distance[adjnode])
            {
                path[adjnode]=(path[node]+path[adjnode])%mod;
            }
            /* code */
        }
        
    }
    return path[n-1]%mod;
    // Write your code here
}

int main()
{
    vector<vector<int>>edges={ {0,6,7 } , {0,1,2 }, {1,2,3 }, {1,3,3 }, {6,3,3 }, {3,5,1 }, {6,5,1 }, {2,5,1 }, {0,4,5 }, {4,6,2 }};
    int ans=numberOfWays(7,10,edges);
    cout<<ans;  
    
return 0;
}