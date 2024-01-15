#include <iostream>
#include <string>
#include <vector>
#include<queue>
using namespace std;
// for connected
bool detectCycle(int V, vector<int> adj[])
{
    vector<int> visited(V, 0);
    vector<int> parent(V, -1);
    queue<int> q;
    q.push(0);
    visited[0]=1;
    while (!q.empty()) 
    {
        int Node = q.front();
        q.pop();
        for (auto it : adj[Node])
        {
            if(!visited[it])
            {
                q.push(it);
                visited[it] =1;
                parent[it]=Node;
            }
            // focus on this statement very important
            else if(it!=parent[Node])
            {
                return true;
            }
           
        }
    }
    return false;
    // Write your code here.
}
int main()
{
    int n,m;
    cin>>n>>m;
    vector<int>adjlist[n];
   
    // nodes 0 based
    for (int i = 0; i <m; i++)
    {
        int u,v;
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
        /* code */
    }
   
    // kisi node ke neighbours pr taverse krne ke liy
    bool b=detectCycle(n,adjlist);
    cout<<b;
    
   
    return 0;
}