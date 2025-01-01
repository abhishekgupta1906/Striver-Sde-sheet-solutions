#include <iostream>
#include <bits/stdc++.h>

using namespace std;
class LRUCache
{
public:
    unordered_map<int, int> mp1;
    // key-value pair
    unordered_map<int, int> mp2;
    // time-key
    set<pair<int, int>> st;
    int capacity;
    int time;
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        this->time = 1;
    }

    int get(int key)
    {
        if (mp1.find(key) != mp1.end())
        {

            //  old time
            int t = mp2[key];
            auto it = st.find({t, key});
            if (it != st.end())
            {
                st.erase(it);
            }
            mp2[key] = time;
            st.insert({time, key});
            time++;
            return mp1[key];
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (mp1.find(key) != mp1.end())
        {
            mp1[key] = value;
            //  old time
            int t = mp2[key];
            auto it = st.find({t, key});
            if (it != st.end())
            {
                st.erase(it);
            }
            mp2[key] = time;
            st.insert({time, key});
            time++;
        }
        else
        {
            mp1[key] = value;
            mp2[key] = time;
            st.insert({time, key});
            time++;
            if (mp1.size() > capacity)
            {
                auto it = st.begin();
                int k = it->second;
                mp1.erase(k);
                mp2.erase(k);
                st.erase(it);
            }
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    set<pair<int,pair<int,int>>>st;
    st.insert({1,{2,3}});
    st.insert({1,{4,3}});
    st.insert({2,{1,3}});
    for(auto it:st){
        cout << it.first <<" "<<it.second.first<<" "<<it.second.second;
    }
    return 0;
}