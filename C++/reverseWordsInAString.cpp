#include<bits/stdc++.h>
using namespace std;

/*
    Given an input string s, reverse the order of the words.
    A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.
    Return a string of the words in reverse order concatenated by a single space.
    Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.
*/


string reverseWords(string s) {
    int n = s.length();

    int left = 0;
    int right = n-1;

    string temp = "";
    string ans = "";

    char ch = s[left];
    
    while(left <= right)
    {
        ch = s[left];
        if(ch != ' ')
        {
            temp+=ch;
        }
        else if(ch == ' ' && temp != "") 
        {
            if(ans != "")
            {
                ans = temp + ' ' + ans;
            }
            else
            {
                ans = temp;
            }
            temp = "";
        }
        left++;
    }

    if(temp != "")
    {
        if(ans != "")
        {
            ans = temp + " " + ans;
        }
        else
        {
            ans = temp;
        } 
    }
    return ans;
}



int main()
{
    string arr;
    
    getline(cin,arr);
    
    string ans = reverseWords(arr);
    cout << "The answer string is : " << ans << endl;
}