#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
// form-2
char next_char(char c)
{
    return (c == 'z') ? 'a' : c + 1;
}


int findSubstringInWraproundString(string s)
{
    vector<int> dp(26, 0);
    // longest length starting at index i
    if(s.length()==1){
        return 1;
    }
    int maxlength =1;
    dp[s.back() - 'a'] = 1;
    for (int i = s.length() - 2; i >= 0; i--)
    {
        char curr = s[i];
        char next = next_char(curr);
        if (next == s[i + 1])
        {
            maxlength++;
        }
        else
        {
            maxlength = 1;
        }
        dp[curr - 'a'] = max(dp[curr - 'a'], maxlength);

        /* code */
    }
    int ans=0;
    for(auto it:dp){
        ans+=it;
    }
    return ans;
    
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s = "acabc";
    int ans = findSubstringInWraproundString(s);
    cout << ans;
    return 0;
}