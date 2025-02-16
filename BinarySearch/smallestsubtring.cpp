#include <iostream>
#include <bits/stdc++.h>
#define int long long
using namespace std;
// can i make longest length<=mid using atmost k opearations
bool check_One(string &s, int k)
{
    int n = s.length();
    string t = "";
    string m = "";
    char c = '1';
    for (int i = 0; i < n; i++)
    {
        m += c;
        if (c == '1')
        {
            c = '0';
        }
        else
        {
            c = '1';
        }
        t += c;
        /* code */
    }
    int c1 = 0;
    int c2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != t[i])
        {
            c1++;
        }
        if (s[i] != m[i])
        {
            c2++;
        }
        /* code */
    }
    return min(c1, c2) <= k;
}
bool check(string &s, int mid, int k)
{
    int n = s.length();
    int ops = 0;
    int i = 0;
    int j = 1;
    if(mid==1){
        return check_One(s,k);
    }
    int count = 1;
    while (j < n)
    {
        if (s[i] == s[j])
        {
            i++;
            count++;
        }
        else
        {
            if (count > mid)
            {
                ops += (count) / (mid + 1);
            }
            i = j;
            count = 1;
        }
        j++;
    }
    if (count > mid)
    {
        ops += (count) / (mid + 1);
    }
    return ops <= k;
}
// agar 1 length ,toh string 01010101...
// agar 1 ,ya 1010...
int minLength(string s, int numOps)
{
    int n = s.length();
    int low = 1;
    int high = n;
    int ans = 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (check(s, mid, numOps))
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s = "0110";
    cout << minLength(s,1);
    return 0;
}