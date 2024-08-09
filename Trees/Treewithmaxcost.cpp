#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#define int long long
using namespace std;
void dfs1(int currnode,int parent,vector<int>adj[],vector<int>&subans,vector<int>&sum,vector<int>&a)
{
    sum[currnode]=a[currnode];
    for(auto it:adj[currnode])
    {
        if(it!=parent)
        {
            dfs1(it,currnode,adj,subans,sum,a);
            sum[currnode]+=sum[it];
            subans[currnode]+=subans[it]+sum[it];
        }
    }

}
// sum[0]-totalweight
void dfs2(int currnode,int parent,vector<int>adj[],vector<int>&subans,vector<int>&sum,vector<int>&dp)
{
  
    for(auto it:adj[currnode])
    {
        if(it!=parent)
        {
            //it-2 parent-1
            // removal
            int newsubans = dp[currnode] - subans[it] - sum[it];
            int newsum = sum[0]-sum[it];
            dp[it] = subans[it] +newsubans+newsum;
            // sum[it] = sum[currnode];
            dfs2(it,currnode,adj,subans,sum,dp);
        }
    }

}

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        /* code */
    }
    vector<int> adj[n];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
        /* code */
    }
    // subans[x]-ans for the subtree x
    // question me jo pucha for a subtree
    // sum[x]-sum of weights of all the nodes in the subtree of x
    vector<int>subans(n,0);
    vector<int>sum(n);
    vector<int>dp(n,0);
    dfs1(0,-1,adj,subans,sum,a);
    dp[0]=subans[0];
    dfs2(0,-1,adj,subans,sum,dp);
    int maxi=0;
    for (int i = 0; i <n; i++)
    {
        maxi=max(dp[i],maxi);
        /* code */
    }
    cout<<maxi;
    


    return 0;
}