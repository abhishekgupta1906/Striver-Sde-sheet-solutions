#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// in out dp ka use krna
// for more clarity
// revise this problem very important for each node we are saving largest and second largest path
// in[x]-distance of the max node in the subtree of x
// out[x]-distance of max node outside the subtree of x
void dfs1(int currnode, int parent, vector<int> adj[], vector<int> &in)
{
    for (auto it : adj[currnode])
    {
        if (it != parent)
        {
            dfs1(it, currnode, adj, in);
            in[currnode] = max(in[currnode], 1 + in[it]);
        }
    }
}
void dfs2(int currnode, int parent, vector<int> adj[], vector<int> &in, vector<int> &out)
{
    int maxi1 = -1;
    int maxi2 = -1;
    for (auto it : adj[currnode])
    {
        if (it != parent)
        {
            if (in[it] + 1 > maxi1)
            {
                maxi2 = maxi1;
                maxi1 = 1 + in[it];
            }
            else if (in[it] + 1 > maxi2)
            {
                maxi2 = 1 + in[it];
            }
        }
    }

    for (auto it : adj[currnode])
    {
        if (it != parent)
        {
            int ans=maxi1;
            if(1+in[it]==maxi1)
            {
                // mtlb longest path maxi1 it ke through aya
                ans=maxi2;
            }
            out[it]=max(1+out[currnode],1+ans);
            dfs2(it,currnode,adj,in,out);
        }
    }
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> adj[n];
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        adj[a].push_back(b);
        adj[b].push_back(a);

        /* code */
    }
    vector<int>in(n,0);
    vector<int>out(n);
    dfs1(0,-1,adj,in);
    out[0]=0;
    dfs2(0,-1,adj,in,out);
    for (int i = 0; i <n; i++)
    {
        cout<<max(in[i],out[i])<<" ";
        /* code */
    }
    

    return 0;
}