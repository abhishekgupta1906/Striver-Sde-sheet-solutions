#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <bits/stdc++.h>
using namespace std;
// s = "ADOBECODEBANC", t = "ABC"
// yahan pr s me ek substr pta kro jisme t ke sare characters h,minimum length
// agar man lo t="wwof" toh substr me atleast w 2 hone hone chaiye
// yahan agar kisi character ka frequency zero hogya toh delete mt krna because man lo agar wo window ans nhi h toh ,orginal need kya tha (ex-adobec)
// A->1
// B->1
// C->1
//  point this->if ke andar isliy kyu   ki agar alg se if (mp[s[j]] == 0)) agar s[j] map me present nhi h toh 
// toh integer map mp[s[j]]==0 by default

 string minWindow(string s, string t) 
    {
        if (t.size() > s.size()) return "";
    unordered_map<char, int> mp;
    int minlen = INT_MAX, start = 0;
    string ans = "";
    
    // Count frequency of characters in string t
    for (auto ch : t) {
        mp[ch]++;
    }
    
    int i = 0, j = 0, count = mp.size();
    
    while (j < s.length()) {
        if (mp.find(s[j]) != mp.end()) {
            mp[s[j]]--;
            if (mp[s[j]] == 0)
                count--;
        } 
        // this
        while (i<=j && count == 0) {
            if (mp.find(s[i]) != mp.end()) {
                mp[s[i]]++;
                if (mp[s[i]] == 1) {
                    count++;
                }
            }
            if (count == 1 && (ans == "" || ans.size() > j - i + 1)) {
                ans = s.substr(i, j - i + 1);
            }
            i++;
        }
        j++;
    }
    
    return ans;
    }  
int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    string ans = minWindow(s, t);
    cout << ans;

    return 0;
}