#include <iostream>
#include <bits/stdc++.h>
// leetcode-2981
using namespace std;
bool check(string &s)
{
    char c = s[0];
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] != c)
        {
            return false;
        }
        /* code */
    }
    return true;
}
int maximumLength(string s)
{
    int len =-1;
    int n = s.length();
    map<string, int> mp;
    for (int i = 0; i <n; i++)
    {
        string str="";
        for (int j =i; j <n; j++)
        {
            str+=s[j];
            mp[str]++;
            /* code */
        }
        
        /* code */
    }
    for(auto it:mp){
        string str=it.first;
        if(check(str) && it.second>=3){
            int a=(int)str.length();
            len=max(len,a);
        }
    }
    return len;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s="abcdef";
    int ans=maximumLength(s);
    cout<<ans;

    return 0;
}