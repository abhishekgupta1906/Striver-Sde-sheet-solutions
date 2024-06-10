#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// int f(int ind,vector<int>&nums, vector<int>&dp)
// {
//     if(ind==0)
//     {
//         return nums[ind];
//     }
//     if(ind<0)
//     {
//         return 0;
//     }
//     if(dp[ind]!=-1)
//     {
//         return dp[ind];
//     }
//     int pick=f(ind-2,nums,dp)+nums[ind];
   
      

    
//     int notpick=f(ind-1,nums,dp);
//     dp[ind]=max(pick,notpick);
//     return dp[ind];
// }
// int rob(vector<int> &nums)
// {
//     int n=nums.size();
//     vector<int>dp(n,-1);
//     return f(n-1,nums,dp);
// }
// dp
int rob(vector<int> &nums)
{
    int n=nums.size();
    vector<int>dp(n);
    dp[0]=nums[0];
    for (int i =1; i <n; i++)
    {
        int pick=0;
        if(i>1)
        {
            pick=dp[i-2]+nums[i];
        }
        int notpick=dp[i-1];
        dp[i]=max(pick,notpick);
        /* code */
    }
    return dp[n-1];

    
   
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums={1,2,3,1};
    int ans=rob(nums);
    cout<<ans;
    return 0;
}