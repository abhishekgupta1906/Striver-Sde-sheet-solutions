#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
// out of bound dimaag me rkhna
// dp[i]-is substring from i to n-1 can be segemented
void f(int ind,string&s,vector<string> &wordDict,vector<string>&result,vector<vector<string>>&ans,map<string,bool>&mp){
    int n=s.length();
   
    if(ind==n){
        ans.push_back(result);
        return ;
    }
     for (int i =1; i <= n-ind; i++) {
        string str = s.substr(ind, i);
        if (mp.find(str) != mp.end()) {
            result.push_back(str);
            f(ind+i, s, wordDict, result, ans, mp);
            result.pop_back();
        }
    }
    
    
}
vector<string> wordBreak(string s, vector<string> &wordDict)
{
    vector<vector<string>>ans;
    vector<string>result;
    map<string,bool>mp;
    for(auto it:wordDict){
       mp[it]=true;
    }
    f(0,s,wordDict,result,ans,mp);
    result.clear();
    for (int i = 0; i <ans.size(); i++)
    {
        string s="";
        for (int j = 0;j<ans[i].size();j++)
        {
            s+=ans[i][j];
            if(j!=ans[i].size()-1){
                s+=" "; 
            }
            /* code */
        }
        result.push_back(s);
        
        /* code */
    }
    return result;
    

}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s="catsanddog";
    vector<string>wordDict={"cat","cats","and","sand","dog"};
    vector<string>result=wordBreak(s,wordDict);
    for(auto it:result){
        cout<<it<<"\n";

    }
    
    return 0;
}