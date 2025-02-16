#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
bool check(string&s,int ind,int target){
    // base case
    int n=s.length();
    if(target<0){
        return false;
    }
    if(ind==n-1){
        int val=s[n-1]-'0';
        if(target-val==0){
            return true;
        }
        return false;
    }
    for(int l=1;l<n-ind;l++){
        string str=s.substr(ind,l);
        int val=stoi(str);
        bool ans1=check(s,ind+l,target-val);
        if(ans1){
            return true;
        }
    }
    return false;


}
int punishmentNumber(int n)
{
    int sum=0;
    for(int i=1;i<=n;i++){
        int val=i*i;
        string s=to_string(val);
        if(check(s,0,i)){
            sum+=val;
        }
    }
    return sum;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n=8;
    int val=n*n;
   
    string s=to_string(val);
    cout<<s;
    bool ans=check(s,0,n);
    cout<<ans;
    return 0;
}