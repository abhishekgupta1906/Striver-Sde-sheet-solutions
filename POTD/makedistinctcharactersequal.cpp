#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool isItPossible(string word1, string word2)
{
    map<char, int> mp1;
    map<char, int> mp2;
    for (auto it : word1)
    {
        mp1[it]++;
    }
    for (auto it : word2)
    {
        mp2[it]++;
    }
    // go in each distinct char in mp1
    // go inj distinct char in mp2
    if (mp1.size() == mp2.size())
    {
      
    }
    for (auto it1 : mp1)
    {
        for (auto it2 : mp2)
        {
            // equals ko mt dekhna
            if (it1.first == it2.first)
            {
                continue;
            }
            char t1 = it1.first;
            char t2 = it2.first;
            mp1[t1]--;
            if (mp1[t1] == 0)
            {
                mp1.erase(t1);
            }
            mp2[t2]--;
            if (mp2[t2] == 0)
            {
                mp2.erase(t2);
            }
            // overall remove
            mp1[t2]++;
            mp2[t1]++;

            if (mp1.size() == mp2.size())
            {
                //    for(auto it:mp1){
                //     cout<<it.first<<" ";
                //    }
                //    cout<<"\n";
                //     for(auto it:mp2){
                //     cout<<it.first<<" ";
                //    }

                return true;
            }
            mp1[t2]--;
            if (mp1[t2] == 0)
            {
                mp1.erase(t2);
            }
            mp2[t1]--;
            if (mp2[t1] == 0)
            {
                mp2.erase(t1);
            }
            // restore
            mp1[t1]++;
            mp2[t2]++;
        }
    }
    return false;
}
int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    bool ans = isItPossible(s1, s2);
    if (ans)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}