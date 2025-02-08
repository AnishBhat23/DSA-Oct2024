#include<bits/stdc++.h>
using namespace std;

/*
    Given an array containing both positive and negative integers, 
    we have to find the length of the longest subarray with the 
    sum of all elements equal to zero.

    Brute Force -> Generate all the subarrays with sum zero in an
                   iterative fashion. 
    
    TC -> O(pow(n,2))
    SC -> O(1)

    Optimal Approach -> Use the prefix sum method to find
                        a subarray(i, x) and subarray(i, j)
                        such that both subarrays add up to same sum X and i<x<j;
                        This indicates that subarray(x+1, j) is zero and we can store
                        this length in a map.
    TC -> O(N)
    SC -> O(N) because we are using a hashmap
*/

int getLongestZeroSumSubarrayLength(vector<int> &arr)
{
	int n = arr.size();
	unordered_map <int,int> mpp;
	int maxi = 0;
	int sum = 0;

	for(int i=0; i<n; i++)
	{
		sum += arr[i];

		if(sum == 0)
		{
			maxi = i+1;
		}
		else
		{
			if(mpp.find(sum) != mpp.end())
			{
				maxi = max(maxi, i - mpp[sum]);
			}
			else
			{
				mpp[sum] = i;
			}
		}
	}
	return maxi;
}



int main()
{
    int len,k;

    cin >> len;
    vector<int> arr1;
    int temp = 0;
    for(int i=0;i<len;++i) 
    { 
        int value; 
		cin >> value;  
		arr1.push_back(value); 
	} 

    int ans = getLongestZeroSumSubarrayLength(arr1);
    cout << ans << endl;
       
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