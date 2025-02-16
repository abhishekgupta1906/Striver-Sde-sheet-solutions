#include <iostream>
#include <bits/stdc++.h>

using namespace std;
vector<int> queryResults(int limit, vector<vector<int>> &queries)
{
    map<int, int> mp1;
    // ball->color
    // color->ball;
    map<int, vector<int>> mp2;
    int n = queries.size();
    vector<int> result(n);
    for (int i = 0; i < n; i++)
    {
        int x = queries[i][0];
        int color = queries[i][1];
        if (mp1.find(x) != mp1.end())
        {
            // x purane color ke saath exist kr rha h
            int old_color = mp1[x];
            vector<int> &v = mp2[old_color];
            auto it = lower_bound(v.begin(), v.end(), x);
            v.erase(it);
        }
        mp1[x]=color;
        mp2[color].push_back(x);
        result[i]=(int)mp2.size();
    }
    return result;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}