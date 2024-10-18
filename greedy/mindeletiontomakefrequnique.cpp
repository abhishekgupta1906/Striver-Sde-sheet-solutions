#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string s)
{
    map<char, int> mp;
    set<int> st;
    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]]++;
        /* code */
    }
    vector<int> temp;
    for (auto &pair : mp)
    {
        if (st.find(pair.second) == st.end())
        {
            st.insert(pair.second);
           
        }
        else
        {
            temp.push_back(pair.second);
        }
    }
    int minoperations = 0;
    for (int i = 0; i < temp.size(); i++)
    {
        auto it = st.lower_bound(temp[i]);
        int val = *(it);
        for (int j = val - 1; j >= 0; j--)
        {
            if (st.find(j) == st.end())
            {
                minoperations += val - j;
                if(j!=0)
                {
                    st.insert(j);
                }
                break;
            }
        }
    }
    return minoperations;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s="bbcebab";
    int ans=minDeletions(s);
    cout<<ans;
    return 0;
}