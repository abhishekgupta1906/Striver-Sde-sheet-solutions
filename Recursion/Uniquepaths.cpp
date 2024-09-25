#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int f(int i, int j, vector<vector<int>> &dp)
{
    if (i < 0 || j < 0)
    {
        return 0;
    }
    // pruning
    if (i == 0 && j == 0)
    {
        return 1;
    }
    // cache check
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }

    int ans = f(i - 1, j, dp) + f(i, j - 1, dp);
    dp[i][j] = ans;
    return ans;
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    int ans = f(m - 1, n - 1, dp);
    return ans;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ans=uniquePaths(3,7);
    cout<<ans;
    return 0;
}