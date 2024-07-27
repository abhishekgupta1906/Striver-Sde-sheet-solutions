#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int longestCommonSubstr(string S1, string S2, int n, int m)
{
    // your code here
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (S1[i] == S2[j])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = 0;
            }

            /* code */
        }

        /* code */
    }

    /* code */

    int maxi = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            maxi = max(maxi, dp[i][j]);

            /* code */
        }

        /* code */
    }
    return max;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}