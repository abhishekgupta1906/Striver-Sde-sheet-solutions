#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int m = 1e9 + 7;
int f(int ind, int n, int minprofit, vector<int> &group, vector<int> &profit,vector<vector<vector<int>>>&dp)
{
    // pruning
    int grp_size = group.size();
    if (n < 0)
    {
        return 0;
    }
    if (minprofit <= 0)
    {
        minprofit = 0;
    }
    if (ind == grp_size)
    {
        if (minprofit <= 0)
        {
            return 1;
        }
        return 0;
    }
    if(dp[ind][n][minprofit]!=-1){
        return dp[ind][n][minprofit];
    }
    int take = 0;
    if (group[ind] <= n)
    {
        take = f(ind + 1, n - group[ind], minprofit - profit[ind], group, profit,dp);
    }
    int notake = f(ind + 1, n, minprofit, group, profit,dp);
    int ans = (notake % m + take % m) % m;
    ans=ans%m;
    dp[ind][n][minprofit] = ans;
    return ans;
}
int profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit)
{
    vector<vector<vector<int>>>dp(group.size(),vector<vector<int>>(n+1,vector<int>(minProfit+1,-1)));
    return f(0, n, minProfit, group, profit,dp);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> profit = {6, 7, 8};
    vector<int> group = {2, 3, 5};
    int ans = profitableSchemes(10,5,group, profit);
    cout << ans;
    return 0;
}