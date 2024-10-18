#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int f(int i, int j, int &count, vector<vector<int>> &grid, vector<vector<int>> &visited,vector<vector<int>>dp)
{
    // pruning
    int m = grid.size();
    int n = grid[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == -1 || visited[i][j] == 1)
    {
        return 0;
    }
    if (grid[i][j] == 2)
    {
        return (count==-1)?1:0;
        // grid[i][j]==1 ke liy bhi minus kr diye

        /* code */
    }
    if(dp[i][j]!=-1)
    {
        return dp[i][j];
    }
    int ans = 0;
    visited[i][j] = 1;
    count--;
    int px[4] = {-1, 1, 0, 0};
    int py[4] = {0, 0, -1, 1};
    for (int m = 0; m < 4; m++)
    {
        int nx = i + px[m];
        int ny = j + py[m];
        ans += f(nx, ny,count, grid, visited,dp);

        /* code */
    }
    visited[i][j] = 0;
    count++;
    dp[i][j]=ans;
    return ans;
}
int uniquePathsIII(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));
    vector<vector<int>>dp(m, vector<int>(n,-1));
    int starti = 0;
    int startj = 0;
    int count = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                starti = i;
                startj = j;
            }
            else if (grid[i][j] == 0)
            {
                count++;
            }
            /* code */
        }

        /* code */
    }
    int ans = f(starti, startj,count, grid, visited,dp);
    return ans;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> grid = {{1, 0, 0, 0}, {0, 0, 0, 0}, {0, 0, 0, 2}};
    int ans = uniquePathsIII(grid);
    cout << ans;
    return 0;
}