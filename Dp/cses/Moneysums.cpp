#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#define int long long
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

signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    vector<int>arr(n);
    for (int i = 0; i <n; i++)
    {
        cin>>arr[i];
        /* code */
    }
    
    vector<vector<int>> dp(100, vector<int>(100001, -1));
    int sum = accumulate(arr.begin(), arr.end(), 0);
    vector<int> ans;
    int count = 0;
    for (int i =1; i <= sum; i++)
    {
        bool t = f(arr.size() - 1, i, dp, arr);
        if (t == 1)
        {
            count++;
            ans.push_back(i);
        }

        /* code */
    }
    cout<<count<<"\n";
    for(auto it:ans)
    {
        cout<<it<<" ";
    }

    return 0;
}