#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
using event=vector<int>;
void solve(){
    int n;
    cin>>n;
    vector<event>events;
    for(int i=0;i<n;i++){
        int l,r,x;
        cin>>l>>r>>x;
        events.push_back({l,0,x,0,0});
        events.push_back({r,2,x,0,0});
    
    }
    int q;
    cin>>q;
    vector<int>ans(q);
    for(int i=0;i<q;i++){
        int y,z;
        cin>>y>>z;
        events.push_back({y,1,0,i,z});
       
    }
    sort(events.begin(),events.end(),[](const vector<int>&a,const vector<int>&b){
        if(a[0]!=b[0]){
            return a[0]<b[0];
        }
        return a[1]<b[1];
    });
    multiset<int>mt;
    for(int i=0;i<events.size();i++){
        vector<int>v=events[i];
        if(v[1]==0){
          mt.insert(v[2]);
        }
        else if(v[1]==2){
            auto it=mt.find(v[2]);
            if(it!=mt.end()){
                mt.erase(it);
            }
        }
        else{
            int z=v[4];
            auto it=mt.upper_bound(z);
            int ans1=-1;
            if(it!=mt.begin()){
                it--;
                ans1=*(it);
            }
            ans[v[3]]=ans1;


        }
    }
    for(auto it:ans){
        cout<<it<<"\n";
    }


}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}