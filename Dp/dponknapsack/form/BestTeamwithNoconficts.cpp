#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
// dp[i]-maxium possible upto the ith index
int f(int ind,vector<pair<int,int>>&team, vector<int>&dp){
    int n=team.size();
    if(ind==n)return 0;
    if(dp[ind]!=-1){
        return dp[ind];
    }
    pair<int,int>curr=team[ind];
    int maxscore=curr.second;
    for (int i =ind-1; i>=0; i--)
    {
        pair<int,int>prev=team[i];
        if(curr.second>=prev.second){
           int score=prev.second+f(i,team,dp);
           maxscore=max(maxscore,score);
        }
        
        /* code */
    }
    dp[ind]=maxscore;
    return maxscore;

}
int bestTeamScore(vector<int> &scores, vector<int> &ages)
{
    int n=scores.size();
    vector<pair<int,int>>team;
    for (int i = 0; i <n; i++)
    {
        team.push_back({ages[i],scores[i]});
        /* code */
    }
    sort(team.begin(),team.end());
    vector<int>dp(n,-1);
   
    int maxi=0;
    for (int i =n-1; i>=0; i--)
    {
        int score=f(i,team,dp);
        maxi=max(maxi,score);
        /* code */
    }
    return maxi;
    

    
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int>scores={1,2,3,5};
    vector<int>ages={8,9,10,1};
    int ans=bestTeamScore(scores,ages);
    cout<<ans;
    return 0;
}