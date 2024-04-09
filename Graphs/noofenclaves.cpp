#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// problems wo ones jisne hm kitna moves chl jye boundary ke bahar nhi jyeneg
// boundary ones danger ones
    bool checkboundary(vector<vector<int>> &grid,int r,int c)
{
    int m = grid.size();
    int n = grid[0].size();
    if(r>=0 && r<=m-1 && c>=0 && c<=n-1 && grid[r][c]==1)
    {
        return true;
    }
    return false;
}

    int numEnclaves(vector<vector<int>>& grid) 
    {
        int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>>visited(m, vector<int>(n, 0));
    // src 
     queue<pair<int, int>> q;
    for (int r = 0; r < grid.size(); r++)
    {
        for (int c = 0; c < grid[r].size(); c++)
        {
            if ((r == 0 || r == m - 1 || c == 0 || c==n-1) && grid[r][c]==1)
            {
                visited[r][c] = 1;
                q.push({r,c});
            }
            /* code */
        }

        /* code */
    }
    // bfs
    while(!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        // main step
        int row[4]={-1,1,0,0};
        int col[4]={0,0,-1,1};
        for (int i = 0; i <4; i++)
        {
            int adjrow=r+row[i];
            int adjcol=c+col[i];
            if(checkboundary(grid, adjrow, adjcol) && visited[adjrow][adjcol]==0)
            {
                visited[adjrow][adjcol]=1;
                q.push({adjrow, adjcol});
            }

        }
        
    }
     int cnt = 0;
       for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
        // check for unvisited land cell
        if(grid[i][j] == 1 && visited[i][j] == 0) 
            cnt++; 
    }
}
        return cnt; 
       
        
        
    }
int main()
{
   
    return 0;
}