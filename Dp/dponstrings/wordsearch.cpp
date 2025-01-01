#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
// dp(i)-is string from i to n-1 can be segemented into words which are in wordlist
bool f(int i,string &s,map<string,bool>&mp,vector<int>&dp)
{
    int n=s.length();
    if(mp.find(s) != mp.end()){
        return true;
    }
    if(i>=n){
        return true;
    }
    if(dp[i]!=-1){
        return dp[i];
    }
    for (int l =1; l <=n; l++)
    {
        string str=s.substr(i,l);
        if(mp.find(str)!=mp.end()){
            bool ans=f(i+l,s,mp,dp);
            if(ans){
               dp[i]=ans;
               return true;
            }
        }
        /* code */
    }
    dp[i]=0;
    return false;


}
bool wordBreak(string s, vector<string> &wordDict)
{
    int n=s.length();
    map<string,bool>mp;
    for(auto it:wordDict){
        mp[it]=true;
    }
    vector<int>dp(n,-1);
    return f(0,s,mp,dp);
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s="AbhiShek";
    vector<string>worDict={"Abhi","Shek"};
    bool ans=wordBreak(s,worDict);
    cout<<ans;
    return 0;
}