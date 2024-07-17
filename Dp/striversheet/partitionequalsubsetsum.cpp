#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
bool f(int level, int target, vector<vector<int>> &dp, vector<int> &arr)
{
    // pruning
    if (target == 0)
    {
        return true;
    }
    // base case
    if (level == 0)
    {
        if (arr[level] == target)
            return true;
        return false;
    }
    // caching
    if (dp[level][target] != -1)
    {
        return dp[level][target];
    }
    bool take = false;
    if (arr[level] <= target)
    {
        take = f(level - 1, target - arr[level], dp, arr);
    }
    bool notake = f(level - 1, target, dp, arr);
    dp[level][target] = take || notake;
    return dp[level][target];
}

bool canPartition(vector<int> &nums)
{
    int sum=accumulate(nums.begin(), nums.end(),0);
    vector<vector<int>>dp(nums.size(),vector<int>(sum,-1));
    if(sum %2==1)
    {
        return false;
    }
    bool ans=f(nums.size()-1,sum/2,dp,nums);
    return ans;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums={1,2,35};
    bool ans=canPartition(nums);
    cout<<ans;

    return 0;
}