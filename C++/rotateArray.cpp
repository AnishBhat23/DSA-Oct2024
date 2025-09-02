#include<bits/stdc++.h>
using namespace std;

/*
    Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

    A shift on s consists of moving the leftmost character of s to the rightmost position.

    For example, if s = "abcde", then it will be "bcdea" after one shift.
*/

bool rotateString_app1(string s, string goal) 
{
        int n = s.size();
        int stringSize = n;

        while(stringSize != 0)
        {
            char test = s[0];
            for(int i=0; i<n-1; i++)
            {
                s[i] = s[i+1];
            }
            s[n-1] = test;

            if(s == goal)
            {
                return true;
            }

            stringSize--;
        }
        return false;
}


bool rotateString_optimal(string s, string goal) 
{
    if (s.size() != goal.size()) return false;
    string doubled = s + s;
    return doubled.find(goal) != string::npos;
}


void rotateLeft(string &s, int k) 
{
    int n = s.size();
    k %= n;
    reverse(s.begin(), s.begin() + k);
    reverse(s.begin() + k, s.end());
    reverse(s.begin(), s.end());
}

bool rotateString_app2(string s, string goal) 
{
    int n = s.size();
    for(int i=1; i<=n; i++)
    {
        rotateLeft(s, 1);
        if(s == goal)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    string s;
    string goal;

    getline(cin,s);
    getline(cin,goal);
    
    bool ans = rotateString_optimal(s, goal);
    cout << ans << endl;
}