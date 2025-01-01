#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
bool f(string &s, int i, int j, vector<vector<int>> &dp)
{
    // base case
    if (i > j)
    {
        return true;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    bool ans;
    if (s[i] == s[j])
    {
        ans = f(s, i + 1, j - 1, dp);
    }
    else
    {
        ans = false;
    }
    dp[i][j] = ans;
    return ans;
}
int countSubstrings(string s)
{
    vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));
    int count = 0;
    for (int i = 0; i < s.length(); i++)
    {
        // debugging
        for (int j =i; j < s.length(); j++)
        {
            if (f(s, i, j, dp))
            {
                count++;
            }
            /* code */
        }

        /* code */
    }
    return count;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s = "aaa";
    int ans = countSubstrings(s);
    cout << ans;
    return 0;
}