#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
// pair<bool,int> get_count(vector<int>adj[],vector<int>&visited,int src){
//     visited[src]=1;
//     queue<pair<int,int>>q;
//     q.push({src,-1});
//     int cyclic_count=INT_MAX;
//     int count=1;
//     while(!q.empty()){
//         int node=q.front().first;
//         int parent=q.front().second;
//         q.pop();
//         for(auto it:adj[node]){
//             if(!visited[it]){
//                 visited[it]=1;
//                 q.push({it,node});
//                 count++;
//             }
//             else if(it!=parent){
//                 cyclic_count=min(cyclic_count,count);
                
//             }
//         }
//     }
//     if(cyclic_count==INT_MAX){
//         return {false,0};
//     }
//     return {true,cyclic_count};
// }
int findShortestCycle(int n, vector<vector<int>> &edges)
{
    vector<int>adj[n+1];
    for(int i=0;i<edges.size();i++){
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
    int min_cycle=INT_MAX;
    for(int i=0;i<n;i++){
        vector<int>dist(n,-1);
        queue<pair<int,int>>q;
        dist[i]=0;
        q.push({i,-1});
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto it:adj[node]){
                if(dist[it]==-1){
                    dist[it]=dist[node]+1;
                    q.push({it,node});
                }
                else if(it!=parent){
                    // length
                    int cycle_length=dist[node]+dist[it]+1;
                    min_cycle=min(min_cycle,cycle_length);
                }
            }
        }
    }
    if(min_cycle==INT_MAX){
        return -1;
    }
    return min_cycle;
   
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>>edges={{1,3},{3,5},{5,7},{7,1},{0,2},{2,4},{4,0},{6,0},{6,1}};
    cout<<findShortestCycle(8,edges)<<endl;
    return 0;
}