#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
bool toposort(int n, vector<int> adj[])
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
    int count = 0;

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
        count++;

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
    // topo sort not applicable
    if (count < n)
    {
        return false;
    }
    return true;

    // Write your code here.
}
 bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
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
    vector<vector<int>> prerequisites={{1,0},{2,1},{0,2}};
    bool ans=canFinish(3,prerequisites);
    cout<<ans;


    return 0;
}