#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
int maxScore(vector<vector<int>> &grid)
{
    // crux of the problem ki agar main ek cell se dusre cell jaun c2-c1 (c1,c2) ->c2,c3-diif c3-c2 total-c3-c1 ,but it depends on final and start point
    // ab score maximize krna h
    // for each cell find min one
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n));
    dp[0][0] = grid[0][0];
    // for first row and first column
    // first row
    for (int j = 1; j < n; j++)
    {
        dp[0][j] = min(grid[0][j], dp[0][j - 1]);
    }
    // first column
    for (int i = 1; i < m; i++)
    {
        dp[i][0] = min(grid[i][0], dp[i - 1][0]);
    }
    int maxi = INT_MIN;
    for (int i = 1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            dp[i][j] = min(grid[i][j], min(dp[i - 1][j], dp[i][j - 1]));

            /* code */
        }

        /* code */
    }
    for (int j = 1; j < n; j++)
    {
        int val=grid[0][j]-dp[0][j-1];
        maxi= max(maxi,val);
    }
    // first column
    for (int i = 1; i < m; i++)
    {
        int val=grid[i][0]-dp[i-1][0];
        maxi= max(maxi,val);
    }
    for (int i =1; i < m; i++)
    {
        for (int j = 1; j < n; j++)
        {
            int val1=min(dp[i-1][j],dp[i][j-1]);
            int val=grid[i][j]-val1;
            
            maxi=max(maxi,val);

            /* code */
        }

        /* code */
    }
    return maxi;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> grid = {{4, 3, 2}, {3, 2, 1}};
    cout << maxScore(grid);
    return 0;
}