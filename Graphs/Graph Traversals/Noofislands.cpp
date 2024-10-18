#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
void dfs(vector<vector<char>> &grid, int i, int j)
{
    int m = grid.size();
    int n = grid[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0')
    {
        return;
    }
    grid[i][j] ='0';
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    for (int t = 0; t < 4; t++)
    {
        int nx = i + dx[t];
        int ny = j + dy[t];
        dfs(grid, nx, ny);

        /* code */
    }
}
// without space
int numIslands(vector<vector<char>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    // vector<vector<int>> visited(m, vector<int>(n, 0));
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '1')
            {
                dfs(grid, i, j);
                count++;
            }
            /* code */
        }

        /* code */
    }
    return count;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}};

    int ans = numIslands(grid);
    cout << ans;
    return 0;
}