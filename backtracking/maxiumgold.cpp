#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

int f(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &visited)
{
    // base case when i cannot move
    int m = grid.size();
    int n = grid[0].size();
    if (i < 0 || i >=m || j < 0 || j >=n || visited[i][j]==1 || grid[i][j]==0)
        return 0;

    visited[i][j] = 1;
    int px[4] = {-1, 1, 0, 0};
    int py[4] = {0, 0, -1, 1};
    int ans = 0;
    for (int t = 0; t < 4; t++)
    {
        int nx = i + px[t];
        int ny = j + py[t];

        ans = max(ans, grid[i][j] + f(grid, nx, ny, visited));
    }
    visited[i][j] = 0;
    return ans;
}
int getMaximumGold(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] != 0)
            {
                ans = max(ans, f(grid, i, j, visited));
            }
            /* code */
        }

        /* code */
    }
    return ans;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> grid = {{1, 0, 7}, {2, 0, 6}, {3, 4, 5}, {0, 3, 0}, {9, 0, 20}};
    int ans = getMaximumGold(grid);
    cout << ans;
    return 0;
}