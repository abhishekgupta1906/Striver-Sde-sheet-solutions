#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
int longestValidParentheses(string s)
{
    

    stack<int> st;
    // (,push into the stack
    // ),if stack empty ,isko iska joridar 1 mark krdo
    vector<int> mark(s.length(), 0);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            st.push(i);
        }
        else if (!st.empty() && s[i] == ')')
        {
            int ind = st.top();
            st.pop();
            mark[ind] = 1;
            mark[i] = 1;
        }
        /* code */
    }
       int maxi = 0;
    int count1 = 0;
    for (int i = 0; i <mark.size(); i++)
    {
        if (mark[i] == 0)
        {
            maxi = max(maxi, count1);
            count1 = 0;
        }
        else
        {
            count1++;
        }
        /* code */
    }
    maxi = max(maxi, count1);
    return maxi;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s = ")()())";
    int ans = longestValidParentheses(s);
    cout << ans;
    return 0;
}