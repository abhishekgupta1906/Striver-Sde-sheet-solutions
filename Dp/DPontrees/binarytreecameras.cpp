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
    unordered_map<pair<TreeNode *, int>, int> dp;
    void dfs(TreeNode *root)
    {
        if (root == NULL)
        {
            return ;
        }
        dfs(root->left);
        dfs(root->right);
        
    }
    int minCameraCover(TreeNode *root)
    {
    }
};
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}