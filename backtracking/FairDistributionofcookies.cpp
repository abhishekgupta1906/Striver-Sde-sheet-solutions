#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
void f(int ind, vector<int> &cookies, int k, vector<int> &child, int &ans)
{
    // base case
    int n = cookies.size();

    if (ind == n)
    {
        int maxi = *max_element(child.begin(), child.end());
        ans = min(ans, maxi);
        return ;
    }

    for (int i = 0; i < k; i++)
    {
        child[i]+= cookies[ind];
        f(ind + 1, cookies, k, child, ans);
        child[i]-=cookies[ind];
        /* code */
    }
}
int distributeCookies(vector<int> &cookies, int k)
{
    int ans=INT_MAX;
    vector<int>child(k,0);
    f(0,cookies,k,child,ans);
    return ans;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int>cookies={8,15,10,20,8};
    int ans=distributeCookies(cookies,2);
    cout<<ans;
    
    return 0;
}