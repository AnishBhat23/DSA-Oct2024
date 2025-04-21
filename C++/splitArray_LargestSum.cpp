#include<bits/stdc++.h>
using namespace std;

/*
    Given an integer array ‘A’ of size ‘N’ and an integer ‘K'. 
    Split the array ‘A’ into ‘K’ non-empty subarrays such that 
    the largest sum of any subarray is minimized. 
    Your task is to return the minimized largest sum of the split.
    A subarray is a contiguous part of the array.

    TC -> O(N * log(sum(arr)-max(arr)+1))
    SC -> O(1)
*/

int minimizeSum(vector<int> &arr, int toMin)
{
    int n = arr.size();

    int subArrayCount = 1;
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        if(sum + arr[i] <= toMin)
        {
            sum += arr[i];
        }
        else
        {
            subArrayCount++;
            sum = arr[i];
        }
    }
    return subArrayCount;
}

int splitArray(vector<int> &arr, int m)
{
    int n = arr.size();
    
    if(m > n)
    {
        return -1;
    }

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while(low <= high)
    {
        int mid = (low+high)/2;
        int minimizedSum = minimizeSum(arr, mid);

        if(minimizedSum <= m)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    int N,m;

    cin >> N;
    vector<int> arr1;
    for(int i=0;i<N;++i) 
    { 
        int value; 
		cin >> value;  
		arr1.push_back(value); 
	}

    cin >> m;  
    int ans;

    ans = splitArray(arr1, m);

    cout << "Minimized Largest Sum is : " << ans << endl;
}