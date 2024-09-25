#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
int f(TreeNode *root,int&ans)
{
    if(root==NULL)return 0;
    int ans1=f(root->left);
    int ans2=f(root->right);
    // jodne wla
    if(root->val ==root->left->val)
    {
        ans1+=1;
    }
    if(root->val ==root->right->val)
    {
        ans2+=1;
    }
    ans=max(ans,ans1+ans2);
    // combining path
    return max(ans1,ans2);

}
int longestUnivaluePath(TreeNode *root)
{
    int ans=INT_MIN;
    return f(root,ans);

}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}