#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
// mereko iss question dekho downwards jna h kya karoge ,har node lowest mano kitna upar tk jaa skte h
int maxi = INT_MIN;
int mini = INT_MAX;
vector<int> path;
map<int, int> mp;
// konsa isnode ka particular color kb aya tha
// weight add krna h
// pathsum->adding weights start end (mainly for calculating min no of nodes)
void dfs1(int node, int par, vector<vector<pair<int, int>>> &adj, vector<int> &nums, int pathsum, int start, int end)
{
    int prevIndex = (mp.find(nums[node]) == mp.end()) ? -1 : mp[nums[node]];
    // iska mtlb ye color last baar kb aya tha
    while (start <= prevIndex)
    {
        pathsum -= path[start];
        start++;
    }
    if (pathsum > maxi)
    {
        maxi = pathsum;
        mini =end - start + 1;
    }
    else if(pathsum==maxi){
        mini = min(mini, end - start + 1);
    }
    mp[nums[node]]=end;
    // ye color iss end pr aya tha
    for(auto it:adj[node]){
        if(it.first==par){
            continue;
        }
        int wt=it.second;
        path.push_back(wt);
        dfs1(it.first,node,adj,nums,pathsum+wt,start,end+1);
        path.pop_back();
    }
    mp[nums[node]]=prevIndex;


}

vector<int> longestSpecialPath(vector<vector<int>> &edges, vector<int> &nums)
{
    // build adjacency list
    int n = edges.size() + 1;
    vector<vector<pair<int, int>>> adj(n);
    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int w = it[2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    dfs1(0,-1,adj,nums,0,0,0);
    return {maxi,mini};

}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>>edges={{0,1,2},{1,2,3},{1,3,5},{1,4,4},{2,5,6}};
    vector<int>nums={2,1,2,1,3,1};
    vector<int>result=longestSpecialPath(edges,nums);
    for(auto it:result){
        cout<<it<<" ";
    }

    return 0;
}