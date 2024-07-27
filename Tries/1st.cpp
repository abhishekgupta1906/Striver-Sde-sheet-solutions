#include<iostream>
#include<string>
#include<vector>
#include <bits/stdc++.h>
using namespace std;
string make_hash_front(string &str)
{
    int count=0;
    string s="";
    for (int i = 0; i <str.length(); i++)
    {
        if(str[i]!='#')
        {
            s+=str[i];
        }
        else
        {
            count++;
        }
        /* code */
    }
    cout<<s<<" ";
    for (int i = 0; i <count; i++)
    {
        s.insert(0,"#");
        /* code */
    }
    cout<<s<<" ";
    return s;
    

    
}
int main()
{
    
   ios_base::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
//    string str="Move#to#front#";
//    string s=make_hash_front(str);
 int a=4;
 cout<<a%-3<<" ";
   
   return 0;
}