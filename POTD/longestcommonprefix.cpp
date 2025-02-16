#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int len(string &s1, string s2)
{
    int mini=min(s1.length(),s2.length());
    int count=0;
    for (int i = 0; i <mini; i++)
    {
        if(s1[i]==s2[i]){
            count++;
        }
        else{
            break;
        }

        /* code */
    }
    return count;
    
}
int longest(vector<string> &arr)
{
    int n = arr.size();
    size_t maxi = 0;
    map<string, bool> mp;
    for (int i = 0; i < arr.size(); i++)
    {
        mp[arr[i]] = true;
        /* code */
    }
    for (int i = 0; i < n; i++)
    {
        mp.erase(arr[i]);
        if (mp.size() >= 2)
        {
            auto it2 = mp.begin();

            string prefix = it2->first;

            for (auto it : mp)
            {
                int ans=len(prefix,it.first);
                prefix=prefix.substr(0,ans);

            }
            maxi=max(maxi,prefix.size());
        }
        mp[arr[i]]=true;
        /* code */
    }
    return maxi;
}
int main()   
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<string>arr={"geeksforgeeks", "geeks", "geek","geezer"};
    cout<<longest(arr);

    return 0;
}