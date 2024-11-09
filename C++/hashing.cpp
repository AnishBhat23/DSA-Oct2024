#include<bits/stdc++.h>
using namespace std;

#define MAX_HASH_SIZE 13
#define MAX_CHARACTER_HASH_SIZE 256
#define MAX_FREQ 999

/*
    An array of max size 1e6 can be declared inside main function.
    An array of max size 1e7 can be declared globally.
*/

// number hashing using array
/*
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    // precompute
    int hash[MAX_HASH_SIZE] = {0};
    for(int j=0; j<n; j++)
    {
        hash[arr[j]]++;
    }

    int inpCnt,inp;
    cin >> inpCnt;
    while(inpCnt--)
    {
        cin >> inp;

        // fetch
        cout << inp << " appears " << hash[inp] << " times." << endl;
    }
}
*/

// character hashing using array
// arrays are always preferred for character hashing
/*
int main()
{
    string s;
    cin >> s;

    // precompute
    int hash[MAX_CHARACTER_HASH_SIZE] = {0};
    for(int i=0;i<s.size();i++)
    {
        hash[s[i]]++;
    }

    int inpCnt;
    char ch;
    cin >> inpCnt;
    while(inpCnt--)
    {
        cin >> ch;

        // fetch

        cout << ch << " appears " << hash[ch] << " times." << endl;
    }

}
*/

// number hashing using maps, efficient for numbers greater than 1e7
/*
    Storing and fetching takes O(log(n)) in maps in call cases

    In unordered map storing and fetching takes O(1)*(number of elements) 
    for average and best cases, and O(n)*(number of elements) for worst case

*/
/*
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    // precompute using maps
    unordered_map<int, int> hashmap;
    for(int i=0; i<n; i++)
    {
        hashmap[arr[i]]++;
    }

    // iterate in the map
    for(auto it : hashmap)
    {
        cout << it.first << "->" << it.second << endl;
    }

    int inpCnt,inp;
    cin >> inpCnt;
    while(inpCnt--)
    {
        cin >> inp;

        // fetch
        cout << inp << " appears " << hashmap[inp] << " times." << endl;
    }
}
*/

// finding the highest/lowest frequency element in an array
int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    // precompute using maps
    map<int, int> hashmap;
    for(int i=0; i<n; i++)
    {
        hashmap[arr[i]]++;
    }

    // iterate in the map
    int highFreq = 0 , lowFreq = MAX_FREQ;
    int highFreqEle = 0, lowFreqEle = 0;
    for(auto it : hashmap)
    {
        cout << it.first << "->" << it.second << endl;
        if(it.second < lowFreq)
        {
            lowFreqEle = it.first;
            lowFreq = it.second;
        }
        if(it.second > highFreq)
        {
            highFreqEle = it.first;
            highFreq = it.second;
        }
    }

    cout << "HighFreq : " << highFreqEle << " and LowFreq : " << lowFreqEle << endl;
}

