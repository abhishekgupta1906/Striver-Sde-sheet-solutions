#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// dp(ind,target)-number of ways from ind to n-1 to make this target_left
int f(int ind, int target, vector<int> &nums, map<pair<int, int>, int> &dp)
{
    int n = nums.size();

    if (ind == n - 1)
    {
        // "+1 -0"
        // "+1 +0"
        int ans = 0;
        if (target - nums[ind] == 0)
        {
            ans += 1;
        }
        if (target + nums[ind] == 0)
        {
            ans += 1;
        }
        return ans;
    }
    if (dp.find({ind, target}) != dp.end())
    {
        return dp[{ind, target}];
    }
    int ans = 0;

    int add = f(ind + 1, target - nums[ind], nums, dp);

    int subtract = f(ind + 1, target + nums[ind], nums, dp);
    ans = add + subtract;
    dp[{ind, target}] = ans;
    return ans;
}
int findTargetSumWays(vector<int> &nums, int target)
{
    int n = nums.size();
    target = abs(target);
    map<pair<int, int>, int> dp;
    return f(0, target, nums, dp);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> nums = {1, 1, 1, 1, 1};
    cout << findTargetSumWays(nums, 3);
    return 0;
}