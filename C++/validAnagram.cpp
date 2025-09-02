#include<bits/stdc++.h>
using namespace std;

/*
    Given two strings s and t, return true if t is an anagram of s, and false otherwise.
*/

bool isAnagram(string s, string t) {
    if (s.size() != t.size())
        return false;

    int count[128] = {0};  // frequency array for ASCII chars

    for (int i = 0; i < s.size(); i++) {
        count[s[i]]++;
        count[t[i]]--;
    }

    for (int i = 0; i < 128; i++) {
        if (count[i] != 0)
            return false;
    }
    return true;
}

int main()
{
    string s;
    string t;

    getline(cin,s);
    getline(cin,t);
    
    bool ans = isAnagram(s, t);
    cout << ans << endl;
}