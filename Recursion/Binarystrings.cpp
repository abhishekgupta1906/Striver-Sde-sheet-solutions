#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
vector<string> validStrings(int n)
{
    if (n == 1)
    {
        vector<string> ans;
        ans.push_back("0");
        ans.push_back("1");
        return ans;
    }
    vector<string> smallerOutput = validStrings(n - 1);
    vector<string>output;
    for (int i = 0; i < smallerOutput.size(); i++)
    {
        string str = smallerOutput[i];
        string temp =smallerOutput[i];
        if (str[str.length() - 1] == '1')
        {
            str += "0";
            temp += "1";
            output.push_back(str);
            output.push_back(temp);
        }
        else
        {
            str += "1";
            output.push_back(str);
        }
        /* code */
    }
    return output;
}
int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    vector<string>ans=validStrings(4);
    for(auto i:ans)
    {
        cout << i << " "; 
    }

    return 0;
}