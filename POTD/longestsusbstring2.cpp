#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int maximumLength(string s)
{
    int n = s.length();
    // ek charactre max n baar ho skta h
    vector<vector<int>> freq(26, vector<int>(n + 2, 0));
    // freq[a][len]
    freq[s[0] - 'a'][1] += 1;
  
    int len = 1;
    int i = 0;
    int j = 1;
    while (j < n)
    {
        if (s[j] == s[i])
        {
            len++;
            freq[s[j] - 'a'][len] += 1;
        }
        else
        {
           
            len = 1;
            freq[s[j] - 'a'][len] += 1;
            i = j;
        }
        j++;
    }
    int l = -1;
    for (int i = 0; i < 26; i++)
    {
        if (freq[i][1] >= 3)
        {
            l=max(l,1);
        }

        /* code */
    }

   

    for (int i = 0; i < 26; i++)
    {
        for (int len =n-1; len >= 1; len--)
        {
           
            freq[i][len]+= freq[i][len + 1];
            if(freq[i][len+1]>=3){
                l=max(l,len);
                break;
            }
            if (freq[i][len] >= 3)
            {
                l = max(l, len);
                break;
            }

            /* code */
        }

        /* code */
    }
    return l;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s = "abcdef";
    int ans = maximumLength(s);
    cout << ans;
    return 0;
}