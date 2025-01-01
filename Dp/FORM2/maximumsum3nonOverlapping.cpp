#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;

// problem mainly kya mujhe subarray start from i lena chaiye ya nhi
// left ka mtlb 3 subarrays lena h
// solve ka bs ye dena kya subarray starting from i le skta hoon
// dp[i][left]-iska max sum from i to n-1 with left==3
int dp[200001][4];
int f(vector<int> &sum, int k, int left, int ind)
{
    int n = sum.size();
    if (left == 0)
    {
        return 0;
    }
    if (ind >= n)
    {
        if (left == 0)
        {
            return 0;
        }
        // kyu ki mereko exactly 3 items lena h
        return INT_MIN;
    }
    if(dp[ind][left]!=-1){
        return dp[ind][left];
    }
    
    int take=sum[ind]+f(sum,k,left-1,ind+k);
    int notake=f(sum,k,left,ind+1);
    dp[ind][left]=max(take,notake);
    return max(take,notake);
}
// mereko subarry start from i lena ya nhi ,iska decision agar ise subarry start from i max sum mil rha h toh lelo
void solve(vector<int> &sum, int k, int left, int ind, vector<int> &ans)
{
    int n = sum.size();
    if (left == 0)
    {
        return;
    }
    if (ind >= n)
    {
        return;
    }
    int start_i =sum[ind]+f(sum,k,left-1,ind+k);
    int not_start_i=f(sum,k,left,ind+1);
    if(start_i>=not_start_i){
        ans.push_back(ind);
        solve(sum,k,left-1,ind+k,ans);

    }
    else{
         solve(sum,k,left,ind+1,ans);
    }
}
vector<int> maxSumOfThreeSubarrays(vector<int> &nums, int k)
{
    int n = nums.size();
    // I need sum from start index i of length k
    vector<int> sum;
    // sum[i]-subarray sum starting from index  i with length k
    // {start index,sum}
    vector<int> prefix(n, 0);
    prefix[0] = nums[0];
    for (int i = 0; i < n; i++)
    {
        prefix[i] = nums[i] + prefix[i - 1];
        /* code */
    }
    sum.push_back(prefix[k - 1]);
    for (int i = 1; i <= n - k; i++)
    {
        int j = i + k - 1;
        sum.push_back(prefix[j] - prefix[i - 1]);
        /* code */
    }
    vector<int> ans;
    // this ans is storing indices
    memset(dp,-1,sizeof(dp));
    solve(sum,k,3,0,ans);
    return ans;

}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}