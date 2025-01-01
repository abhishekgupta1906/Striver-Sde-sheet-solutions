#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
int calculate_lowerind(vector<int> &days, int val)
{
    int ind = lower_bound(days.begin(), days.end(), val) - days.begin();
    return ind;
}
int f(int ind, vector<int> &days, vector<int> &costs, vector<int> &dp)
{
    int n = days.size();
    if (ind >= n)
    {
        return 0;
    }
    if (dp[ind] != -1)
    {
        return dp[ind];
    }
    int take1 = costs[0] + f(calculate_lowerind(days, days[ind] + 1), days, costs, dp);

    int take7 = costs[1] + f(calculate_lowerind(days, days[ind] + 7), days, costs, dp);
    int take30 = costs[2] + f(calculate_lowerind(days, days[ind] + 30), days, costs, dp);
    dp[ind] = min({take1, take7, take30});
    return min({take1, take7, take30});
}
int mincostTickets(vector<int> &days, vector<int> &costs)
{
    int n = days.size();
    vector<int> dp(n, -1);
    return f(0, days, costs, dp);
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> days = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31};
    vector<int> costs = {2, 7, 15};
    cout << mincostTickets(days, costs);
    return 0;
}