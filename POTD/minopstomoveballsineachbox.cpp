#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int> minOperations(string boxes)
{
    int n=boxes.length();
    map<char,vector<int>>mp;
    for (int i = 0; i <n; i++)
    {
        if(boxes[i]=='1'){
            mp[boxes[i]].push_back(i);
        }
        /* code */
    }
    vector<int>v=mp['1'];
    int m=v.size();
    vector<int>prefix(v.size(),0);
    prefix[0]=v[0];
    for (int i =1; i <v.size(); i++)
    {
        prefix[i]=v[i]+prefix[i-1];
        /* code */
    }
    
    vector<int>ans(n);
    for (int i = 0; i <n; i++)
    {
       
        int result=0;
        auto it=upper_bound(v.begin(),v.end(),i);
        if(it==v.begin()){
            int ind=0;
            int rangesum=prefix[m-1];
            result+=(rangesum-(m*i));
        }
        else{
            int ind=it-v.begin();
            // ind se last tk range sum chaiye
            int rangesum=prefix[m-1]-prefix[ind-1];
            result+=abs(rangesum-(m-ind)*i);
            int rangesum2=prefix[ind-1];
            result+=abs((ind)*i-rangesum2);
        }
        ans[i]=result;
        
        
        /* code */
    }
    return ans;
    
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string boxes="001011";
    vector<int>result=minOperations(boxes);
    for(auto it:result){
        cout<<it<<" ";
    }
    return 0;
}