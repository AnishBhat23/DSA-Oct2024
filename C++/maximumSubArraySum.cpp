#include<bits/stdc++.h>
using namespace std;


/*
    Get the maximum sum from any subarray in the given array

    Brute force approach -> 
        Generate all subarrays of a given array and compare the sums
        to get the maximum sum

        TC -> O(pow(n,3))
        SC -> O(1)
    
    Better approach -> 
        Get the sum of all the subarays from i
        without running a N iterations. 

        TC -> O(pow(n,2))
        SC -> O(1)

        https://takeuforward.org/data-structure/kadanes-algorithm-maximum-subarray-sum-in-an-array/
    
    Optimal approach -> 
        Kadane's Algorithms
        Store the max sum (first element) and start iterating through
        the array. Add each ith element to the sum. 
        If at any point the sum reaches < 0, store the max sum and start from
        the next element again

        TC -> O(n)
        SC -> O(1)
*/

long long maxSubArraySumKadane(int arr[], int n)
{
    long long sum = 0, maxSum = LONG_MIN;
    int subArrStart = 0, subArrEnd = 0;
    for(int i = 0; i<n; i++)
    {
        if(sum == 0)
        {
            subArrStart = i;
        }
        sum += arr[i]; 

        if(sum > maxSum)
        {
            maxSum = sum;
            subArrEnd = i;
        }

        if(sum < 0)
        {
            sum = 0;
        }
    }
    if(maxSum < 0)
    {
        maxSum = 0;
    }
    return maxSum;
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

    long long sum = maxSubArraySumKadane(arr1, n1);
    cout << "Maximum subarray sum : " << sum << endl; 

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