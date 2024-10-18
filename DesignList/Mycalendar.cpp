#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// sweep line
class MyCalendarTwo
{
    map<int, int> mp;

public:
    MyCalendarTwo()
    {
    }

    bool book(int start, int end)
    {
        mp[start]+=1;
        mp[end]-=1;
        // abhi add kro
       
        int intersecting = 0;
        for (auto it : mp)
        {
            intersecting += it.second;
            
            if (intersecting >= 3)
            {
                mp[start]--;
                mp[end]++;
                // remove kro
                return false;
            }
        }
        return true;
    }
};

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    MyCalendarTwo *obj = new MyCalendarTwo();
    vector<pair<int, int>> v = {{10, 20}, {50, 60}, {10, 40}, {5, 15}, {5, 10}, {25, 55}};
    for (auto it : v)
    {
       
        bool ans1 = obj->book(it.first, it.second);
        cout << ans1 << "\n";
    }
    delete obj;

    return 0;
}