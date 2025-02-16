#include <iostream>
#include <bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
void solve(){
    int N,L;
    cin>>N>>L;
    vector<pair<int,int>>events(N);
    for(int i=0;i<N;i++){
        int x,y;
        cin>>x>>y;
        events[i]={x,y};
    }
    sort(events.begin(),events.end());
    int last=0;
    int maxi=0;
    int ans=0;
    int i=0;
    while(last<L){
        //  ye last covered jo point usko start man kr usse pehle ya uske barabar jiska endpoint max ho
        int newlast=last;
        while(i<N && events[i].F<=last){
            newlast=max(newlast,events[i].S);
            i++;
        }
        if(newlast==last){
            break;
        }
        ans++;
        last=newlast;
   
        
    }
    
    cout<<ans<<"\n";

}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
  

    return 0;
}