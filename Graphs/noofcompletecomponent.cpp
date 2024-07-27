#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
class Dsu
{
public:
    vector<int> parent;
    vector<int> s;
    Dsu(int n)
    {
        parent.resize(n);
        s.resize(n);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
            s[i] = 1;
            /* code */
        }
    }
    int findParent(int node)
    {
        if (parent[node] == node)
        {
            return node;
        }
        return findParent(parent[node]);
    }
    void unionbySize(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);

        if (pu == pv)
            return;
        if (s[pu] < s[pv])
        {
            parent[pu] = pv;
            s[pv] += s[pu];
        }
        else
        {
            parent[pv] = pu;
            s[pu] += s[pv];
        }
    }
};
int countCompleteComponents(int n, vector<vector<int>> &edges)
{
    Dsu ds(n);
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        ds.unionbySize(u, v);
        /* code */
    }
    // no of components
    int count = 0;
    for (int i = 0; i < ds.parent.size(); i++)
    {
        if (ds.parent[i] == i)
        {
            count++;
        }
        /* code */
    }
    return count;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}