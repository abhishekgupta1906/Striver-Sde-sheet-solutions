#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#define int long long
using namespace std;
// int f(int ind, int x, vector<int> &price, vector<int> &page,vector<vector<int>>&dp)
// {
//     // pruning
//     if (x == 0)
//     {
//         return 0;
//     }
//     // base case
//     if (ind == 0)
//     {
//         if (price[ind] <= x)
//         {
//             return page[ind];
//         }
//         return 0;
//     }
//     // caching
//     if(dp[ind][x]!=-1)
//     {
//         return dp[ind][x];
//     }

//     // recursion
//     int take = 0;
//     if (price[ind] <= x)
//     {
//         take = page[ind] + f(ind - 1, x - price[ind], price, page,dp);
//     }
//     int notake = f(ind - 1, x, price, page,dp);
//     dp[ind][x]=max(take, notake);
//     return dp[ind][x];
// }
// int maxpages(vector<int> &price, vector<int> &pages, int x)
// {
//     int n = price.size();
//     vector<vector<int>>dp(n,vector<int>(x+1,-1));

//     return f(n - 1, x, price, pages,dp);
// }

int maxpages(vector<int> &price, vector<int> &page, int x)
{
    int n = price.size();
    // vector<vector<int>> dp(n, vector<int>(x + 1, 0));
    vector<int>prev(x+1,0);
    for (int j = price[0]; j <= x; j++)
    {
        prev[j]=page[0];

        /* code */
    }
    for (int i =1; i <n; i++)
    {
        vector<int>curr(x+1);
        for (int j = 0; j <=x; j++)
        {
            int take=INT_MIN;
            if(price[i]<=j)
            {
                take=page[i]+prev[j-price[i]];
            }
            int notake=prev[j];
            curr[j]=max(take,notake);
            /* code */
        }
        prev=curr;
        
        /* code */
    }
    return prev[x];
    
}
signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    cin >> n >> x;
    vector<int> price(n);
    vector<int> page(n);
    for (int i = 0; i < n; i++)
    {
        cin >> price[i];
        // cin >> page[i];
        /* code */
    }
    for (int i = 0; i < n; i++)
    {
        cin >> page[i];
        // cin >> page[i];
        /* code */
    }
    int ans = maxpages(price, page, x);
    cout << ans;

    return 0;
}