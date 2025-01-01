#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
// dp(i,t)-max sum from i to n-1 ,with total time taken is t
// why sorting ,dekh maX nikalna h chote element pr km time bde element pr jyada
int f(int ind, vector<int> &satisfaction, int t, vector<vector<int>> &dp)
{
    //  pruning
    int n = satisfaction.size();
    if (t > n)
    {
        return 0;
    }
    if (ind == n)
    {
        return 0;
    }
    if (dp[ind][t] != -1)
    {
        return dp[ind][t];
    }
    int take = (t + 1) * satisfaction[ind] + f(ind + 1, satisfaction, t + 1, dp);
    int notake = f(ind + 1, satisfaction, t, dp);
    dp[ind][t] = max(take, notake);
    return max(take, notake);
}
int maxSatisfaction(vector<int> &satisfaction)
{
    int n = satisfaction.size();
    sort(satisfaction.begin(), satisfaction.end());
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    return f(0, satisfaction, 0, dp);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<int> satisfaction(n);
    for (int i = 0; i < n; i++)
    {
        cin >> satisfaction[i];
        /* code */
    }
    int ans = maxSatisfaction(satisfaction);
    cout << ans << "\n";

    return 0;
}