#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int minimizeXor(int num1, int num2)
{
    int cnt = 0;
    // cnt set bits in num2
    for (int bit = 0; bit <= 31; bit++)
    {
        if ((num2 & (1 << bit)))
        {
            cnt++;
        }
    }
    vector<int> ans(32, 0);
    for (int i = 31; i >= 0; i--)
    {
        if (num1 & (1 << i))
        {
            ans[i] = 1;
            cnt--;
        }
        /* code */
    }
    if (cnt != 0)
    {
        for (int i = 0; i <= 31; i++)
        {
            if (cnt == 0)
            {
                break;
            }
            if (ans[i] == 0)
            {
                ans[i] = 1;
                cnt--;
            }

            /* code */
        }
    }
    int val=0;
    for (int i = 0; i <=31; i++)
    {
        if(ans[i]==1){
            val+=(1<<i);
        }
        /* code */
    }
    return val;
    
}
int main()
{
    return 0;
}