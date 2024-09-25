#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
void f(int ind,vector<int>&perm,vector<bool>&taken,int n,int&count)
{
    // base case
    if(ind==n+1)
    {
        count++;
        return;
    }
    for (int choice =1; choice <n+1; choice++)
    {
        perm[ind]=choice;
        if((perm[ind] % ind==0 || ind % perm[ind]==0) && taken[choice]==false)
        {
            taken[choice] = true;
            f(ind+1,perm,taken,n,count);
            taken[choice]=false;
        }
        perm[ind]=0;
        /* code */
    }
    

}
int countArrangement(int n)
{
    vector<int>perm(n+1,0);
    vector<bool> taken(n+1,false);
    int count = 0;
    f(1,perm,taken,n,count);
    return count;

}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int ans=countArrangement(4);
    cout<<ans;
    return 0;
}