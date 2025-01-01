#include <iostream>
#include <bits/stdc++.h>

using namespace std;
string longestDiverseString(int a, int b, int c)
{
 multiset<std::pair<int, char>> mt;
    if (a > 0) mt.insert({a, 'a'});
    if (b > 0) mt.insert({b, 'b'});
    if (c > 0) mt.insert({c, 'c'});
    
    string ans = "";
    
    while (!mt.empty()) {
        auto it =prev(mt.end());
        char t = it->second;
        int n = ans.length();
        int freq = it->first;
        
        
        if (freq == 0) {
            mt.erase(it);
            continue;
        }
        
       
        if (freq >= 2 && (n == 0 || ans[n - 1] != t)) {
            ans += t;
            ans += t;
            mt.erase(it);
            if (freq - 2 > 0) {
                mt.insert({freq - 2, t});
            }
        }
       
        else if (n==0 || ans[n - 1] != t) {
            ans += t;
            mt.erase(it);
            if (freq - 1 > 0) {
                mt.insert({freq - 1, t});
            }
        }
        
        else {
            if (mt.size() > 1) {
                auto it2 =prev(it);
                char temp = it2->second;
                int tempFreq = it2->first;
                
                if (tempFreq > 0) {
                    ans += temp;
                    mt.erase(it2);
                    if (tempFreq - 1 > 0) {
                        mt.insert({tempFreq - 1, temp});
                    }
                }
            } else {
                break; 
            }
        }
    }
    
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string ans = longestDiverseString(7,3, 1);
    cout << ans;

    return 0;
}