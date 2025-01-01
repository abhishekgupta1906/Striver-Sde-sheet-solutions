#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
// dp[i,n,m]-largest subset size from i to n-1 with atmost n ones and m zeroes
class Special
{
public:
    bool valid;
    int c1;
    int c0;
};
Special check(string str, int n, int m)
{
    Special p;
    int count1 = 0;
    int count0 = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '1')
        {
            count1++;
        }
        else
        {
            count0++;
        }
    }
    if (count1 > n || count0 > m)
    {
        p.valid = false;
        p.c1 = n;
        p.c0 = m;
        return p;
    }
    p.valid = true;
    p.c1 = count1;
    p.c0 = count0;
    return p;
}

int f(int ind, int n, int m, vector<string> &strs,vector<vector<vector<int>>>&dp)
{
    int strSize = strs.size();
    if (n < 0 || m < 0)
    {
        return 0;
    }
    if (ind == strSize)
    {
        return 0;
    }
    if (dp[ind][n][m] != -1)
    {
        return dp[ind][n][m];
    }
    int take = 0;
    Special p = check(strs[ind], n, m);
    if (p.valid)
    {
        take = 1 + f(ind + 1, n - p.c1, m - p.c0, strs, dp);
    }
    int notake = f(ind + 1, n, m, strs, dp);
    dp[ind][n][m] =max(take, notake);
    return max(take, notake);
}

int findMaxForm(vector<string> &strs, int m, int n)
{
    int strSize = strs.size();
    vector<vector<vector<int>>>dp(strSize,vector<vector<int>>(n+1,vector<int>(m+1,-1)));
    return f(0, n, m, strs,dp);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}