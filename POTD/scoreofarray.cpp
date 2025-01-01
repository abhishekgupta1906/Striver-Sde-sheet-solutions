#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
long long findScore(vector<int> &nums)
{
    long long ans=0;
    int n=nums.size();
    set<pair<long long,long long>>st;
    for (int i = 0; i <nums.size(); i++)
    {
        st.insert({nums[i],i});
        
    }
    while(!st.empty()){
        auto it=st.begin();
        long long val=it->first;
        long long ind=it->second;
        ans+=val;
        if(ind-1>=0){
            st.erase({nums[ind-1],ind-1});
        }
        if(ind+1<n){
            st.erase({nums[ind+1],ind+1});
        }
        st.erase(it);
    }
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int>nums={2,1,3,4,5,2};
    cout<<findScore(nums)<<"\n";
    return 0;
}