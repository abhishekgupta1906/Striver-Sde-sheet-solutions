#include <iostream>
#include <bits/stdc++.h>
using namespace std;
bool check(int start, vector<int> &derived)
{
    int n = derived.size();
    vector<int> original(n);
    original[0] = start;
    for (int i = 1; i < n; i++)
    {
        original[i] = derived[i - 1] ^ original[i - 1];
    }
    int val = original[n - 1] ^ original[0];
    if (derived[n - 1] == val)
    {
        return true;
    }
    return false;
}
bool doesValidArrayExist(vector<int> &derived)
{
    bool ans1 = check(0, derived);
    bool ans2 = check(1, derived);
    return ans1 | ans2;
}
int main()
{
    int n;
    cin>>n;
    vector<int>derived(n);
    for (int i = 0; i <n; i++)
    {
        cin>>derived[i];
        /* code */
    }
    cout<<doesValidArrayExist(derived);
    
    return 0;
}