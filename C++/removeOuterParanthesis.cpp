#include<bits/stdc++.h>
using namespace std;


string removeOuterParentheses(string s) {
    string ans;
    int depth = 0;

    for (char c : s) 
    {
        if (c == '(') 
        {
            if (depth > 0) 
                ans += c; // only add if not the outermost '('
            depth++;
        } 
        else // c == ')'
        {       
            depth--;
            if (depth > 0) 
                ans += c; // only add if not the outermost ')'
        }
    }

    return ans;
}

int main()
{
    string arr;
    
    cin >> arr;
    
    string ans = removeOuterParentheses(arr);
    cout << "The answer string is : " << ans << endl;
}