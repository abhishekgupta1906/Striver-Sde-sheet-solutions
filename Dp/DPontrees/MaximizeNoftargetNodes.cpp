#include <iostream>
#include <vector>
#include <algorithm>
#define int long long
using namespace std;

void dfs1(int currnode, int parent, vector<vector<int>> &adj, vector<int> &evensubans, vector<int> &oddsubans)
{
    evensubans[currnode] = 1;
    oddsubans[currnode] = 0;
    for (auto it : adj[currnode])
    {
        if (it != parent)
        {
            dfs1(it, currnode, adj, evensubans, oddsubans);
            evensubans[currnode] += oddsubans[it];
            oddsubans[currnode] += evensubans[it];
        }
    }
}

void dfs2(int currnode, int parent, vector<vector<int>> &adj, vector<int> &evensubans, vector<int> &oddsubans, vector<int> &even, vector<int> &odd)
{
    for (auto it : adj[currnode])
    {
        if (it != parent)
        {
            int totaleven = even[currnode];
            int totalodd = odd[currnode];
            int neweven = totaleven - oddsubans[it];
            int newodd = totalodd - evensubans[it];

            even[it] = evensubans[it] + newodd;
            odd[it] = oddsubans[it] + neweven;

            dfs2(it, currnode, adj, evensubans, oddsubans, even, odd);
        }
    }
}

vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
{
    // Build tree 1
    int n = edges1.size() + 1;
    int m = edges2.size() + 1;
    vector<vector<int>> adj1(n);
    vector<vector<int>> adj2(m);
    for (int i = 0; i < edges1.size(); i++)
    {
        int u = edges1[i][0];
        int v = edges1[i][1];
        adj1[u].push_back(v);
        adj1[v].push_back(u);
    }
    for (int i = 0; i < edges2.size(); i++)
    {
        int u = edges2[i][0];
        int v = edges2[i][1];
        adj2[u].push_back(v);
        adj2[v].push_back(u);
    }

    // Initialize vectors for the first tree
    vector<int> evensubans(n, 0);
    vector<int> oddsubans(n, 0);
    vector<int> even1(n, 0);
    vector<int> odd1(n, 0);

    dfs1(0, -1, adj1, evensubans, oddsubans);
    even1[0] = evensubans[0];
    odd1[0] = oddsubans[0];
    dfs2(0, -1, adj1, evensubans, oddsubans, even1, odd1);

    vector<int> evensubans2(m, 0);
    vector<int> oddsubans2(m, 0);
    vector<int> even2(m, 0);
    vector<int> odd2(m, 0);

    dfs1(0, -1, adj2, evensubans2, oddsubans2);
    even2[0] = evensubans2[0];
    odd2[0] = oddsubans2[0];
    dfs2(0, -1, adj2, evensubans2, oddsubans2, even2, odd2);

    vector<int> result(n);
    int maxi = *max_element(odd2.begin(), odd2.end());
    for (int i = 0; i < n; i++)
    {
        result[i] = even1[i] + maxi;
    }
    return result;
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> edges1 = {{0, 1}, {0, 2}, {2, 3}, {2, 4}};
    vector<vector<int>> edges2 = {{0, 1}, {0, 2}, {0, 3}, {2, 7}, {1, 4}, {4, 5}, {4, 6}};

    vector<int> result = maxTargetNodes(edges1, edges2);
    for (auto it : result)
    {
        cout << it << " ";
    }

    return 0;
}