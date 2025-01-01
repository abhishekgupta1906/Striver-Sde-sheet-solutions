#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    map<TreeNode *, int> dp;
    long long maxi = 0;
    int totalsum = 0;
    const int m = 1e9 + 7;

    

    long long subtreeSum(TreeNode *root) {
        if (root == NULL) return 0;
        if (dp.find(root) != dp.end()) return dp[root];
        return dp[root] = root->val + subtreeSum(root->left) + subtreeSum(root->right);
    }

    
    void maxproduct(TreeNode *root) {
        if (root == NULL) return;

        if (root->left != NULL) {
            long long s1 = totalsum - dp[root->left];
            long long s2 = dp[root->left];
            maxi = max(maxi,s1*s2);
            maxproduct(root->left);
        }
        if (root->right != NULL) {
            long long s1 = totalsum - dp[root->right];
            long long s2 = dp[root->right];
            maxi = max(maxi,s1*s2);
            maxproduct(root->right);
        }
    }

    int maxProduct(TreeNode *root) {
        totalsum = subtreeSum(root);
        maxproduct(root);           
       maxi=maxi%m;
       return maxi;
    }
};
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}