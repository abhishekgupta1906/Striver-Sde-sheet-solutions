#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
class RandomizedSet
{
public:
    map<int, bool> mp;
    RandomizedSet()
    {
    }

    bool insert(int val)
    {
        if (mp.find(val) != mp.end())
        {
            return false;
        }
        mp[val] = true;
        return true;
    }

    bool remove(int val)
    {
        if (mp.find(val) != mp.end())
        {
            mp.erase(val);
            return true;
        }
        return false;
    }

    int getRandom()
    {
        int n = mp.size();
        int r = rand() % n;
        auto it = mp.begin();
        advance(it, r);
        return it->first;
    }
};
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}