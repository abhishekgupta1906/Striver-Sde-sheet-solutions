#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <bits/stdc++.h>
#define int long long
using namespace std;

int bfs(vector<string> &grid, int n, int m, vector<vector<pair<int, int>>> &parent, int &brow, int &bcol)
{
    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> visited(n, vector<int>(m, 0));

    // Find the start position 'A'
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 'A')
            {
                q.push({{i, j}, 0});
                visited[i][j] = 1;
                break;
            }
        }
    }

    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};
    int ansteps = INT_MAX;

    while (!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int s = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nrow = r + row[i];
            int ncol = c + col[i];

            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol])
            {
                if (grid[nrow][ncol] == '.')
                {
                    visited[nrow][ncol] = 1;
                    parent[nrow][ncol] = {r, c};
                    q.push({{nrow, ncol}, s + 1});
                }
                else if (grid[nrow][ncol] == 'B')
                {
                    visited[nrow][ncol] = 1;
                    brow = nrow;
                    bcol = ncol;
                    if (s + 1 < ansteps)
                    {
                        ansteps = s + 1;
                        parent[nrow][ncol] = {r, c};
                    }
                }
            }
        }
    }

    if (visited[brow][bcol] == 0)
    {
        return -1;
    }
    return ansteps;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);

    for (int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }

    vector<vector<pair<int, int>>> parent(n, vector<pair<int, int>>(m, {-1, -1}));
    int brow = 0, bcol = 0;

    int ans = bfs(grid, n, m, parent, brow, bcol);

    if (ans == -1)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
        cout << ans << '\n';

        string s = "";

        int row[4] = {-1, 1, 0, 0};
        int col[4] = {0, 0, -1, 1};
        char path[4] = {'U', 'D', 'L', 'R'};
        while (grid[brow][bcol] != 'A')
        {
            int pr = parent[brow][bcol].first;
            int pc = parent[brow][bcol].second;
            for (int i = 0; i < 4; i++)
            {
                int nrow = pr + row[i];
                int ncol = pc + col[i];
                if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m)
                {
                    if (nrow == brow && ncol == bcol)
                    {
                        s += path[i];
                        break;
                    }
                }
                /* code */
            }

            brow = pr;
            bcol = pc;
        }

        reverse(s.begin(), s.end());
        cout << s << '\n';
    }

    return 0;
}
