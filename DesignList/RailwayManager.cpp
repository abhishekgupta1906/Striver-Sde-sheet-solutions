
#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
class UndergroundSystem
{
    map<int, pair<string, int>>mp1;
    map<pair<string, string>, vector<int>> mp2;

public:
    UndergroundSystem()
    {
    }

    void checkIn(int id, string stationName, int t)
    {
        mp1[id] = {stationName, t};
    }

    void checkOut(int id, string stationName, int t)
    {
        auto it = mp1.find(id);
        if(it!=mp1.end())
        {
            mp2[{mp1[id].first, stationName}].push_back(t - mp1[id].second);
            mp1.erase(it);
        }
    }

    double getAverageTime(string startStation, string endStation)
    {
        vector<int> v = mp2[{startStation, endStation}];
        double ans = 0;
        int sum = 0;
        for (int i = 0; i < v.size(); i++)
        {
            sum += v[i];
            /* code */
        }
        double ans = (sum * 1.00000) / v.size();
        return ans;
    }
};
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}