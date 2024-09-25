#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int done = 0;
void f(int ind, int n, string &str, vector<string> &output, map<string, int> &mp)
{
    if(done==1)return;
    if (ind == n)
    {
        if (mp.find(str) == mp.end())
        {
            output.push_back(str);
            done++;
        }
        return;
    }
    for (char ch = '0'; ch <= '1'; ch++)
    {
        str.push_back(ch);
        f(ind + 1, n, str, output, mp);
        str.pop_back();
    }
}
string findDifferentBinaryString(vector<string> &nums)
{
    int n=nums[0].size();
    map<string, int>mp;
    for(auto it:nums)
    {
        mp[it]++;
    }
    string str;
    vector<string> output;
    f(0, n, str, output, mp);
    return output[0];


}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<string>nums={"00","11","10"};
    string str=findDifferentBinaryString(nums);
    cout<<str;
    return 0;
}