#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
// dp[i][k]-max value from i to n-1 ny taking atmost k events
int f(int ind, vector<int> &start, vector<int> &end, vector<int> &value, int k, vector<vector<int>>&dp)
{
    int n = start.size();
    // pruning
    if (k == 0)
    {
        return 0;
    }
    // base case
    if (ind >= n)
    {
        return 0;
    }
    if(dp[ind][k]!=-1){
        return dp[ind][k];
    }
    int i = upper_bound(start.begin(), start.end(), end[ind]) - start.begin();
    int take = value[ind] + f(i, start, end, value, k - 1,dp);
    int notake = f(ind + 1, start, end, value, k,dp);
    dp[ind][k]=max(take, notake);
    return max(take, notake);
}
int maxValue(vector<vector<int>> &events, int k)
{
    int n = events.size();
    sort(events.begin(), events.end());
    vector<int> start, end, value;
    for (int i = 0; i < events.size(); i++)
    {
        start.push_back(events[i][0]);
        end.push_back(events[i][1]);
        value.push_back(events[i][2]);
        /* code */
    }
    vector<vector<int>>dp(n,vector<int>(k+1,-1));
    f(0,start,end,value,k,dp);
    int maxi=0;
    for (int i = 0; i <=k; i++)
    {
        maxi=max(maxi,dp[0][i]);
        /* code */
    }
    return maxi;
    
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> events = {{1, 2, 4}, {3,4,3}, {2, 3, 10}};
    int ans=maxValue(events,2);
    cout<<ans;

    
    return 0;
}