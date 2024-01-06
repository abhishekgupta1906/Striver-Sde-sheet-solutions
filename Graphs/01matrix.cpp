#include <iostream>
#include <string>
#include <queue>
#include <vector>
using namespace std;
// 1 ko rotten orange jaisa treat karo
// distance of nearest 1 from each cell
vector<vector<int>> nearest(vector<vector<int>> &mat, int n, int m)
{
    vector<vector<int>> ans(n, vector<int>(m, 0));
    vector<vector<int>> vis(n, vector<int>(m, 0));
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 1)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            }
            /* code */
        }

        /* code */
    }

    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int steps = q.front().second;

        q.pop();
        int row[4] = {-1, 1, 0, 0};
        int col[4] = {0, 0, -1, 1};
        // unvisited zeroes
        for (int i = 0; i < 4; i++)
        {
            int nrow = r + row[i];
            int ncol = c + col[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && mat[nrow][ncol] == 0)
            {
                q.push({{nrow, ncol}, steps + 1});
                vis[nrow][ncol] = 1;
                ans[nrow][ncol] = steps + 1;
            }
            /* code */
        }
    }
    return ans;

    // Write your code here.
}

int main()
{
    vector<vector<int>> mat = {{0, 0, 0, 1},
                               {0, 0, 1, 1},
                               {0, 1, 1, 0}};

    vector<vector<int>> ans = nearest(mat, 3, 4);
    for (int i = 0; i <3; i++)
    {
        for (int j = 0; j <4; j++)
        {
           cout<<ans[i][j]<<" ";
            /* code */
        }
        cout<<endl;

        /* code */
    }

    return 0;
}