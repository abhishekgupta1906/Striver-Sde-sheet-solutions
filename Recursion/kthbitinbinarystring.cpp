#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
string get_string(int n)
{
    if (n == 1)
    {
        string ans = "0";
        return ans;
    }
    string smallerString = get_string(n - 1);
    string output = "";
    output += smallerString;
    output += "1";
    string temp = "";

    for (int i = 0; i < smallerString.length(); i++)
    {
        if (smallerString[i] == '0')
        {
            temp += "1";
        }
        else
        {
            temp += "0";
        }
        /* code */
    }
    reverse(temp.begin(), temp.end());
    output += temp;

    return output;
}
char findKthBit(int n, int k)
{
    string output = get_string(n);
    if (k <= output.length())
    {
        char c = output[k - 1];
        return c;
    }
    char c='\0';
    return c;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    char ans = findKthBit(3, 5);
    cout << ans;
    return 0;
}