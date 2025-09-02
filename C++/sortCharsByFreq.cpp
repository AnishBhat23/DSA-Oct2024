#include<bits/stdc++.h>
using namespace std;

/*
    Given a string s, sort it in decreasing order based on the frequency of the 
    characters. The frequency of a character is the number of times it appears 
    in the string.

    Return the sorted string. If there are multiple answers, return any of them.
*/

string frequencySort(string s) 
{
    int n = s.size();
    unordered_map<char, int> freq;
    
    // 1. Count frequencies
    for (char c : s) {
        freq[c]++;
    }
    
    // 2. Buckets: index = frequency, value = list of chars
    vector<vector<char>> buckets(n + 1);
    for (auto &p : freq) {
        buckets[p.second].push_back(p.first);
    }
    
    // 3. Build answer from high freq to low
    string ans;
    for (int i = n; i >= 1; i--) {
        for (char c : buckets[i]) {
            ans.append(i, c); // append 'i' copies of c
        }
    }
    
    return ans;
}

int main()
{
    string s;

    getline(cin,s);
    
    string ans = frequencySort(s);
    cout << ans << endl;
}