#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
// dp[ind]-max profit by doing non overlapping jobs form ind to n-1;
int f(int ind, vector<int> &startTime, vector<int> &endTime, vector<int> &profit,vector<int>&dp)
{
    // base case
    int n = startTime.size();
    if (ind >= n)
    {
        return 0;
    }
    if(dp[ind]!=-1){
        return dp[ind];
    }
    int i = lower_bound(startTime.begin(), startTime.end(), endTime[ind]) - startTime.begin();
    int take = profit[ind] + f(i, startTime, endTime, profit,dp);
    int notake = f(ind + 1, startTime, endTime, profit,dp);
    dp[ind]=max(take, notake);
    return max(take, notake);
}
int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
{
    int n = startTime.size();
    vector<pair<pair<int, int>, int>> events;
    for (int i = 0; i < n; i++)
    {
        events.push_back({{startTime[i], endTime[i]}, profit[i]});
        /* code */
    }
    sort(events.begin(), events.end());
    for (int i = 0; i < n; i++)
    {
        startTime[i] = events[i].first.first;
        endTime[i] = events[i].first.second;
        profit[i] = events[i].second;
        /* code */
    }
    vector<int>dp(n,-1);
    return f(0,startTime,endTime,profit,dp);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int>start={1,2,3,3};
    vector<int>end={3,4,5,6};
    vector<int>profit={50,10,40,70};
    int ans=jobScheduling(start,end,profit);
    cout<<ans;
    return 0;
}