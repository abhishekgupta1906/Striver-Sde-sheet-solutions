#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
using event=vector<int>;
// l ,query type,x,bogus

vector<int> minInterval(vector<vector<int>> &intervals, vector<int> &queries)
{
    int q = queries.size();
    int n = intervals.size();
    vector<event> events;
    for (int i = 0; i < n; i++)
    {
        int l = intervals[i][0];
        int r = intervals[i][1];
        int size=r-l+1;
        events.push_back({l,0,size,0});
        events.push_back({r,2,size,0});
    }
    for(int i=0;i<q;i++){
        events.push_back({queries[i],1,0,i});
    }
    multiset<int>mt;
    sort(events.begin(),events.end(),[](const vector<int>&a,const vector<int>&b){
        if(a[0]!=b[0]){
          return a[0]<b[0];
        }
        return a[1]<b[1];
    });
    vector<int> ans(q);
    for(int i=0;i<events.size();i++){
        vector<int>v=events[i];
        if(v[1]==0){
            mt.insert(v[2]);
        }
        else if(v[1]==2){
            mt.erase(v[2]);
        }
        else{
            if(!mt.empty()){
                ans[v[3]]=*mt.begin();
            }
            else{
                ans[v[3]]=-1;
            }
        }

    }
    return ans;
    // offline queries
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}