#include<bits/stdc++.h>
using namespace std;
int get_sum(int&num){
    int val=num;
    int sum=0;
    while(val>0){
        sum+=(val % 10);
        val/=10;
    }
    return sum;
}
int maximumSum(vector<int>& nums) {
        //sort krdo foi farak nhi pdega
    int n=nums.size();
    sort(nums.begin(),nums.end());
    map<int,vector<int>>mp;
    for(int i=0;i<n;i++){
        int sum=get_sum(nums[i]);
        mp[sum].push_back(nums[i]);
    }
    int maxi=-1;
    for(auto it:mp){
        vector<int>v=mp[it.first];
        if(v.size()>=2){
            int m=v.size();
            maxi=max(maxi,v[m-1]+v[m-2]);
        }
    } 
    return maxi;  

}
int main(){
    int n;
    cin>>n;
    vector<int>nums(n);
    for(int i=0;i<n;i++){
        cin>>nums[i];
    }
    cout<<maximumSum(nums);
    return 0;
}