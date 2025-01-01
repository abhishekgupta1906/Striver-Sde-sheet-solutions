#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
// dp(i,j)-> maximum coins that can be obtained by bursting balloons from i to j from last ,mtlb last se start kr rhe tki intervals
// independent ho
int f(int i,int j,vector<int> &nums,vector<vector<int>>&dp){
    // pruning 
    if(i>j){
        return 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int maxi=INT_MIN;
    for (int ind =i; ind <=j; ind++)
    {
        // burstting ballon ind last
        int coins=nums[i-1]*nums[ind]*nums[j+1]+f(i,ind-1,nums,dp)+f(ind+1,j,nums,dp);
        maxi=max(maxi,coins);

        /* code */
    }
    dp[i][j]=maxi;
    return maxi;
}
int maxCoins(vector<int> &nums)
{
    int n=nums.size();
    nums.push_back(1);
    nums.insert(nums.begin(), 1);
    vector<vector<int>>dp(n+2,vector<int>(n+2,-1));
    return f(1,n,nums,dp);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums={1,5};
    int ans=maxCoins(nums);
    cout<<ans;
    return 0;
}