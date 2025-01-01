#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
// dp[i,j]=max value of m from str1[i...n-1] and str2[j...m-1]
// memory limit exceeded 1e8
// int f(string &str1, string &str2, int i, int j,vector<vector<int>>&dp)
// {
//     int n = str1.size();
//     int m = str2.size();
//     // base case
//     if (i == n)
//     {
//         if (j == m)
//         {
//             return 1;
//         }
//         return 0;
//     }
//     // cache check
//     if(dp[i][j]!=-1){
//         return dp[i][j];
//     }

//     // computation
//     int ans = 0;
//     if (j == m)
//     {
//         ans = max(ans, 1 + f(str1, str2, i, 0,dp));
//     }
//     if (str1[i] == str2[j])
//     {
//         ans = max(ans, f(str1, str2, i + 1, j + 1,dp));
//     }
//     ans = max(ans, f(str1, str2, i + 1, j,dp));
//     dp[i][j]=ans;
//     return ans;
// }
// int getMaxRepetitions(string s1, int n1, string s2, int n2)
// {
//     string str1 = "";
//     string str2 = "";
//     for (int i = 0; i < n1; i++)
//     {
//         str1 += s1;
//     }
//     for (int i = 0; i < n2; i++)
//     {
//         str2 += s2;
//     }
//     int n = str1.size();
//     int m = str2.size();
//     vector<vector<int>>dp(n,vector<int>(m,-1));
//     return f(str1, str2, 0, 0,dp);
// }

int getMaxRepetitions(string s1, int n1, string s2, int n2)
{
    int c1 = 0;
    int c2 = 0;
    int i = 0;
    int j = 0;
    int n = s1.size();
    
    // string str = "";
    // for (int i = 0; i < n2; i++)
    // {
    //     str += s2;
    //     /* code */
    // }
    int m=s2.size();

    while (c1 < n1)
    {
        if (s1[i] ==s2[j])
        {
            j++;
        }
        i++;
        if (i == n)
        {
            i = 0;
            c1++;
        }
        if (j == m)
        {
            j = 0;
            c2++;
        }
    }
    return c2/n2;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s1 = "acb";
    string s2 = "ab";
    int ans = getMaxRepetitions(s1, 4, s2, 2);
    cout << ans;
    return 0;
}