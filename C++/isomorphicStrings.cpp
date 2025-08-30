#include<bits/stdc++.h>
using namespace std;

/*
    Given two strings s and t, determine if they are isomorphic.

    Two strings s and t are isomorphic if the characters in s can be 
    replaced to get t.

    All occurrences of a character must be replaced with another character 
    while preserving the order of characters. No two characters may map to 
    the same character, but a character may map to itself.
*/

bool isIsomorphic(string s, string t) 
{
    if (s.size() != t.size()) return false;

    // ASCII character set → 256 possible chars
    char mapST[256] = {0}; // s → t mapping
    char mapTS[256] = {0}; // t → s mapping

    for (int i = 0; i < s.size(); i++) {
        char c1 = s[i], c2 = t[i];

        // If not yet mapped, establish the mapping
        if (mapST[c1] == 0 && mapTS[c2] == 0) {
            mapST[c1] = c2;
            mapTS[c2] = c1;
        }
        // If already mapped, check consistency
        else if (mapST[c1] != c2) {
            return false;
        }
    }

    return true;
}


int main()
{
    string arr1;
    string arr2;

    getline(cin,arr1);
    getline(cin,arr2);
    
    bool ans = isIsomorphic(arr1, arr2);
    cout << ans << endl;
}