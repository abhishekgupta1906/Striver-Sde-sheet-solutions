#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// cost [i][j]-cost to place to mail 1 box for an inetrval i to j
// dp[i][k]-minimum totalcost for i to n-1 with k mailboxes
// i-start
int f(int i, int k, vector<int> &houses, vector<vector<int>> &cost, vector<vector<int>> &dp)
{
    int n = houses.size();
    // base case
    if (i == n && k == 0)
    {
        return 0;
    }
    // pruning
    if (i == n || k == 0)
    {
        return INT_MAX;
    }
    if (dp[i][k] != -1)
    {
        return dp[i][k];
    }
    int ans = INT_MAX;
    for (int j = i; j < n; j++)
    {
        int c = f(j + 1, k - 1, houses, cost, dp);
        if (c != INT_MAX)
        {
            c += cost[i][j];
        }
        ans = min(ans, c);
        /* code */
    }
    dp[i][k] = ans;
    return ans;
}

int minDistance(vector<int> &houses, int k)
{
    sort(houses.begin(), houses.end());
    int n = houses.size();
    vector<vector<int>> cost(n, vector<int>(n));
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int ind = (i + j) / 2;
            // median
            int median = houses[ind];
            int ans = 0;
            for (int x = i; x <= j; x++)
            {
                ans += abs(median - houses[x]);
            }
            cost[i][j] = ans;
        }
    }

    return f(0, k, houses, cost, dp);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> houses = {2,3,5,12,18};
    int ans = minDistance(houses,2);
    cout << ans;
    return 0;
}