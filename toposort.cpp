#include<iostream>
#include<string>
#include<vector>
#include<stack>
using namespace std;
// topo sort
// condition-directed cyclic graph
// linear ordering ,agar manlo u and v ke beech edge h u pehle print hona chaiye
// stack use kr rhe h toh print hoga wo last me push hoga
void dfs(vector<vector<int>> &graph,int src,vector<int>&visited,stack<int>&st)
{
    visited[src]=1;
      for (int i : graph[src]) {
        if (!visited[i]) {
            dfs(graph,i,visited,st);
        }
    }
 
    st.push(src);
    
}
vector<int> topologicalSort(vector<vector<int>> &graph, int edges, int nodes) 
{
    vector<int>ans;
    vector<int>visited(nodes,0);
    stack<int>st;
    for (int i = 0; i <nodes; i++)
    {
        if(!visited[i])
        {
            dfs(graph,i,visited,st);
        }
        /* code */
    }
    while(!st.empty())
    {
        int value=st.top();
        st.pop();
        ans.push_back(value);
    }
    return ans;
    

    // Write your code here!
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>graph;
   
   
    // nodes 0 based
    for (int i = 0; i <m; i++)
    {
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
       
    }
    vector<int>ans=topologicalSort(graph,m,n);
    

    
return 0;
}