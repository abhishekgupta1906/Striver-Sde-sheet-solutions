#include<iostream>
#include<string>
#include<vector>
#include <bits/stdc++.h>
using namespace std;
 vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        priority_queue<pair<int, int>>pq;
    unordered_map<int,int>mp;
    for (int i = 0; i <nums.size(); i++)
    {
        mp[nums[i]]++;
        /* code */
    }
    // insert into priority queue
     for (int i = 0; i <nums.size(); i++)
    {
        if(mp.find(nums[i])!=mp.end())
        {
            pq.push({mp[nums[i]], nums[i]});
            mp.erase(nums[i]);
        }
        /* code */
    }
    int K=k;
    vector<int>ans;
    while(K!=0)
    {
        auto it=pq.top();
        pq.pop();
        ans.push_back(it.second);
        K--;
    }
    return ans;
        
    }
int main()
{
    
return 0;
}