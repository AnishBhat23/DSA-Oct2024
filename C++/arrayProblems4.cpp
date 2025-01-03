#include<bits/stdc++.h>
using namespace std;

void swapInt(int *a, int*b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Longest Subarray with sum K (positives/negatives)

/*
    Brute force approach-> 
        Generate all subarrays and 
        find the subarrays whose sum
        is k. 

    Better approach -> 
        If there exists a subarray with sum k as
        ele x as last element, use hashing to determine where
        x-k lies and compare indices to get the maxLen subarray
        Time complexity -> O(N*log2N)
        Space complexity -> O(N)

        This is the optimal solution if the array 
        has both positives and negatives

    Optimal Solution->  
        Use two pointers and increment the right pointer
        until we find K. Once we find k, increment the left pointer
        until sum < k and then start incrementing the right pointer
        Sliding window type iteration. 
        Time complexity -> O(2N)
        Space complexity -> O(1)
*/

int longestSubarraySumKBrute1(int arr[], int n, int s)
{
    int sum = 0, longLen = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=i; j<n; j++)
        {
            sum = 0;
            for(int k = i; k<=j; k++)
            {
                sum += arr[k];
            }
            if(sum == s)
            {
                longLen = max(longLen, j-i+1);
            }
        }
    }
    return longLen;
}

int longestSubarraySumKBrute2(int arr[], int n, int s)
{
    int sum = 0, longLen = 0;
    for(int i=0; i<n; i++)
    {
        sum = 0;
        for(int j=i; j<n; j++)
        {
            sum += arr[j];
            if(sum == s)
            {
                longLen = max(longLen, j-i+1);
            }
        }
    }
    return longLen;
}

int longestSubArraySumKHashing(int a[], int n, long long k)
{
    map<long long, int> prefixSumMap;
    long long prefixSum = 0;
    int maxLen = 0;

    for(int i=0; i<n; i++)
    {
        prefixSum += a[i];

        if (prefixSum == k) 
        {
            maxLen = max(maxLen, i+1);
        }

        long long rem = prefixSum - k;

        if (prefixSumMap.find(rem) != prefixSumMap.end()) 
        {
            int len = i - prefixSumMap[rem];
            maxLen = max(maxLen, len);
        }

        if (prefixSumMap.find(prefixSum) == prefixSumMap.end()) 
        {
            prefixSumMap[prefixSum] = i;
        }
    }

    return maxLen;
}

int longestSubarraySumKOptimal(int a[], int n, long long k)
{
    long long sum = a[0]; 
    int longLen = 0;
    int left = 0, right = 0;    
    while(right < n)
    {
        while(left <= right && sum > k)
        {
            sum -= a[left];
            left++;
        }
        if(sum == k)
        {
            longLen = max(longLen, right-left+1);
        }
        right++;
        if(right < n)
        {
            sum += a[right];
        }
    }
    return longLen;
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

    long long sum = 0;
    cin >> sum;
    int ans = longestSubArraySumKHashing(arr1, n1, sum);
    cout << "Longest subarray of Sum " << sum << " : " << ans << endl;

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