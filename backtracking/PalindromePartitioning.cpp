#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string&str)
{
    int start=0;
    int end=str.length()-1;
    while(start<=end)
    {
        if(str[start]!=str[end])
        {
            return false;
        }
        start++;
        end--;
    }
    return true;
}
void f(int n, int ind, string &s, vector<string> &ans, vector<vector<string>> &output)
{
    if (ind == n)
    {
        output.push_back(ans);
        return ;
    }
    for (int i =ind; i <n; i++)
    {
        string str=s.substr(ind,i-ind+1);
        if(isPalindrome(str))
        {
            ans.push_back(str);
            f(n,i+1,s,ans,output);
            ans.pop_back();
        }
        str.pop_back();
        /* code */
    }
    
}
vector<vector<string>> partition(string s)
{
    int n=s.length();
    vector<vector<string>>output;
    vector<string>ans;
    
    f(n,0,s,ans,output);
    return output;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s="aab";
    vector<vector<string>>output=partition(s);
    for(auto it:output)
    {
        vector<string>vec=it;
        for (int i = 0; i <vec.size(); i++)
        {
            cout<<vec[i]<<" ";
            /* code */
        }
        cout<<"\n";
    }
   

    return 0;
}