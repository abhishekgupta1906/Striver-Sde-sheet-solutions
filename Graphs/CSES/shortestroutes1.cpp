#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#define int long long
using namespace std;
void dijkstra(int src, vector<pair<int, int>> adj[], vector<int> &dist)
{
    set<pair<int, int>> st;

    st.insert({0,src});

    while (!st.empty())
    {
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;
        st.erase(it);

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edgW = it.second;

            if (dis + edgW < dist[adjNode])
            {
                
                if (dist[adjNode] != 1e9)
                    st.erase({dist[adjNode], adjNode});

              
                dist[adjNode] = dis + edgW;
                st.insert({dist[adjNode], adjNode});
            }
        }
    }
}
signed main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> adj[n];
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        adj[a].push_back({b, c});
        /* code */
    }
    vector<int> dist(n, LLONG_MAX);
    dist[0] = 0;
    dijkstra(0, adj, dist);
    for (auto i : dist)
    {
        cout << i << " ";
    }

    return 0;
}