#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
bool check(string &prev, string &cur)
{
    if (prev.length() == 0)
    {
        return true;
    }
    if (prev.length() + 1 != cur.length())
    {
        return false;
    }
    int i = 0;
    int j = 0;
    int diff = 0;
    while (i < prev.length() && j < cur.length())
    {
        if (prev[i] == cur[j])
        {
            i++;
            j++;
        }
        else
        {
            diff++;
            j++;
        }
    }

    return i == prev.length();
}
int f(int ind, string prev, int n, vector<string> &words, map<pair<int, string>, int> &mp)
{
    //  base case
    if (ind == n)
    {
        return 0;
    }
    if (mp.find({ind, prev}) != mp.end())
    {
        return mp[{ind, prev}];
    }
    int take = 0;
    if (prev.length() == 0 || check(prev, words[ind]))
    {
        take = 1 + f(ind + 1, words[ind], n, words, mp);
    }
    int notake = f(ind + 1, prev, n, words, mp);
    mp[{ind, prev}] = max(take, notake);
    return max(take, notake);
}
// int longestStrChain(vector<string> &words)
// {
//     int n = words.size();
//     string prev = "";
//     sort(words.begin(), words.end(), [](string &a, string &b)
//          { return a.length() < b.length(); });
//     map<pair<int, string>, int> mp;
//     return f(0, prev, n, words, mp);
// }
// tabulation
int longestStrChain(vector<string> &words)
{
    int n = words.size();

    sort(words.begin(), words.end(), [](string &a, string &b)
         { return a.length() < b.length(); });
    vector<int> dp(n, 1);
    // best ans till jth index
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (check(words[j], words[i]))
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
            /* code */
        }
        maxi = max(maxi, dp[i]);

        /* code */
    }
    return maxi;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<string> words = {"bqtmbnugq","bjqtmbnuwsgq","m","btmnugq","czlhk","ihkgszexnh","wiszechhcxldcrow","kgszn","lhk","zlzfgmjurcntwvn","jjvodlrsmdmie","tm","ihqkgpszexnh","wnwpxg","zmun","hkgszenh","zmucnwn","kgzn","yjmk","wiszechcxldcrow","fnnh","yjm","jjvodlrmdmie","bqtmnugq","hkgszen","wehcxdrow","nhed","zmucn","wisehcxdrow","fnnlh","wehcxdro","zlzgmjurcntwvn","wnwg","jjvodlmde","wisechcxldcrow","wiehcxdrow","nhxyeedlcqxw","wehcxr","zzgmjurcnwvn","btmgq","nwdhslknbwpxg","ihqkgszexnh","jjvodlrsmdmhie","jjvodlmd","wdhslknbwpxg","nhedxw","wisehcxldcrow","btmugq","mfnnlfh","bqtmbnuwgq","nhedcxw","bqtmbnuwsgq","nhe","zzgmjurcntwvn","jjvodlrmdie","whslknwpxg","wdhslknwpxg","wsnwpxg","jjvodlm","hkgszexnh","zzgmjucnwvn","nhxyeedlcxw","nhxedcxw","zzmucnwn","hkgszn","zmucnw","whsnwpxg","czlmhk","whsknwpxg","wehcxro","wnwpg","nhxeedcxw","nwdhslknbjwpxg","nhedw","tmg","zlhk","zlzfgmjurcntwvnr","jjvodlmdie","zzmjucnwvn","mfnnlh","zzmjucnwn","wisehcxldrow","tmgq","nhxyeedcxw"};
    int ans = longestStrChain(words);
    cout << ans;
    return 0;
}