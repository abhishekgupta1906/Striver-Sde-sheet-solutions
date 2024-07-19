#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// int f(vector<int> &arr, int index, int n, int k, vector<int> &dp) {
//     // Base case
//     if (index >= n) {
//         return 0;
//     }

//     // Cache check
//     if (dp[index] != -1) {
//         return dp[index];
//     }

//     int maxi = 0;
//     int maxinumber = 0;

//     for (int j = index; j<min(n, index + k); j++) {
//         for (int m =index; m <=j; m++)
//         {
//             maxinumber = max(maxinumber,arr[m]);
//             /* code */
//         }

//         int coins = maxinumber * (j - index+1) + f(arr, j+1, n, k, dp);
//         maxi = max(maxi, coins);
//     }

//     dp[index] = maxi;
//     return maxi;
// }

// int maxSumAfterPartitioning(vector<int> &arr, int k) {
//     int n = arr.size();
//     vector<int> dp(n, -1);
//     return f(arr, 0, n, k, dp);
// }

// optimised version

int f(vector<int> &arr, int index, int n, int k, vector<int> &dp)
{
    // Base case
    if (index >= n)
    {
        return 0;
    }

    // Cache check
    if (dp[index] != -1)
    {
        return dp[index];
    }

    int maxi = 0;
    int maxinumber = 0;

    for (int j = index; j < min(n, index + k); j++)
    {

        maxinumber = max(maxinumber, arr[j]);
        /* code */

        int coins = maxinumber * (j - index + 1) + f(arr, j + 1, n, k, dp);
        maxi = max(maxi, coins);
    }

    dp[index] = maxi;
    return maxi;
}

int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n, -1);
    return f(arr, 0, n, k, dp);
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> arr = {1, 15, 7, 9, 2, 5, 10};
    int ans = maxSumAfterPartitioning(arr, 3);
    cout << ans;
    return 0;
}