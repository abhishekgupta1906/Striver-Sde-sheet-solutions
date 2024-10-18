#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
string serialize(vector<int> &needs)
{
    string key = "";
    for (int n : needs)
    {
        key += to_string(n) + ",";
    }
    return key;
}
bool check(vector<int> &current, vector<int> &needs)
{
    bool a = true;
    for (int i = 0; i < needs.size(); i++)
    {
        if (current[i] > needs[i])
        {
            a = false;
            break;
        }
        /* code */
    }
    return a;
}
bool check2(vector<int> &needs)
{
    bool a = true;
    for (int i = 0; i < needs.size(); i++)
    {
        if (needs[i] > 0)
        {
            a = false;
            break;
        }
        /* code */
    }
    return a;
}
int f(int n, int ind, vector<int> &needs, vector<int> &price, vector<vector<int>> &special, map<pair<string, int>, int> &dp)
{
    // pruning
    if (check2(needs))
    {
        return 0;
    }

    // base case
    if (ind == n)
    {
        int sum = 0;
        for (int i = 0; i < needs.size(); i++)
        {
            if (needs[i] > 0)
            {
                sum += needs[i] * price[i];
            }
            /* code */
        }
        return sum;
    }
    string needsKey = serialize(needs);

    if (dp.find({needsKey, ind}) != dp.end())
    {
        return dp[{needsKey, ind}];
    }

    int ans = INT_MAX;
    if (check(special[ind], needs))
    {
        vector<int> current = special[ind];
        for (int i = 0; i < needs.size(); i++)
        {
            needs[i] -= current[i];
            /* code */
        }
        ans = min(ans, current[price.size()] + f(n, ind, needs, price, special, dp));
        for (int i = 0; i < needs.size(); i++)
        {
            needs[i] += current[i];
            /* code */
        }
    }
    ans = min(ans, f(n, ind + 1, needs, price, special, dp));
    dp[{needsKey, ind}] = ans;

    return ans;
}
int shoppingOffers(vector<int> &price, vector<vector<int>> &special, vector<int> &needs)
{
    int n = special.size();
    map<pair<string, int>, int> dp;
    return f(n, 0, needs, price, special, dp);
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> price = {4, 9, 6};
    vector<int> needs = {4, 5, 3};
    vector<vector<int>> special = {{0, 1, 1, 5}, {2, 3, 2, 1}, {1, 2, 1, 7}, {1, 0, 0, 2}};
    int ans = shoppingOffers(price, special, needs);
    cout << ans;
    return 0;
}