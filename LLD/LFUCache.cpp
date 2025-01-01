#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
class LFUCache
{
public:
    unordered_map<int, int> mp1, mp2, mp3;
    // mp1 for value ,mp2 for time ,mp3 for frequency
    int time;
    int capacity;
    set<pair<int, pair<int, int>>> st;
    LFUCache(int capacity)
    {
        this->capacity = capacity;
        time = 1;
    }

    int get(int key)
    {
        if (mp1.find(key) != mp1.end())
        {

            // old time delete
            int t = mp2[key];
            int freq = mp3[key];
            auto it = st.find({freq, {t, key}});
            if (it != st.end())
            {
                st.erase(it);
            }
            // new time and frequency insert
            mp2[key] = time;
            mp3[key] += 1;

            time++;

            st.insert({mp3[key], {mp2[key], key}});
            return mp1[key];
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (mp1.find(key) != mp1.end())
        {
            mp1[key] = value;
            // old time
            int t = mp2[key];
            int freq = mp3[key];
            auto it = st.find({freq, {t, key}});
            if (it != st.end())
            {
                st.erase(it);
            }
            // new time and frequency insert
            mp2[key] = time;
            time++;
            mp3[key] += 1;
            st.insert({mp3[key], {mp2[key], key}});
        }
        else
        {
            if (mp1.size() >= capacity)
            {
                auto it = st.begin();
                int k = (it->second).second;
                mp1.erase(k);
                mp2.erase(k);
                mp3.erase(k);
                st.erase(it);
            }
            mp1[key] = value;
            mp2[key] = time;
            time++;
            mp3[key] += 1;
            st.insert({mp3[key], {mp2[key], key}});
        }
    }
};
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}