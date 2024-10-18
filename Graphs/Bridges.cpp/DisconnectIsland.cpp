#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
void dfs(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &visited)
{
    int m = grid.size();
    int n = grid[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || visited[i][j]==1)
    {
        return;
    }
    visited[i][j] = 1;
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};
    for (int t = 0; t < 4; t++)
    {
        int nx = i + dx[t];
        int ny = j + dy[t];
        dfs(grid, nx, ny, visited);

        /* code */
    }
}
int get_components(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int count = 0;
    vector<vector<int>> visited(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1 && visited[i][j] == 0)
            {
                dfs(grid, i, j, visited);
                count++;
            }
            /* code */
        }

        /* code */
    }
    return count;
}
int minDays(vector<vector<int>> &grid)
{
    int a=get_components(grid);
    if(a!=1)
    {
        return 0;

    }
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i <n; i++)
    {
        for (int j = 0; j <m; j++)
        {
            if(grid[i][j]==1)
            {
                grid[i][j] =0;
                int ans=get_components(grid);
                if(ans!=1)
                {
                    return 1;
                }
                grid[i][j]=1;
            }
            /* code */
        }
        
        /* code */
    }
    return 2;
    
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}