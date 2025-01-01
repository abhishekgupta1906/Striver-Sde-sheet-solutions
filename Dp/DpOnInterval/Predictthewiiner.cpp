#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
// dp[i][j]-max score of player 1 from i to j
int f(int i, int j, int turn, vector<int> &nums, vector<vector<int>> &dp)
{
    // base case
    if (i > j)
    {
        return 0;
    }
    // cache check
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int result = (turn == 1) ? INT_MIN : INT_MAX;
    if (turn)
    {
        result = max(result, nums[i] + f(i + 1, j, 0, nums, dp));
        result = max(result, nums[j] + f(i, j - 1, 0, nums, dp));
    }
    else
    {
        result = min(result, f(i + 1, j, 1, nums, dp));
        result = min(result, f(i, j - 1, 1, nums, dp));
    }
    dp[i][j]=result;
    return result;
}
bool predictTheWinner(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int player1=f(0,n-1,1,nums,dp);
    int player2=accumulate(nums.begin(),nums.end(),0)-player1;
    return player1>=player2;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums={1,5,233,7};
    bool ans=predictTheWinner(nums);
    cout<<ans;
    return 0;
}