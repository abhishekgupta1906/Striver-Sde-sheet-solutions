#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
bool check(int m, map<int, int> &mp, int n)
{
    for (int i = 0; i < m; i++)
    {
        if (mp[i] == n)
        {
            return true;
        }
        /* code */
    }
    return false;
}
int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat)
{
    map<int, pair<int, int>> mp;
    // this map is for tracking position of element in matrix
    map<int, int> row, col;
    // this map is for tracking how many elements are painted in particular row
    int m = mat.size();
    int n = mat[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mp[mat[i][j]] = {i, j};
            /* code */
        }

        /* code */
    }
    int ans = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        auto it = mp[arr[i]];
        // it.first is row and it.second is column
        row[it.first]++;
        col[it.second]++;
        bool ans1 = check(m, row, n);
        bool ans2 = check(n, col, m);
        if (ans1 == 1 || ans2 == 1)
        {
            ans = i;
            break;
        }
        /* code */
    }
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}