#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#define int long long
using namespace std;


int maxProfit(vector<int> &value, vector<int> &weight, int n, int W)
{
     vector<int>prev(W+1,0);
    for (int j = weight[0]; j <= W; j++)
    {
        prev[j] = value[0];
    }
    for (int i = 1; i < n; i++)
    {
        vector<int>curr(W+1,0);
        for (int j = 0; j <= W; j++)
        {
            int pick = INT_MIN;
            if (j >= weight[i])
            {
                pick = value[i] +prev[j - weight[i]];
            }
            int notPick =prev[j];
            curr[j] = max(pick, notPick);
            /* code */
        }
        prev=curr;

        /* code */
    }
    return prev[W];
    // Write your code here
}
signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n >>w;
    vector<int>value(n);
    vector<int> weight(n);
    for (int i = 0; i < n; i++)
    {
        cin >>value[i];
        // cin >> weight[i];
        /* code */
    }
    for (int i = 0; i < n; i++)
    {
        cin >> weight[i];
        // cin >> page[i];
        /* code */
    }
    int ans = maxpages(value,weight,w);
    cout << ans;

    return 0;
}