#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int timer=1;
void dfs(int currNode,int parent,vector<int>adj[],vector<int>&vis,vector<int>&time,vector<int>&low,vector<vector<int>>&bridges)
{
    vis[currNode]=1;
    time[currNode]=timer;
    low[currNode]=timer;
    timer++;
    for(auto it:adj[currNode])
    {
        if(it==parent)
        {
            continue;
        }
        if(!vis[it])
        {
            dfs(it,currNode,adj,vis,time,low,bridges);
            low[currNode]=min(low[currNode],low[it]);
            if(low[it]>time[currNode])
            {
                // bridge h
                bridges.push_back({currNode,it});
            }

        }
        else
        {
            low[currNode]=min(low[currNode],low[it]);

        }
    }

    
}
vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    // create adjacency list
    vector<int>adj[n];
    for (int i = 0; i <connections.size(); i++)
    {
        int u=connections[i][0];
        int v=connections[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
        /* code */
    }
    vector<int>vis(n,0);
    vector<int>time(n);
    // the steps to reach a node
    vector<int>low(n);
    // low vertex that can be reached from currentVertex
    vector<vector<int>>bridges;
    dfs(0,-1,adj,vis,time,low,bridges);
    return bridges;


}
int main()
{
     vector<vector<int>>connections={{0,1},{1,2},{2,0},{1,3}};
     vector<vector<int>>ans=criticalConnections(4,connections);
     for (int i = 0; i <ans.size(); i++)
     {
        for (int j = 0; j <ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
            /* code */
        }
        cout<<endl;
        
        /* code */
     }
     

    return 0;
}