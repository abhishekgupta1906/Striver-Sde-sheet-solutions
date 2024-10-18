#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
void f(int n,int ind,string&digits,string&str,vector<string>&output,map<char,string>&mp)
{
    if(ind==n)
    {
        output.push_back(str);
        return ;
    }
    string s=mp[digits[ind]];
    for (int i = 0; i <s.length(); i++)
    {
        str.push_back(s[i]);
        f(n,ind+1,digits,str,output,mp);
        str.pop_back();
        /* code */
    }
    
}
vector<string> letterCombinations(string digits)
{
    int n=digits.length();
    if(n==0)
    {
        return vector<string>();
    }
    map<char,string>mp;
    mp['2']="abc";
    mp['3']="def";
    mp['4']="ghi";
    mp['5']="jkl";
    mp['6']="mno";
    mp['7']="pqrs";
    mp['8']="tuv";
    mp['9']="wxyz";
    string str;
    vector<string> output;
    f(n,0,digits,str,output,mp);
    return output;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string digits="";
    vector<string>ans=letterCombinations(digits);
    for(auto I:ans)
    {
        cout<<I<<" ";
    }
    return 0;
}