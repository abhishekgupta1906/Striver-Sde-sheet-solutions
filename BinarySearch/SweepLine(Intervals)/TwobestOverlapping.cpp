#include <iostream>
#include <bits/stdc++.h>

using namespace std;
// for jobs start time>end time of 1st job
// curr element ko second job mano
// ek particular job ek value mil gya ,ab store krlo ,age walon wapas se iterate n krna pde
int maxTwoEvents(vector<vector<int>> &events)
{
    int n = events.size();
    vector<pair<pair<int, int>, int>> startime;
    for (int i = 0; i < n; i++)
    {
        startime.push_back({{events[i][0], events[i][1]}, events[i][2]});
        /* code */
    }
    sort(startime.begin(), startime.end());
    // ye maxi-overall max sum h
    // maxvalue ek particular job ki max value ,ab bki ke liy firse iterate thori krenge
    set<pair<pair<int, int>, int>> st;
    int maxi = 0;
    int maxvalue = 0;
    for (int i = 0; i < n; i++)
    {
        // current second job ,1st job nikalo
        int start = startime[i].first.first;
        int end1 = startime[i].first.second;
        int value = startime[i].second;
        while (!st.empty())
        {
            auto it = st.begin();
            int end = it->first.first;
            if (start > end)
            {
                maxvalue = max(maxvalue, it->second);
                st.erase(it);
            }
            else
            {
                break;
            }
        }
        st.insert({{end1, start}, value});
        maxi = max(maxi, maxvalue + value);
        /* code */
    }
    return maxi;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<vector<int>> v = {{1, 3, 2}, {4, 5, 2}, {2, 4, 3}};
    int ans = maxTwoEvents(v);
    cout << ans;
    return 0;
}