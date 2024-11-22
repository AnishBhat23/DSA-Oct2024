#include<bits/stdc++.h>
using namespace std;

/*
    Find the element which appears more than n/2 times

    Brute force method -> 
        Iterate through the entire array for element i
        and count the number of repitions of i. 
        If this number is greater than n/2, return it

        Time complexity -> O(pow(n,2))
    
    Better solution -> 
        Hashing - declare a hashmap where key is the 
        array value and value is its count. 
        Iterate through the hashmap to find a count 
        greater than n/2

        TC -> O(NlogN) + O(N)
        SC -> O(N)

    Optimal Approach -> 
        Apply Moore's Voting Algorithm (see code for logic)
        Verify if the element gotten is the
        majority element

        TC -> O(N)
        SC -> O(1)
*/


int majorityElementBetterApp(int arr[], int n)
{
    map<int,int> mpp;
    for(int i=0; i<n; i++)
    {
        mpp[arr[i]]++;
    }
    for(auto it : mpp)
    {
        if(it.second > (n/2))
        {
            return it.first;
        }
    }
    return -1;
}

int majorityElementOptimalApp(int arr[], int n)
{
    int cnt = 0, chkCnt = 0;
    int el = 0;
    for(int i=0; i<n; i++)
    {
        if(cnt == 0)
        {
            cnt = 1;
            el = arr[i];
        }
        else if(arr[i] == el)
        {
            cnt++;
        }
        else
        {
            cnt--;
        }  
    }

    for(int i=0; i<n; i++)
    {
        if(arr[i] == el)
        {
            chkCnt++;
        }
    }

    if(chkCnt > (n/2))
    {
        return el;
    }
    else
    {
        return -1;
    }
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
    
    int ans = majorityElementBetterApp(arr1,n1);
    cout << "The majority element is : " << ans << endl;

    /*
    cin >> n2;
    int arr2[n2];
    for(int i=0; i<n2; i++)
    {
        cin >> arr2[i];
    }
    */

    /*
    for(auto it: arr1)
    {
        cout << it << " ";
    }
    */
}