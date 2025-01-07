#include<bits/stdc++.h>
using namespace std;

/*
    Given an array of integers and an integer k, 
    return the total number of subarrays whose sum equals k.

    Brute Force Solution -> 
        Loop through all the sub arrays and count the ones which 
        sum up to k
        TC -> O(N^3)
        SC -> O(1)

    Better Solution ->  
        Reduce one loop by updating the sum while
        traversing through the array for subarrays. 
        TC -> O(N^2)
        SC -> O(1)

    Optimal Solution -> 
        Use maps to store the prefix sums while iterating through
        the array. If the map has prefixsum-k, increment the ans count
        by the number of instances of prefixsum-k 
        TC -> O(NxlogN)
        SC -> O(N)
*/

int countSubArraySum(vector<int> arr, int k)
{
    map<int, int> prefixSumMap;
    int prefixSum = 0;
    int count = 0;

    prefixSumMap[prefixSum] += 1;

    for(int i=0; i<arr.size(); i++)
    {
        prefixSum += arr[i];

        if(prefixSumMap.find(prefixSum-k) != prefixSumMap.end())
        {
            count += prefixSumMap[prefixSum-k];
        }

        if(prefixSumMap.find(prefixSum) == prefixSumMap.end())
        {
            prefixSumMap[prefixSum] = 1;
        }

        else
        {
            prefixSumMap[prefixSum]++;
        }
    }
    return count;
}

int main()
{
    int len,k;

    cin >> k;
    cin >> len;
    vector<int> arr1;
    int temp = 0;
    for(int i=0;i<len;++i) 
    { 
        int value; 
		cin >> value;  
		arr1.push_back(value); 
	} 

    int ans = countSubArraySum(arr1,k);
       
    /*
    cin >> n2;
    int arr2[n2];
    for(int i=0; i<n2; i++)
    {
        cin >> arr2[i];
    }
    */
    /*
    for (auto it : ansVect) 
    {
        for (auto ele : it) 
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    */
}