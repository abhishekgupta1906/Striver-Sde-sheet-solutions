#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
int countPalindromicSubsequence(string s)
{
    int n = s.length();
    vector<vector<int>> prefix(26, vector<int>(n, 0));
    // prefix[i][j]-cnt of character i till jth index
    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < n; i++)
        {
            char temp = 'a' + i;
            if (j >= 1)
            {
                prefix[i][j] = ((temp == s[j]) ? 1 : 0) + prefix[i][j - 1];
            }
            else
            {
                prefix[i][j] = (temp == s[j]) ? 1 : 0;
            }

            /* code */
        }

        /* code */
    }

    map<char, vector<int>> mp;
    for (int i = 0; i < s.length(); i++)
    {
        mp[s[i]].push_back(i);
        /* code */
    }
    int ans = 0;
    map<string, bool> mp1;
    for (auto it : mp)
    {
        char temp=it.first;
        vector<int>v=mp[it.first];
        int ind1=v[0];
        int ind2=v[v.size()-1];
        if(ind2-ind1<2){
          continue;
        }
        for (int i = 0; i <26; i++)
        {
            int count=0;
            count=prefix[i][ind2-1]-prefix[i][ind1];
            if(count!=0){
                string check="";
                check+=temp;
                char var1='a'+i;
                check+=var1;
                check+=temp;
                if(mp1.find(check)==mp1.end()){
                    ans++;
                    mp1[check]=true;
                }
                
            }

            /* code */
        }
        
    }
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    char c = 'a' + 2;
    cout << c;

    return 0;
}