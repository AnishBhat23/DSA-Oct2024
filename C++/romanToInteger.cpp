#include<bits/stdc++.h>
using namespace std;

/*
    Given a roman numeral, convert it to an integer.
*/

int romanToInt(string s) 
{
    int n = s.size();
    int ans = 0;
    int idx = n-1;
    map<char,int> romanMap = {{'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};
    while(idx > 0)
    {
        if(romanMap[s[idx]] > romanMap[s[idx-1]])
        {
            ans += (romanMap[s[idx]]-romanMap[s[idx-1]]);
            idx--;
        }
        else
        {
            ans += romanMap[s[idx]];
        }
        idx--;
    }

    if(idx == 0)
    {
        ans += romanMap[s[0]];
    }
    
    return ans;
}

int main()
{
    string s;

    getline(cin,s);
    
    int ans = romanToInt(s);
    cout << ans << endl;
}