#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
int minimumDeletions(vector<int> &nums)
{
    int mini=0;
    // dono me se minimum index
    int maxi=0;
    // dono ka maxium index
    int n=nums.size();
    set<pair<int,int>>st;
    for (int i = 0; i <n; i++)
    {
        st.insert({nums[i],i});
        /* code */
    }
    auto it=st.rbegin();
    int val1=it->second;
    auto it2=st.begin();
    int val2=it2->second;
    mini=min(val1,val2);
    maxi=max(val1,val2);
    int choice1=maxi+1;
    int choice2=n-mini;
    int choice3=(n-maxi)+(mini+1);
    return min({choice1,choice2,choice3});



    
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}