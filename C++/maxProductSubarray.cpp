#include<bits/stdc++.h>
using namespace std;

/*
    Given an array that contains both negative and positive integers, 
    find the maximum product subarray. 

    Brute Force -> Find all possible subarrays of the given array. 
                   Find the product of each subarray. 
                   Return the maximum of all them.
    TC -> O(pow(n,3))
    SC -> O(1)

    Better Approach -> We can optimize the brute force by making 
                       3 nested iterations to 2 nested iterations.
                       Following are the steps for the approach:
                        -> Run a loop to find the start of the subarrays.
                        -> Run another nested loop
                        -> Multiply each element and store the maximum value of all the subarray.
    TC -> O(pow(n,2))
    SC -> O(1)

    Optimal Approcah -> By observation we see that if an array contains all 
                        positive numbers, the whole array is the maxProductSubarray. 
                        If the array has even number of negative numbers, again the 
                        whole array is a subarray. We just need to account for when
                        there are odd number of negative numbers and when zeroes are 
                        present. 
    TC -> O(N)
    SC -> O(1)
*/


int maxProductSubarray_brute(vector<int> arr)
{
    int n = arr.size();
    int max_prod = INT_MIN;
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int prod = 1;
            for(int k=i; k<j; k++)
            {
                prod *= arr[k];
            }
            max_prod = max(max_prod,prod);
        }
    }

    return max_prod;
}

int maxProductSubarray_better(vector<int> arr)
{
    int n = arr.size();
    int max_prod = arr[0];
    for(int i=0; i<n-1; i++)
    {
        int prod = arr[i];
        for(int j=i+1; j<n; j++)
        {
            max_prod = max(max_prod,prod);
            prod *= arr[j];
        }
        max_prod = max(max_prod,prod);
    }

    return max_prod;
}

int maxProductSubArray_optimal(vector<int> arr)
{
    int n = arr.size(); //size of array.

    int pre = 1, suff = 1;
    int ans = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (pre == 0) pre = 1;
        if (suff == 0) suff = 1;
        pre *= arr[i];
        suff *= arr[n - i - 1];
        ans = max(ans, max(pre, suff));
    }
    return ans;
}

int main()
{
    int len1,len2,k;

    cin >> len1;
    vector<int> arr1;
    for(int i=0;i<len1;++i) 
    { 
        int value; 
		cin >> value;  
		arr1.push_back(value); 
	}

    int ans;
    ans = maxProductSubarray_brute(arr1);

    cout << ans << " ";      
    
}