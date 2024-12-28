#include<bits/stdc++.h>
using namespace std;

void swapInt(int *a, int*b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}

/*
    You are given an array of ‘N’ integers. 
    You need to find the length of the longest 
    sequence which contains the consecutive elements.

    Brute force approach ->     
        Pick up each element from the array and find the 
        next consecutive elements of that element. 
        When not found break and check the length, if greater 
        than max length replace with the max length

        TC -> O(pow(2,n))
        SC -> O(1)

    Better Approach -> 
        Sort the array and run a for loop to find the 
        longest consecutive sequence.
        Iterate through the array one by one and check 
        if it can be part of the sequence. 
        lastSmaller- to store the last included of the 
        current sequence. 
        cnt - to store the length of the current sequence
        longest - to store the maximum length
        if arr[i]-1 == lastSmaller it means that arr[i] is in 
        sequence. 
        if arr[i] == lastsmaller, skip it.
        if arr[i] != lastsmaller means it is not part of 
        this sequence. so this will be start of a new sequence.

        TC -> O(NlogN) + O(N)
        SC -> O(1)

    Optimal approach -> 
        Add all elements in the array to a set 
        data structure. 
        Select an element ele and check if ele - 1 exists. 
        If not that is the first element in the sequence. 
        cnt - length of current sequence. 
        longest - maximum length
        check for all the elements after ele and increment
        cnt until an element is not found. 
        update the longest
*/

int longestConsecutiveSequence_better(int arr[], int n)
{
    sort(&arr[0],&arr[n-1]);
    int lastSmaller = INT_MIN;
    int cnt = 0;
    int longest = 1;

    for(int i = 0; i < n; i++)
    {
        if(arr[i]-1 == lastSmaller)
        {
            lastSmaller = arr[i];
            cnt++;
        }
        else if(arr[i] == lastSmaller)
        {
            //skip
        }
        else if(arr[i] != lastSmaller)
        {
            lastSmaller = arr[i];
            cnt = 1;
        }
        longest = max(longest,cnt);
    }

    return longest;
}

int longestConsecutiveSequence_optimal(int arr[], int n)
{
    if(n == 0)
    {
        return 0;
    }
    int longest = 1;
    unordered_set<int> st;
    for(int i=0; i<n; i++)
    {
        st.insert(arr[i]);
    }

    for(auto it: st)
    {
        //if 'it' is a starting number:
        if (st.find(it - 1) == st.end()) {
            //find consecutive numbers:
            int cnt = 1;
            int x = it;
            while (st.find(x + 1) != st.end()) {
                x = x + 1;
                cnt = cnt + 1;
            }
            longest = max(longest, cnt);
        }
    }
    return longest;
}


int main()
{
    int n1,n2,k;

    cin >> n1;
    int arr1[n1];
    for(int i=0; i<n1; i++)
    {
        cin >> arr1[i];
    }

    /*
    cin >> n2;
    int arr2[n2];
    for(int i=0; i<n2; i++)
    {
        cin >> arr2[i];
    }
    */
    /*
    for(auto it: ans)
    {
        cout << it << " ";
    }
    */
}