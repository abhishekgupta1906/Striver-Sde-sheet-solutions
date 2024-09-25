#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
void f(int ind, int n, string s, string &str, vector<string> &output)
{
    if (ind == n)
    {

        output.push_back(str);

        return;
    }
    char ch = s[ind];
    if (!isdigit(ch))
    {
        // for (int i = 0; i <= 1; i++)
        // {
        //     if (i == 0)
        //     {
        //         str.push_back(ch);
        //         f(ind + 1, n, s, str,output);
        //         str.pop_back();
        //     }
        //     else
        //     {
        //         if(islower(ch))
        //         {
        //             str.push_back(toupper(ch));
        //         }
        //         else{
        //             str.push_back(tolower(ch));
        //         }
        //         f(ind + 1, n, s, str,output);
        //         str.pop_back();
        //     }
        //     /* code */
        // } easy way
        if (islower(ch))
        {
            str.push_back(toupper(ch));
        }
        else
        {
            str.push_back(tolower(ch));
        }
        f(ind + 1, n, s, str, output);
        str.pop_back();
    }

    str.push_back(ch);
    f(ind + 1, n, s, str, output);
    str.pop_back();
}
vector<string> letterCasePermutation(string s)
{
    int n = s.length();
    vector<string> output;
    string str;
    f(0, n, s, str, output);
    return output;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s = "3z4";
    vector<string> ans = letterCasePermutation(s);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    return 0;
}