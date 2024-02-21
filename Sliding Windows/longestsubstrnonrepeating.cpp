#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
// find the longest substring with non repeating
// two pointers
// int lengthOfLongestSubstring(string s)
// {
//     int i=0;
//     int j=0;
//     int ans = 0;
//     unordered_set<char>st;
//     while(j<s.length())
//     {
//         // check in the set
//         if(st.find(s[j])!=st.end())
//         {
//             while(i<j && st.find(s[j])!=st.end())
//             {
//                 st.erase(s[i]);
//                 // not j
//                 i++;
//             }
//         }

//         st.insert(s[j]);
//         ans=max(ans,j-i+1);
//         j++;
//     }
//     return ans;
// }
// more optimised
int lengthOfLongestSubstring(string s)
{
    int i = 0;
    int j = 0;
    int ans = 0;
    unordered_map<char, int> mp;
    // storing the index where this character was last seen
    while (j < s.length())
    {
        // check in the set
        if (mp.find(s[j]) != mp.end())
        {
            int lastindex = mp[str[j]];
            i = max(i, lastindex + 1);
            //    update the last index of str[j]
            //  a b c a a b c d b a
            // j-3
           
        }

        mp[s[j]] = j;
        ans = max(ans, j - i + 1);
        j++;
    }
    return ans;
}

int main()
{
    string s = "abcaabcbb";
    int ans = lengthOfLongestSubstring(s);
    cout << ans;

    return 0;
}