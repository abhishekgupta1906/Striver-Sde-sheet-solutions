#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
// dp(i,j)-min delete ascii sum in s1[i..n-1],and s2[j..m-1]
int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
    int n = s1.length();
    int m = s2.length();
    // pruning
    // base case
    if (i == n && j == m)
        return 0;
    if (i == n)
    {
        int sum = 0;
        for (int t = j; t < m; t++)
        {
            char c = s2[t];
            sum += (int)c;
        }
        return sum;
    }

    if (j == m)
    {
        int sum = 0;
        for (int t = i; t < n; t++)
        {
            char c = s1[t];
            sum += (int)c;
        }
        return sum;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }
    int minans = INT_MAX;
    if (s1[i] == s2[j])
    {
        minans = min(minans, f(i + 1, j + 1, s1, s2, dp));
    }
    minans = min(minans, (int)s2[j] + f(i, j + 1, s1, s2, dp));
    minans = min(minans, (int)s1[i] + f(i + 1, j, s1, s2, dp));
    dp[i][j]=minans;
    return minans;
}
int minimumDeleteSum(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(0, 0, s1, s2, dp);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s1 = "delete";
    string s2 = "leet";
    int ans = minimumDeleteSum(s1, s2);
    cout << ans;
    return 0;
}