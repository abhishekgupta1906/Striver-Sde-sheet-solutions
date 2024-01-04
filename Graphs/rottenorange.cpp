#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;
// rotten orange fresh orange ko bhi rotten bna dega
// 4 adjacent positions top down bottom up
// agar koi aisa orange jo visited na hua ho
// for ( int i = 0; i <n; i++)
// {
//     for (int j = 0; j <m; j++)
//     {
//         if(vis[i][j]!=2 && grid[i][j]==1)
//         {
//            return -1;

//         }
//         /* code */
//     }

//     /* code */
// }
int minTimeToRot(vector<vector<int>> &grid, int n, int m)
{
    // search for rotten orange position
    vector<vector<int>> vis(n, vector<int>(m, 0));

    queue<pair<pair<int, int>, int>> q;
    // count maintain krke
    int fresh = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 2)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 2;
            }
            else if (grid[i][j] == 1)
            {
                fresh++;
            }
            /* code */
        }

        /* code */
    }
    int anstime = 0;
    // count how many fresh become rotten
    int rottfresh = 0;

    // bfs
    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();
        anstime = max(anstime, t);
        int row[4] = {-1, 1, 0, 0};
        int col[4] = {0, 0, -1, 1};
        for (int i = 0; i < 4; i++)
        {
            int nrow = r + row[i];
            int ncol = c + col[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1)
            {
                q.push({{nrow, ncol}, t + 1});
                vis[nrow][ncol] = 2;
                rottfresh++;
            }
        }
    }
    if (fresh != rottfresh)
    {
        return -1;
    }

    return anstime;

    // Write your code here.
}
int main()
{
    vector<vector<int>> v{{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    int a = minTimeToRot(v, 3, 3);
    cout << a;

    return 0;
}