#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
// global dp
int dp[50002][5];
int f(int ind, int k,vector<int>&start,vector<int>&end,vector<int>&weight)
{
    // pruning
    int n = start.size();

    if (k==0)
    {
        // over
        return 0;
    }
    if (ind >= n)
    {
        if (k < 0)
        {
            return INT_MIN;
        }
        return 0;
    }
    if(dp[ind][k]!=-1){
        return dp[ind][k];
    }
    int i = lower_bound(start.begin(), start.end(),end[ind]+1) - start.begin();
    int take =weight[ind]+ f(i, k - 1,start,end,weight);
    int notake = f(ind + 1, k,start,end,weight);
    dp[ind][k]=max(take, notake);
    return max(take, notake);
}
void solve(int ind, int k, vector<int>&start,vector<int>&end,vector<int>&weight, map<pair<int, pair<int, int>>, int> &mp, vector<int> &ans)
{
    int n =start.size();
    if (k==0)
    {
        return;
    }
    if (ind >= n)
    {
        return;
    }
    int i = lower_bound(start.begin(), start.end(),end[ind]+1) - start.begin();
    int take =weight[ind]+ f(i, k - 1,start,end,weight);
    int notake = f(ind + 1, k,start,end,weight);
    if (take >= notake)
    {
        // take this  index but iska original wla
        int l = start[ind];
        int r =end[ind];
        int w = weight[ind];
        int index = mp[{l, {r, w}}];
        ans.push_back(index);
        solve(ind + 1, k - 1,start,end,weight, mp, ans);
    }
    else
    {
        solve(ind + 1, k,start,end,weight, mp, ans);
    }
}
vector<int> maximumWeight(vector<vector<int>> &intervals)
{
    map<pair<int, pair<int, int>>, int> mp;
    int n = intervals.size();
    for (int i = 0; i < n; i++)
    {
        int l = intervals[i][0];
        int r = intervals[i][1];
        int weight = intervals[i][2];
        mp[{l, {r, weight}}] = i;
        /* code */
    }
    sort(intervals.begin(), intervals.end());
    vector<int>start,end,weight;
    for (int i = 0; i <n; i++)
    {
        start.push_back(intervals[i][0]);
        end.push_back(intervals[i][1]);
        weight.push_back(intervals[i][2]);
        /* code */
    }
    
    
    memset(dp,-1,sizeof(dp));
    vector<int> ans;
    solve(0,4,start,end,weight,mp,ans);
    return ans;
}
char forward_shift(char temp,int&shift){
    int i=temp-'a';
    int ans=(i+shift)%26;
    char val='a'+ans;
    return val;

}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    char shift=forward_shift('d',4);
    cout<<shift;
    
   
    return 0;
}