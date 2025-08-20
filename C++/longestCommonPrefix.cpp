#include<bits/stdc++.h>
using namespace std;

/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".
*/

string longestCommonPrefix(vector<string>& strs) {
    if (strs.empty()) return "";
    if (strs.size() == 1) return strs[0];

    // Find the smallest string length
    int minLen = strs[0].size();
    for (const auto& s : strs) {
        minLen = min(minLen, (int)s.size());
    }

    int prefixLen = 0;
    for (int i = 0; i < minLen; i++) {
        char currentChar = strs[0][i];
        for (int j = 1; j < strs.size(); j++) {
            if (strs[j][i] != currentChar) {
                return strs[0].substr(0, prefixLen);
            }
        }
        prefixLen++;
    }

    return strs[0].substr(0, prefixLen); // Whole prefix up to minLen matched
}

int main()
{
    vector<string> arr;
    int numItems;
    cin >> numItems;
    for(int i = 0; i< numItems; i++)
    {
        string test;
        cin >> test;
        arr.push_back(test);
    }
    
    string ans = longestCommonPrefix(arr);
    cout << "The answer string is : " << ans << endl;
}