#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
class MyCalendarThree
{
    map<int, int> mp;

public:
    MyCalendarThree()
    {
    }

    int book(int start, int end)
    {
        mp[start]++;
        mp[end]--;
        int maxpoints = 0;
        int overlaping = 0;
        for (auto it : mp)
        {
            overlaping += it.second;
            maxpoints = max(maxpoints, overlaping);
        }
        return maxpoints;
    }
};
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}