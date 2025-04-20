#include<bits/stdc++.h>
using namespace std;

/*
    You are given a strictly increasing array ‘vec’ and a positive integer 'k'. 
    Find the 'kth' positive integer missing from 'vec'.

    Brute Force -> Increment the number k each time to account for a number
                   existing in the array until arr[i] >= k
    TC -> O(N)
    SC -> O(1)

    Optimal -> We narrow down the search space to the neighbouring indices of the target 
               number by checking the count of missing numbers at each index of the array. 
               then we stop when low and high are at opposite polarity.  
               missing = arr[high] - (high+1)
               more_to_be_added =  k - missing
               ans = arr[high] + more
                   = arr[high] + k - missing
                   = arr[high] + k - arr[high] + high + 1
                   = k + high + 1 or k + low

    TC -> O(log2N)
    SC -> O(1)
*/

int findMissingNum_brute(vector<int> &arr, int k)
{
    int n = arr.size();

    for(int i = 0; i<n; i++)
    {
        if(arr[i] <= k)
        {
            k++;
        }
        else
        {
            break;
        }
    }
    return k;
}


int findMissingNumber_optimal(vector<int> &arr, int k)
{
    int n = arr.size();

    int low = 0, high = n-1;

    while(low <= high)
    {
        int mid = (low+high)/2;
        int missing = arr[mid] - (mid+1);
        if(missing < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high+1+k;
}

int main()
{
    int N,k;

    cin >> N;
    vector<int> arr1;
    for(int i=0;i<N;++i) 
    { 
        int value; 
		cin >> value;  
		arr1.push_back(value); 
	}

    cin >> k;  
    int ans;

    ans = findMissingNumber_optimal(arr1, k);

    cout << "Missing number is : " << ans << endl;
}