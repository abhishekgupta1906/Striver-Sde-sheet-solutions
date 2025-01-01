#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    // build graph
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < flights.size(); i++)
    {
        int u = flights[i][0];
        int v = flights[i][1];
        int w = flights[i][2];
        adj[u].push_back({v, w});
        // pehla node dusra distance

        /* code */
    }

    set<pair<int, pair<int, int>>>st;
    // pehle distance dusra node teesra stops
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    int cheap = INT_MAX;
    st.insert({-1, {0,src}});
    while (!st.empty())
    {
        auto it = st.begin();
        int stops = it->first;
        int d= (it->second).first;
        int u= (it->second).second;
       st.erase(it);
        if (stops > k)
        {
            continue;
        }
        if (u == dst && stops <= k)
        {
            cheap = min(cheap, d);
            continue;
        }

        for (auto it : adj[u])
        {
            int v = it.first;
            int w = it.second;
            if (d + w < dist[v] && stops <= k)
            {
                dist[v] = d + w;
                st.insert({stops+1, {dist[v], v}});
            }
        }
    }
    if (cheap == INT_MAX)
    {
        return -1;
    }
    return cheap;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> flights = {{0, 1, 1}, {0, 2, 5}, {1, 2, 1}, {2, 3, 1}};
    int ans = findCheapestPrice(4, flights, 0, 3, 1);
    cout << ans;

    return 0;
}