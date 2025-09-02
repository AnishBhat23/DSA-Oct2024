#include<bits/stdc++.h>
using namespace std;

/*
    Given a valid parentheses string s, return the nesting depth of s. 
    The nesting depth is the maximum number of nested parentheses.
*/

int maxDepth(string s) {
    int n = s.size();
    int stackCount = 0;
    int maxStackCount = 0;
    for(int i=0; i<n; i++)
    {
        if(s[i] == '(')
        {
            stackCount++;
        }
        else if(s[i] == ')')
        {
            stackCount--;
        }
        maxStackCount = max(maxStackCount, stackCount);
    }
    return maxStackCount;
}

int main()
{
    string s;

    getline(cin,s);
    
    int ans = maxDepth(s);
    cout << ans << endl;
}