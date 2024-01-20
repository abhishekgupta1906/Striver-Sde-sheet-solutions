#include <iostream>
#include <string>
#include <vector>
#include<queue>
using namespace std;
// apply topo sort
vector<int> toposort(int n, vector<int> adj[])
{
    
    vector<int> indegree1(n, 0);
    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
        {
            indegree1[it]++;
            /* code */
        }

        /* code */
    }
    // push in the queue
    queue<int> q;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (indegree1[i] == 0)
        {
            q.push(i);
        }
        /* code */
    }
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for (auto it : adj[node])
        {
            indegree1[it]--;
            if (indegree1[it] == 0)
            {
                q.push(it);
            }
            /* code */
        }
    }
    // topo sort not possible
    if(ans.size()<n)
    {
        return vector<int>();
        // empty vector

    }
    return ans;
   


    // Write your code here.
}
vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    
    int n=numCourses;
    vector<int>adj[n];
    for (int i = 0; i <prerequisites.size(); i++)
    {
        int v=prerequisites[i][0];
        int u=prerequisites[i][1];
        adj[u].push_back(v);
        /* code */
    }
    return toposort(n,adj);
}
int main()
{
    vector<vector<int>>prerequisites ={{1,0},{2,0},{3,1},{3,2}};
    vector<int>ans=findOrder(4,prerequisites);
    for (int i = 0; i <ans.size(); i++)
    {
        cout<<ans[i]<<" ";
        /* code */
    }
    

    return 0;
}