#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
// dp[i]-no of good strings of len i
const int m= 1e9 + 7;
int f(int len, int zero, int one, vector<int> &dp)
{
    if (len < 0)
    {
        return 0;
    }
    if (len == 0)
    {
        return 1;
    }
    if (dp[len] != -1)
    {
        return dp[len];
    }
    int append_zero = f(len - zero, zero, one, dp);
    int append_one = f(len - one, zero, one, dp);
    dp[len] = append_zero + append_one;
    return append_zero + append_one;
}
int countGoodStrings(int low, int high, int zero, int one)
{
    vector<int> dp(high + 1, -1);
    int ans = 0;
    for (int i = high; i >= low; i--)
    {
        int val = f(i, zero, one, dp);
        ans=(ans%m+val%m)%m;

        /* code */
    }
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ans=countGoodStrings(2,3,1,2);
    cout<<ans;
    return 0;
}