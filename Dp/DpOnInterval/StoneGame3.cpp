#include <iostream>
#include <climits>
#include <bits/stdc++.h>
// #define int long long
using namespace std;
// states dp[i]-max score score by alice from i to n-1
int f(int ind, int turn, vector<int> &stoneValue, vector<int>&dp)
{
    int n = stoneValue.size();
    if (ind >= n)
    {
        return 0;
    }
    if (dp[ind] != -1)
    {
        return dp[ind];
    }
    int result = (turn == 1) ? INT_MAX : INT_MIN;
    int score = 0;
    for (int X = 1; X <= min(n - ind, 3); X++)
    {
        score+=stoneValue[ind+X-1];
        if(turn == 1){

        result = max(result, score + f(ind + X, 0, stoneValue, dp));
        }
        else{
            result = min(result,f(ind + X, 1, stoneValue, dp));

        }


        /* code */
    }

    dp[ind]= result;
    return result;
}
string stoneGameIII(vector<int> &stoneValue)
{
    int n = stoneValue.size();
    vector<int>dp(n,-1);
    
    int aliceScore = f(0, 1, stoneValue, dp);
    int totalScore = accumulate(stoneValue.begin(), stoneValue.end(), 0);
    int bobScore = totalScore - aliceScore;
    string s = "";
    if (aliceScore > bobScore)
    {
        s += "Alice";
        return s;
    }
    else if (aliceScore == bobScore)
    {
        s += "Tie";
    }
    else
    {
        s += "Bob";
    }
    return s;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<int> stoneValue = {1, 2, 3, -9};
    string s = stoneGameIII(stoneValue);
    cout << s;
    return 0;
}