#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    // build the graph
    int n=graph.size();
    vector<int>indegree(n);
    vector<vector<int>>adj(n);
    for(int i=0;i<graph.size();i++){
        for (int j = 0; j <graph[i].size(); j++)
        {
            adj[i].push_back(graph[i][j]);
            /* code */
        }
        
    }
    vector<vector<int>>revadj(n);
    for(int i=0;i<n;i++){
        for(auto it:adj[i]){
            revadj[it].push_back(i);
            indegree[i]++;
        }
    }
    queue<int>q;
    for(int i=0;i<n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    vector<int>ans;
    while(!q.empty()){
        int node=q.front();
        ans.push_back(node);
        q.pop();
        for(auto it:revadj[node]){
               indegree[it]--;
               if(indegree[it]==0){
                q.push(it);
               }
        }
    }
    return ans;
}
int main()
{
    int n;
    cin>>n;
    vector<vector<int>>graph;
    for(int i=0;i<n;i++){
        int m;
        cin>>m;
        for(int j=0;j<m;j++){
            int val;
            cin>>val;
            graph[i].push_back(val);
        }
    }
    
    return 0;
}