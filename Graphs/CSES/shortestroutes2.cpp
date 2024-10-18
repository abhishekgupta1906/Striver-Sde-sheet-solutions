#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#define int long long
using namespace std;
// need to find shortest path between two cities for queries
void floyd_using(int n, vector<vector<long long>> &cost)
{
    for (int via = 0; via < n; via++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (cost[i][via] < LLONG_MAX && cost[via][j] < LLONG_MAX)
                {
                    cost[i][j] = min(cost[i][j], cost[i][via] + cost[via][j]);
                }
                /* code */
            }

            /* code */
        }

        /* code */
    }
}
signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m, q;
    cin >> n >> m >> q;
    vector<vector<long long>> cost(n, vector<int>(n,LLONG_MAX));
    for (int i = 0; i < m; i++)
    {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        a--;
        b--;
        cost[a][b] =min(c,cost[a][b]);
        cost[b][a] =min(c,cost[b][a]);

        /* code */
    }
    for (int i = 0; i < n; i++)
    {
        cost[i][i] = 0;
        /* code */
    }
    floyd_using(n, cost);
    for (int i = 0; i < q; i++)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        if (cost[a][b] == LLONG_MAX)
        {
            int ans = -1;
            cout << ans << "\n";
        }
        else
        {
            cout << cost[a][b] << "\n";
        }

        /* code */
    }

    return 0;
}