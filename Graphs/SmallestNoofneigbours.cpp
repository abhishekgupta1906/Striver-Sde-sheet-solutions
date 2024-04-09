#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int V, vector<vector<pair<int, int>>>& adj, int S) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> distTo(V, INT_MAX);
    distTo[S] = 0;
    pq.push({0, S});

    while (!pq.empty()) {
        int node = pq.top().second;
        int dis = pq.top().first;
        pq.pop();

        for (auto it : adj[node]) {
            int v = it.first;
            int w = it.second;
            if (dis + w < distTo[v]) {
                distTo[v] = dis + w;
                pq.push({dis + w, v});
            }
        }
    }

    return distTo;
}

int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
    // Construct the adjacency list
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    int minCount = INT_MAX;
    int smallerCity = -1;

    // Iterate over all cities
    for (int i = 0; i < n; i++) {
        // Call Dijkstra's algorithm taking every node as the source
        vector<int> array = dijkstra(n, adj, i);
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (i != j && array[j] <= distanceThreshold) {
                count++;
            }
        }
        if (count < minCount || (count == minCount && i > smallerCity)) {
            minCount = count;
            smallerCity = i;
        }
    }
    return smallerCity;
}
int main()
{
       vector<vector<int>> edges = {{0,1,2},{0,4,8},{1,2,3},{1,4,2},{2,3,1},{3,4,1}};
      int ans=findTheCity(5, edges,2);
      cout<<ans;

    return 0;
}
